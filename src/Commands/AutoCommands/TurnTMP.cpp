#include "TurnTMP.h"

TurnTMP::TurnTMP(float degrees, float velocity) {
	Requires(Drivetrain::GetInstance());
	m_deg_input = degrees;
	m_cruiseVelocity = velocity;

	if(degrees<0) {
			m_isLeft=true;
			m_deg_input = -m_deg_input;
		}
}

// Called just before this Command runs the first time
void TurnTMP::Initialize() {
	//reset isFinished
	m_isFinished=0;
	float accel_dist,hold_time,hold_segments=0;
	bool isTriangular=0;

	//check that the Drivetrain is in closed loop
	if(!Drivetrain::GetInstance()->isClosedLoop())
		Drivetrain::GetInstance()->configClosedLoop();

	//check where we pointing
	m_initangle = Drivetrain::GetInstance()->updateGyroYaw();

	//calculate the final destination angle
	m_finalangle = m_initangle+m_deg_input;

	//convert to radians, then inches
	m_rad_distance = ((M_PI/180) * m_deg_input)*(DRIVETRAIN_BASE_DIAMETER/2);

	//ensure queue is empty
	while(!m_output.empty())
		m_output.pop();
	while(!m_dist.empty())
		m_dist.pop();

	//generate profile
	//to begin, check if a triangle or trapezoid profile is needed.
	float accel_time = sqrt(m_rad_distance/m_maxAccelRate);
	float max_vel = m_maxAccelRate*accel_time;

	if(max_vel>m_cruiseVelocity) {
	    max_vel = m_cruiseVelocity;
	    cout <<"trapezoid" << endl;
	    accel_time = m_cruiseVelocity/m_maxAccelRate;
	    accel_dist = 0.5*m_maxAccelRate*pow(accel_time,2);

	    hold_time = (m_rad_distance-accel_dist-accel_dist)/m_cruiseVelocity;
	    //hold_dist = m_travelDistance - accel_dist - accel_dist;
	    hold_segments = ceil(hold_time/m_dt);
	   }
	   else {
	    cout <<"triangle" << endl;
	    isTriangular=true;
	    accel_dist = 0.5*m_maxAccelRate*pow(accel_time,2);
	   }

	  	  //calculate the segments needed
		float end_time = accel_time + accel_time + hold_time;
		int accel_segments = ceil(accel_time/m_dt);
		int decel_segments = accel_segments;

		//generate acceleration curve
		for(int i = 0;i < accel_segments;i++) {
			double t = m_dt*i;
		    float v = (m_maxAccelRate*t);
		    float d = (0.5*m_maxAccelRate*t*t);

			if(m_isLeft) {
	        v = -v;
	        d = -d;
	        }

		    m_output.push(v);
		    m_dist.push(d);

			//if needed, generate hold
			if(!isTriangular) {
				for(int i = 0;i <= hold_segments;i++) {
					double t = m_dt*i;
					float v = (m_cruiseVelocity);
					float d = (accel_dist+m_cruiseVelocity*t);

					if(m_isLeft) {
						v = -v;
						d = -d;
					}

					m_output.push(v);
					m_dist.push(d);
					//LOG
					//log->AddtoBuffer("Vel",v);
					//log->AddtoBuffer("Dist", d);
				}
			}

			//generate deceleration curve
			for(int i=1 ;i < decel_segments;i++) {
				float t = m_dt*i;
				float curr_t = t + accel_time + hold_time;
				float v = max_vel-(m_maxAccelRate*t);
				float d = m_rad_distance - 0.5*m_maxAccelRate*pow(curr_t-end_time,2);								//very negative

				if(m_isLeft) {
					v=-v;
					d = -d;
				}

			    m_output.push(v);
			    m_dist.push(d);
			}
			//last point
			m_output.push(0);

			if(m_isLeft)
				m_dist.push(-m_rad_distance);
			else
				m_dist.push(m_rad_distance);

		cout << "info: generated a profile with "<< accel_segments*2 <<" Points. time: " << accel_segments*2*m_dt << "sec"<< endl;
	}

}

// Called repeatedly when this Command is scheduled to run
void TurnTMP::Execute() {

	float cur_vel = m_output.front();
	float cur_dist = m_dist.front();

	//after setting, remove from queue
	m_output.pop();
	m_dist.pop();

	float act_angle =  Drivetrain::GetInstance()->updateGyroYaw() - m_initangle;
	float act_rad_dist = ((M_PI/180) * act_angle)*(DRIVETRAIN_BASE_DIAMETER/2);

	float dist_err = cur_dist - act_rad_dist;
	float dist_comp = dist_err*TURN_DIST_P;

	//convert IPS to RPM
	cur_vel = Drivetrain::GetInstance()->IPStoRPM(cur_vel);

	//SetLeft and SetRight to current queue
	Drivetrain::GetInstance()->SetLeft(cur_vel + dist_comp);
	Drivetrain::GetInstance()->SetRight(-cur_vel - dist_comp);

	//once the queue is empty, set isFinished
	if(m_output.empty())
		m_isFinished=true;

	//debug
	cout << "info: heading error: " << Drivetrain::GetInstance()->GetAngle() - m_finalangle << endl;
}


// Make this return true when this Command no longer needs to run execute()
bool TurnTMP::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void TurnTMP::End() {
	Drivetrain::GetInstance()->SetLeft(0);
	Drivetrain::GetInstance()->SetRight(0);
	cout <<"info: set drivetrain to " << 0 <<" RPM" << endl;

	//empty the queue if interrupted
	while(!m_output.empty())
		m_output.pop();
	while(!m_dist.empty())
		m_dist.pop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnTMP::Interrupted() {
	End();
}

/*
 * DriveFor.c
 *
 *  Created on: Feb 12, 2018
 *      Author: Halen
 */

#include "Drive.h"

Drive::Drive(double inches, double velocity) {
	Requires(Drivetrain::GetInstance());
	m_travelDistance  = inches; //How far we want to go in inches
	m_cruiseVelocity = velocity;

	if(inches<0) {
		m_isReverse=true;
		m_travelDistance = -m_travelDistance;
	}

	if(m_cruiseVelocity > m_maxdrivevelocity) {
		m_cruiseVelocity = m_maxdrivevelocity;
	}

}

// Called just before this Command runs the first time
void Drive::Initialize() {

	//reset isFinished
	m_isFinished=0;
	float decel_dist,accel_dist,hold_time,hold_segments=0;
	bool isTriangular=0;


	//check where we pointing
	m_initangle = Drivetrain::GetInstance()->updateGyroYaw();

	//reset encoder distance
	//Drivetrain::GetInstance()->ZeroSensors();

	//check that the Drivetrain is in closed loop
	if(!Drivetrain::GetInstance()->isClosedLoop())
		Drivetrain::GetInstance()->configClosedLoop();

	Drivetrain::GetInstance()->SetBrakeMode(true);

	//ensure queue is empty
	while(!m_velocity.empty())
		m_velocity.pop();

	while(!m_distance.empty())
		m_distance.pop();

	//to begin, calculate the time we would need to accelerate to the theoretical max speed.
	float decel_time = sqrt((2*m_travelDistance)/((pow(m_maxDecelRate,2)/m_maxAccelRate) + m_maxDecelRate));
	float accel_time = (m_maxDecelRate/m_maxAccelRate)*decel_time;

	float max_accel_vel = m_maxAccelRate*accel_time;
	float max_decel_vel = m_maxDecelRate*decel_time;
	float max_vel = min(max_accel_vel,max_decel_vel);

   if(max_vel>m_cruiseVelocity) {
    max_vel = m_cruiseVelocity;
    cout <<"trapezoid profile" << endl;
    accel_time = m_cruiseVelocity/m_maxAccelRate;
    accel_dist = 0.5*m_maxAccelRate*pow(accel_time,2);

	decel_time = m_cruiseVelocity/m_maxDecelRate;
	decel_dist = 0.5*m_maxDecelRate*pow(decel_time,2);

	hold_time = (m_travelDistance-accel_dist-decel_dist)/m_cruiseVelocity;
    //hold_dist = m_travelDistance - accel_dist - accel_dist;
    hold_segments = ceil(hold_time/m_dt);
   }
   else {
	   cout <<"triangle profile" << endl;
	   isTriangular=true;
	   accel_dist = 0.5*m_maxAccelRate*pow(accel_time,2);
	   decel_dist = 0.5*m_maxDecelRate*pow(decel_time,2);
	   hold_time = 0;
   }

	//calculate the segments needed
    float end_time = accel_time + accel_time + hold_time;
    int accel_segments = ceil(accel_time/m_dt);
	int decel_segments = ceil(decel_time/m_dt);




	//generate acceleration curve
	for(int i = 0;i < accel_segments;i++) {
		double t = m_dt*i;
	    float v = (m_maxAccelRate*t);
	    float d = (0.5*m_maxAccelRate*t*t);

		if(m_isReverse) {
        v=-v;
        d = -d;
        }

	    m_velocity.push(v);
	    m_distance.push(d);
	    //Log

	 }


	//if needed, generate hold
	if(!isTriangular) {
		for(int i = 0;i <= hold_segments;i++) {
			double t = m_dt*i;
			float v = (m_cruiseVelocity);
			float d = (accel_dist+m_cruiseVelocity*t);

			if(m_isReverse) {
				v=-v;
				d = -d;
			}

			m_velocity.push(v);
			m_distance.push(d);

		}
	}

	//generate deceleration curve
	for(int i=1 ;i < decel_segments;i++) {
		float t = m_dt*i;
		float curr_t = t + accel_time + hold_time;
	    float v = max_vel-(m_maxDecelRate*t);
	    float d = m_travelDistance - 0.5*m_maxDecelRate*pow(curr_t-end_time,2);								//very negative

		if(m_isReverse) {
			v=-v;
			d = -d;
		}

	    m_velocity.push(v);
	    m_distance.push(d);


	 }
	 //push last point
	 m_velocity.push(0);

	 if(m_isReverse)
		m_distance.push(-m_travelDistance);
	else
		m_distance.push(m_travelDistance);


	 //log->CloseFile();

	cout<<"info: generated profile with"<< accel_segments+hold_segments+decel_segments << " Points. time: " << end_time <<"sec"<< endl;
}


// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {

	float cur_vel = m_velocity.front();
	float cur_dist = m_distance.front();

	//after setting, remove from queue
	m_velocity.pop();
	m_distance.pop();


	//find actual velocity(rpm)
	int act_lvel = Drivetrain::GetInstance()->getLeftDriveVelocity();
	int act_rvel = Drivetrain::GetInstance()->getRightDriveVelocity();

	//find actual distance and convert to inches
	int act_ldist = Drivetrain::GetInstance()->RotationtoInch(Drivetrain::GetInstance()->GetLeftDistance());
	int act_rdist = Drivetrain::GetInstance()->RotationtoInch(Drivetrain::GetInstance()->GetRightDistance());

	//convert IPS to RPM and account
	cur_vel = Drivetrain::GetInstance()->IPStoRPM(cur_vel);



	//Find left and right velocity error
	float vel_lerr = cur_vel-act_lvel;
	float vel_rerr = cur_vel-act_rvel;
	float vel_lcomp = DRIVETRAIN_P*vel_lerr;
	float vel_rcomp = DRIVETRAIN_P*vel_rerr;

	//compute heading hold compensation
	float cur_angle = Drivetrain::GetInstance()->updateGyroYaw();
	float cur_angle_err = cur_angle - m_initangle;
	float gyro_comp = (DRIVE_GYRO_P*cur_angle_err);



	//SetLeft and SetRight to current queue with gyro compensation
	Drivetrain::GetInstance()->SetDriveVelocity(cur_vel-gyro_comp,cur_vel+gyro_comp)


	//for Testing
	//cout <<"info: set drivetrain to " << cur_vel <<" RPM" << endl;
	//cout <<"info: heading error is " << cur_angle_err << "Degrees" << endl;
	//cout <<"info: gyro_comp " << gyro_comp << "" << endl;
	//cout << "info: Left Distance " << act_ldist << endl;
	//cout <<"info: Set drivetrain V to" << Drivetrain::GetInstance()->RPMtoIPS(cur_vel) << "IPS" << endl;

	frc::SmartDashboard::PutNumber("profileV", Drivetrain::GetInstance()->RPMtoIPS(cur_vel));
	frc::SmartDashboard::PutNumber("profileD", cur_dist);
	frc::SmartDashboard::PutNumber("ActualLV", Drivetrain::GetInstance()->RPMtoIPS(Drivetrain::GetInstance()->GetLeftVelocity()));
	frc::SmartDashboard::PutNumber("ActualRV", Drivetrain::GetInstance()->RPMtoIPS(Drivetrain::GetInstance()->GetRightVelocity()));
	frc::SmartDashboard::PutNumber("ActualD", Drivetrain::GetInstance()->GetLeftDistance());
	frc::SmartDashboard::PutNumber("outputLeftV", Drivetrain::GetInstance()->GetLeftThrottle());
	frc::SmartDashboard::PutNumber("outputRightV", Drivetrain::GetInstance()->GetRightThrottle());

	//once the queue is empty, set isFinished
	if(m_velocity.empty())
		m_isFinished=true;
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void Drive::End() {
	Drivetrain::GetInstance()->SetDriveVelocity(0,0);



	//empty the queue if interrupted
	while(!m_velocity.empty())
		m_velocity.pop();

	while(!m_distance.empty())
		m_distance.pop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {
	End();
}



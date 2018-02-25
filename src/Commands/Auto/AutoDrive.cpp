#include <Commands/Auto/AutoDrive.h>
#include <Util/UnitMaster.h>
#include <iostream>

UnitMaster unit_master_conv;

AutoDrive::AutoDrive(double inches, double cruise_velocity, double final_velocity) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());

	m_travelDistance = inches;
	m_cruiseVelocity = cruise_velocity;
	m_finalVelocity = final_velocity;

	//check is we're going backwards
	if(inches<0) {
		m_isReverse=true;
		m_travelDistance = -m_travelDistance;
	}

	//check if the requested velocity is too high
	if(m_cruiseVelocity > m_maxdrivevelocity) {
		m_cruiseVelocity = m_maxdrivevelocity;
	}
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	m_initangle = Drivetrain::GetInstance()->getGyroYaw();
	m_leftStartPos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_rightStartPos = Drivetrain::GetInstance()->getRightDrivePosition();
	m_distanceTicks = (m_travelDistance*TICKS_PER_ROTATIONS)/WHEEL_CIRC_INCHES;

	//reset isFinished
	m_isFinished=0;

	float decel_dist,accel_dist,hold_time,hold_segments=0;
	bool isTriangular=0;

	//check that the Drivetrain is in closed loop
	if(!Drivetrain::GetInstance()->isClosedLoopVelocity())
		Drivetrain::GetInstance()->configClosedLoopVelocity();

	//set Brake Mode
	Drivetrain::GetInstance()->SetBrakeMode(true);

	//ensure the queue is empty
	while(!m_trajectory.empty())
		m_trajectory.pop();

	//calculate the time we would need to accelerate to the theoretical max speed.
	float decel_time = sqrt((2*m_travelDistance)/((pow(m_maxDecelRate,2)/m_maxAccelRate) + m_maxDecelRate));
	float accel_time = (m_maxDecelRate/m_maxAccelRate)*decel_time;

	float max_accel_vel = m_maxAccelRate*accel_time;
	float max_decel_vel = m_maxDecelRate*decel_time;
	float max_vel = min(max_accel_vel,max_decel_vel);

	//If we can reach the max velocity, the profile is trapezoidal
	if(max_vel>m_cruiseVelocity) {
	    max_vel = m_cruiseVelocity;
	    accel_time = m_cruiseVelocity/m_maxAccelRate;
	    accel_dist = 0.5*m_maxAccelRate*pow(accel_time,2);

		decel_time = m_cruiseVelocity/m_maxDecelRate;
		decel_dist = 0.5*m_maxDecelRate*pow(decel_time,2);

		hold_time = (m_travelDistance-accel_dist-decel_dist)/m_cruiseVelocity;

	} else { //if we can't reach reach the max velocity, the profile is triangular
	   isTriangular=true;
	   accel_dist = 0.5*m_maxAccelRate*pow(accel_time,2);
	   decel_dist = 0.5*m_maxDecelRate*pow(decel_time,2);
	   hold_time = 0;
	}

	//calculate the number of points needed
    float end_time = accel_time + decel_time + hold_time;
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

		m_trajectory.push({t,v,v,d,d});
	}

	//if needed, generate the velocity hold
	if(!isTriangular) {
		for(int i = 0;i <= hold_segments;i++) {
			double t = m_dt*i;
			float v = m_cruiseVelocity;
			float d = accel_dist+m_cruiseVelocity*t;

			if(m_isReverse) {
				v=-v;
				d = -d;
			}

			m_trajectory.push({accel_time + t,v,v,d,d});
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

		m_trajectory.push({accel_time + hold_time + t,v,v,d,d});

	}

	//push last point
	if(m_isReverse)
		m_trajectory.push({end_time,0,0,-m_travelDistance,-m_travelDistance});
	else
		m_trajectory.push({end_time,0,0,m_travelDistance,m_travelDistance});


}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {


	//read current values from queue
	float cur_t = m_trajectory.front().t;
	float cur_v_l = m_trajectory.front().v_left;
	float cur_v_r = m_trajectory.front().v_right;
	float cur_d_l = m_trajectory.front().d_left;
	float cur_d_r = m_trajectory.front().d_right;

	//after setting, remove from queue
	m_trajectory.pop();

	//read actual velocity (returns native units)
	double act_lvel = Drivetrain::GetInstance()->getLeftDriveVelocity();
	double act_rvel = Drivetrain::GetInstance()->getRightDriveVelocity();

//	std::cout << "AutoDrive: GetLeftVelocity " << act_lvel << std::endl;
//	std::cout << "AutoDrive: GetRightVelocity " << act_rvel << std::endl;


	//find actual distance
	int act_ldist = Drivetrain::GetInstance()->getLeftDrivePosition();
	int act_rdist = Drivetrain::GetInstance()->getRightDrivePosition();

	//find left/right velocity error (needs conversion to native units)
	float vel_lerr = cur_v_l-act_lvel;
	float vel_rerr = cur_v_r-act_rvel;
//	float vel_lcomp = DRIVE_VELOCITY_P*vel_lerr;
//	float vel_rcomp = DRIVE_VELOCITY_P*vel_rerr;

	//get gyro angle and compensate
	double cur_angle = Drivetrain::GetInstance()->getGyroYaw();
	std::cout << "Gyro Yaw: " << cur_angle << std::endl;
	float cur_angle_err = cur_angle - m_initangle;
	std::cout << "Gyro Error: " << cur_angle_err << std::endl;
	float gyro_comp = (DRIVE_GYRO_COMP_P*cur_angle_err);


	//SetLeft and SetRight to current queue with gyro compensation (in native unit)
//	std::cout << "TrajLeftVel: " << cur_v_l << std::endl;
//	std::cout << "TrajRightVel: " << cur_v_r << std::endl;
	Drivetrain::GetInstance()->SetDriveVelocity(unit_master_conv.GetTicksPer100ms(cur_v_l-gyro_comp),unit_master_conv.GetTicksPer100ms(cur_v_r+gyro_comp));
//	std::cout << "AutoDrive: SetLeftVelocity " << unit_master_conv.GetTicksPer100ms(cur_v_l-gyro_comp) << std::endl;
//	std::cout << "AutoDrive: SetRightVelocity " << unit_master_conv.GetTicksPer100ms(cur_v_r-gyro_comp) << std::endl;

    float distErrorL = abs(Drivetrain::GetInstance()->getLeftDrivePosition()  - m_leftStartPos) - m_distanceTicks;
    float distErrorR = abs(Drivetrain::GetInstance()->getRightDrivePosition()  - m_rightStartPos) - m_distanceTicks;
    float distErrorAvg = (distErrorL + distErrorR)/2;
//    std::cout << "Gyro Yaw: " << gyro_comp << " Distance Error Avg: "  << distErrorAvg << std::endl;

	if(m_trajectory.empty() )
		m_isFinished = true;
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void AutoDrive::End() {
	Drivetrain::GetInstance()->SetDriveVelocity(m_finalVelocity,m_finalVelocity);

	//empty the queue if interrupted
	while(!m_trajectory.empty())
		m_trajectory.pop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {
	End();
}

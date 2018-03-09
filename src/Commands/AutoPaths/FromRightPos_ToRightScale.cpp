#include "FromRightPos_ToRightScale.h"
#include "OI.h"
#include <iostream>


FromRightPos_ToRightScale::FromRightPos_ToRightScale() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());


}

// Called just before this Command runs the first time
void FromRightPos_ToRightScale::Initialize() {
	Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::PATH_CONFIG);
	m_initTime = frc::Timer::GetFPGATimestamp();
	m_isFinished = false;
//	std::cout << "Init" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void FromRightPos_ToRightScale::Execute() {

	double timeEnlapsed = frc::Timer::GetFPGATimestamp() - m_initTime;

	int time_index = (int)(timeEnlapsed / m_pathDT);

//	std::cout << time_index << std::endl;

	if(time_index > num_index){
		m_isFinished = true;
		return;
	}
	double l_pos = left_wheel[time_index][0];
	double l_vel = left_wheel[time_index][1];
	double l_acc = left_wheel[time_index][2];

	double r_pos = right_wheel[time_index][0];
	double r_vel = right_wheel[time_index][1];
	double r_acc = right_wheel[time_index][2];

	double heading = left_wheel[time_index][4];

	Drivetrain::GetInstance()->SetPathDriveVelocity(l_pos, l_vel, l_acc, r_pos, r_vel, r_acc, heading,false);


//	if(OI::GetInstance()->drvStick->GetRawButton(1)){
//		Drivetrain::GetInstance()->SetDriveVelocity(unit_master.GetTicksPer100ms(140.0), unit_master.GetTicksPer100ms(140.0));
//	//	std::cout << "works" << std::endl;
//	}
//	else
//		Drivetrain::GetInstance()->Arcade(OI::GetInstance()->drvStick->GetRawAxis(4), -OI::GetInstance()->drvStick->GetRawAxis(1));
}

// Make this return true when this Command no longer needs to run execute()
bool FromRightPos_ToRightScale::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void FromRightPos_ToRightScale::End() {
	Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::OPEN_LOOP);
	Drivetrain::GetInstance()->Arcade(0,0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FromRightPos_ToRightScale::Interrupted() {

}

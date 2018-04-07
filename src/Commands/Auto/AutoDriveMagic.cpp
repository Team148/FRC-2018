/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoDriveMagic.h"
#include "../../Subsystems/Drivetrain.h"
#include "Constants.h"
#include <iostream>



AutoDriveMagic::AutoDriveMagic(double inches, double cruise_velocity, double acceleration, double heading) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	m_inches = inches;
	m_cruise_velocity = cruise_velocity;
	m_acceleration = acceleration;
	m_heading = heading;

}

// Called just before this Command runs the first time
void AutoDriveMagic::Initialize() {
	m_isFinished = false;
	Drivetrain::GetInstance()->SetEncoderPosition(0,0);

	Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::MOTION_MAGIC_CONFIG, m_cruise_velocity, m_acceleration);
	double conv_m_inches = unit_master.GetTicks(m_inches, tUnits::INCHES);

	Drivetrain::GetInstance()->SetDrivePositionMagic(conv_m_inches, conv_m_inches);


}

// Called repeatedly when this Command is scheduled to run
void AutoDriveMagic::Execute() {
	double cur_l_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	double cur_r_pos = Drivetrain::GetInstance()->getRightDrivePosition();

	frc::SmartDashboard::PutNumber("cur_l_pos", cur_l_pos);
	frc::SmartDashboard::PutNumber("cur_r_pos", cur_r_pos);




	double conv_m_inches = unit_master.GetTicks(m_inches, tUnits::INCHES);

	frc::SmartDashboard::PutNumber("error_l", conv_m_inches-cur_l_pos);


	if(cur_l_pos > (conv_m_inches)-50 && cur_r_pos > (conv_m_inches)-50)
	{
		m_isFinished = true;
	}


}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveMagic::IsFinished() {
	std::cout << "AutoDriveMagic Finished" << std::endl;
	return m_isFinished;
}

// Called once after isFinished returns true
void AutoDriveMagic::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveMagic::Interrupted() {

}

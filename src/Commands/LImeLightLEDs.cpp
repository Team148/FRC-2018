/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/LImeLightLEDs.h"

LImeLightLEDs::LImeLightLEDs(int Mode = 0) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(LimelightCamera::GetInstance());
	m_limeLightMode = Mode;
}

// Called just before this Command runs the first time
void LImeLightLEDs::Initialize() {
	switch(m_limeLightMode)
	{
		case 0:
			LimelightCamera::GetInstance()->SetCameraLEDOff();
		case 1:
			LimelightCamera::GetInstance()->SetCameraLEDOn();
		case 2:
			LimelightCamera::GetInstance()->SetCameraLEDBlink();
		default:
			LimelightCamera::GetInstance()->SetCameraLEDOff();


	}
}

// Called repeatedly when this Command is scheduled to run
void LImeLightLEDs::Execute() {
	m_isFinished = true;
}

// Make this return true when this Command no longer needs to run execute()
bool LImeLightLEDs::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void LImeLightLEDs::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LImeLightLEDs::Interrupted() {

}

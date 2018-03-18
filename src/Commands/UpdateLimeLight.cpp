/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "UpdateLimeLight.h"

UpdateLimeLight::UpdateLimeLight() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(LimelightCamera::GetInstance());
}

// Called just before this Command runs the first time
void UpdateLimeLight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void UpdateLimeLight::Execute() {
	LimelightCamera::GetInstance()->GetCameraData();
}

// Make this return true when this Command no longer needs to run execute()
bool UpdateLimeLight::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void UpdateLimeLight::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpdateLimeLight::Interrupted() {

}

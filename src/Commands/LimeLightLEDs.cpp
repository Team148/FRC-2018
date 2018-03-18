/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/LimeLightLEDs.h>

LimeLightLEDs::LimeLightLEDs(int mode) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_limeLightMode = mode;
}

// Called just before this Command runs the first time
void LimeLightLEDs::Initialize() {
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



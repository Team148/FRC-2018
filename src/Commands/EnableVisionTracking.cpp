/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "EnableVisionTracking.h"
#include "Subsystems/LimelightCamera.h"


EnableVisionTracking::EnableVisionTracking(bool on, double pipe) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_on = on;
	m_pipe = pipe;
}

// Called once when the command executes
void EnableVisionTracking::Initialize() {
	LimelightCamera::GetInstance()->SetPipeline(m_pipe);
	if(m_on)
	{
		LimelightCamera::GetInstance()->SetEnableVision(true);
		std::cout << "Enable Vision Command" << std::endl;
	}
	else
	{
		LimelightCamera::GetInstance()->SetEnableVision(false);
		std::cout << "Disabled Vision Command" << std::endl;
	}

}

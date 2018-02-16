/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoSetElevator.h"

AutoSetElevator::AutoSetElevator(bool on, double position) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Elevator::GetInstance());
}

// Called just before this Command runs the first time
void AutoSetElevator::Initialize() {
	if (m_on)
	{
		Elevator::GetInstance()->SetElevatorPosition(m_position);
	}
	else
	{
		Elevator::GetInstance()->SetElevatorPosition(1.0);
	}
}



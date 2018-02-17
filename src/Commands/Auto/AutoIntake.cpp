/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoIntake.h"
#include <iostream>

AutoIntake::AutoIntake(double percent, double runTime) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Intake::GetInstance());
	m_percent = percent;
	m_runTime = runTime;
}

// Called just before this Command runs the first time
void AutoIntake::Initialize() {
	m_startTime = frc::Timer::GetFPGATimestamp();
	Intake::GetInstance()->SetIntakeMotor(m_percent);
	m_isIntakeOn = true;
	m_IsFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoIntake::Execute() {
	double deltaTime;

	m_currentTime =  frc::Timer::GetFPGATimestamp();
	deltaTime = m_currentTime - m_startTime;
    std::cout << deltaTime << std::endl;
	if(deltaTime >= m_runTime   )
	{
		Intake::GetInstance()->SetIntakeMotor(0);
		m_IsFinished = true;
	}



}

// Make this return true when this Command no longer needs to run execute()
bool AutoIntake::IsFinished() {
	return m_IsFinished;
}

// Called once after isFinished returns true
void AutoIntake::End() {
	m_IsFinished = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoIntake::Interrupted() {
	m_IsFinished = false;
}

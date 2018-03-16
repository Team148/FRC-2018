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
	Intake::GetInstance()->SetIntakeMotor(m_percent);


	m_totalCurrent = 0;
	m_timesExecuted = 0;
	m_startTime = frc::Timer::GetFPGATimestamp();

	m_isIntakeOn = true;
	m_IsFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoIntake::Execute() {

	//Intake
	if(m_percent > 0)
	{
		InTake();
	}

	//OutTake
	else if(m_percent < 0)
	{
		OutTake();
	}

	//Doesn't Run if m_percent == 0
	else
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
	std::cout << "FINISHED: TurnPosition" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoIntake::Interrupted() {
	End();
}


void AutoIntake::OutTake()
{

	double deltaTime;

	m_currentTime =  frc::Timer::GetFPGATimestamp();
	deltaTime = m_currentTime - m_startTime;
	std::cout << deltaTime << std::endl;
	if(deltaTime >= m_runTime)
	{
		Intake::GetInstance()->SetIntakeMotor(0);
		m_IsFinished = true;
	}

}
void AutoIntake::InTake()
{
	float totalRunTime = frc::Timer::GetFPGATimestamp() - m_startTime;


	float avgCurrent = Intake::GetInstance()->GetAverageCurrent();

	if(avgCurrent >= CUBE_IN_CURRENT_CURRENT || m_startToIntakeCube == true)
	{
		if(m_startToIntakeCube == false)
		{
			std::cout << "IntakeTimeOutTime: " << totalRunTime << std::endl;
			m_startToIntakeCube = true;
			m_startIntakeTime = frc::Timer::GetFPGATimestamp();
		}

		float elapsedTime = frc::Timer::GetFPGATimestamp() - m_startIntakeTime;

		if(elapsedTime >= TIME_TO_RUN_INTAKE)
		{
			Intake::GetInstance()->SetIntakeMotor(0);
			m_IsFinished = true;
		}

	}

	if(totalRunTime >= m_runTime)
	{
		std::cout << "commandTimeOutTime: " << totalRunTime << std::endl;
		Intake::GetInstance()->SetIntakeMotor(0);
		m_IsFinished = true;
	}

}







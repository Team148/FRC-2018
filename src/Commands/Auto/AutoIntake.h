/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Commands/Command.h"
#include "CommandBase.h"
#include "constants.h"

class AutoIntake : public CommandBase {
private:
	bool m_isIntakeOn = false;
	bool m_IsFinished = false;

	double m_percent = 0;
	double m_runTime = 0;
	double m_startTime = 0;
	double m_currentTime = 0;

public:
	AutoIntake(double percent, double runTime);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};


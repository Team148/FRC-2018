/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include <Commands/Command.h>
#include "CommandBase.h"

class CheckHeading : public CommandBase {
public:

	CheckHeading(double heading, double tolerance, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:

	bool m_isFinished = false;
	double m_timeOut = 0;
	double m_tolerance = 0;
	double m_heading = 0;
};


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

class AutoSetElevator : public CommandBase {
public:
	AutoSetElevator(bool on, double position);
	void Initialize() override;

private:
	bool m_on = false;
	double m_position;
	double m_inches;

};


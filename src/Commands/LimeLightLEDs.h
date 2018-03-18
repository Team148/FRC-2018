/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Commands/InstantCommand.h"
#include "Subsystems/LimeLightCamera.h"

class LimeLightLEDs : public frc::InstantCommand {
public:
	LimeLightLEDs(int mode=0);
	void Initialize() override;

private:
	int m_limeLightMode = 0;
};


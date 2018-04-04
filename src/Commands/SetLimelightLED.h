/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Commands/InstantCommand.h"
#include "Subsystems/LimelightCamera.h"

class SetLimelightLED : public frc::InstantCommand {
public:
	SetLimelightLED(bool on);
	void Initialize() override;

private:
	bool m_on;
};


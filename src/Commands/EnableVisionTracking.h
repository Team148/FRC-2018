/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Commands/InstantCommand.h"

class EnableVisionTracking : public frc::InstantCommand {
public:
	EnableVisionTracking(bool on, double pipe);
	void Initialize() override;

private:
	bool m_on;
	double m_pipe;
};


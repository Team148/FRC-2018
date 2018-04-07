/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include <Commandbase.h>
#include "Util/UnitMaster.h"



class AutoDriveMagic : public frc::Command {
public:
	AutoDriveMagic(double inches, double cruise_velocity, double acceleration, double heading);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	UnitMaster unit_master;
	double m_inches = 0.0;
	double m_cruise_velocity = 0.0;
	double m_acceleration = 0.0;
	double m_heading = 0.0;
	bool m_isFinished = false;

};


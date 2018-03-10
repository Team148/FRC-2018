/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Util/UnitMaster.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "constants.h"

class AutoLimeTurn : public CommandBase {
public:
	AutoLimeTurn();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	UnitMaster unit_master;
	LimelightCamera* m_instance;
	float m_cur_angle;
	float m_angle_err;
	float m_l_cur_pos;
	float m_r_cur_pos;
	bool m_isFinished = false;
};


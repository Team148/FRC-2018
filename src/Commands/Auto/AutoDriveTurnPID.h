/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include <Commandbase.h>

class AutoDriveTurnPID : public frc::Command {
public:
	AutoDriveTurnPID(double degrees);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	bool m_isFinished = false;

	float m_degreesToTurn;
	float currentGyroValue;
	float m_cumlativeError = 0;
	float m_intailAngle;

	float P_VALUE = .009;
	float I_VALUE = .0001;
	float D_VALUE = 0;
	float output = 0;
	float TIME_STEP = .02;
	float TURN_TOLERENCE = .01;


};


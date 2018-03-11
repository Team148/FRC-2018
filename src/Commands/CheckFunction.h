/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef CheckFunction_H
#define CheckFunction_H

#include <Commands/Command.h>
#include "Subsystems/Drivetrain.h"
#include "OI.h"
#include "Constants.h"
#include <iostream>

class CheckFunction : public frc::Command {
public:
	CheckFunction();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	//drivetrain motor current lower limit
	double drivelowerlimit = 0.1;
	double drivecurrent[6][10] = {};
	int drivecurrentcounter = 0;
	bool readytocheck=false;
	bool l1currentpass=false;
	bool l2currentpass=false;
	bool l3currentpass=false;
	bool r1currentpass=false;
	bool r2currentpass=false;
	bool r3currentpass=false;

	bool l1failflag=false;
	bool l2failflag=false;
	bool l3failflag=false;

};

#endif


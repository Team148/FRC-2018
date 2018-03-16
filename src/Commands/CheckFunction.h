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
#include "Subsystems/Elevator.h"
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
	//std::shared_ptr<NetworkTable> table;
	double pdp_curr[16][10]={};
	int currentcounter=0;
	double drivelowerlimit = 0.1;

	bool drivereadytocheck=false;

	double elevlowerlimit = 0.1;
	bool elevreadytocheck=false;

	double intakelowerlimit = 0.1;
	double intakecurrent[2][10] = {};
	bool intakereadytocheck=false;

	bool l1currentpass=false;
	bool l2currentpass=false;
	bool l3currentpass=false;
	bool r1currentpass=false;
	bool r2currentpass=false;
	bool r3currentpass=false;

	bool l1failflag=false;
	bool l2failflag=false;
	bool l3failflag=false;
	bool r1failflag=false;
	bool r2failflag=false;
	bool r3failflag=false;

	bool elev1failflag=false;
	bool elev2failflag=false;

	bool elev1currentpass=false;
	bool elev2currentpass=false;
	bool elevatorencoderpass=false;

	bool intake1currentpass=false;
	bool intake2currentpass=false;

	bool intake1failflag=false;
	bool intake2failflag=false;

	bool driveleftencoderpass=false;
	bool driverightencoderpass=false;

	bool wranglercurrentpass=false;

	bool climber1currentpass=false;
	bool climber2currentpass=false;
	bool climber3currentpass=false;

};

#endif


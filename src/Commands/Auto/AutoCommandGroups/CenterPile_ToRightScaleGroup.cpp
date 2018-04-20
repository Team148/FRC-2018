/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/



#include "CenterPile_ToRightScaleGroup.h"
#include "CommonCommandHeaders.h"

CenterPile_ToRightScaleGroup::CenterPile_ToRightScaleGroup() {

	AddSequential(new TurnPosition(270, .5)); // starts at 270
	AddSequential(new PathExecuter(FromCenterPile_ToRightScaleSneak::GetInstance(), false));
	AddSequential(new AutoDrive(-12, 150, 0, 100, 90)); // ends at 90
	AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0, 500));
	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	AddSequential(new AutoDrive(-12, 150, 0, 100, 90));
}

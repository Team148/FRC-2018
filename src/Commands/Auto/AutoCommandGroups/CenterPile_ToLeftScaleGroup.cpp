/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CenterPile_ToLeftScaleGroup.h"
#include "CommonCommandHeaders.h"


CenterPile_ToLeftScaleGroup::CenterPile_ToLeftScaleGroup()
{
	AddSequential(new TurnPosition(90, .5)); // starts at 90
	AddSequential(new PathExecuter(FromCenterPile_ToLeftScaleSneak::GetInstance(), false));
	AddSequential(new AutoDrive(-12, 150, 0, 100, 270)); // ends at 270
	AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0, 500));
	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	AddSequential(new AutoDrive(-12, 150, 0, 100, 270));
}

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "FrontLeftSwitchGroup.h"
#include "CommonCommandHeaders.h"


FrontLeftSwitchGroup::FrontLeftSwitchGroup()
{
	AddParallel(new ReleaseIntake());
	AddParallel(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, FromMiddlePos_ToLeftSwitchPath::GetInstance()->GetTimeLength()-1.2));
	AddSequential(new PathExecuter(FromMiddlePos_ToLeftSwitchPath::GetInstance(), false));
	AddSequential(new AutoIntake(-0.40, 0.5));
	AddParallel(new AutoSetElevator(ELEVATOR_ZERO, 0.35, 500));
	AddSequential(new PathExecuter(FromLeftSwitchFront_ToCenterPileReversed::GetInstance(), true));
	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
	AddSequential(new AutoDrive(43, 100, 0, 90, 0));
	AddSequential(new AutoDrive(-43, 150, 0, 120, 0));
	AddParallel(new AutoIntake(INTAKE_HOLD_AUTO_PERCENT, 3.0));
	AddParallel(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, FromCenterPile_ToLeftSwitchFront::GetInstance()->GetTimeLength()-1.2));
	AddSequential(new PathExecuter(FromCenterPile_ToLeftSwitchFront::GetInstance(), false));
	AddSequential(new AutoIntake(-0.40, 0.35));
	AddSequential(new AutoDrive(-10, 150, 0, 120, 0));
	AddParallel(new AutoSetElevator(ELEVATOR_ZERO, 0.0, 500));
	AddSequential(new TurnPositionMagic(305, 1.0, 150, 100));
	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
	AddSequential(new AutoDrive(30, 50, 0, 100 ,305));
	AddSequential(new PathExecuter(FromLeftSwitchFront_ToLeftScaleBackReversePath::GetInstance(), true));
}

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "FrontRightSwitchGroup.h"
#include "../../../OI.h"
#include "CommonCommandHeaders.h"


FrontRightSwitchGroup::FrontRightSwitchGroup()
{
	AddParallel(new ReleaseIntake());
	AddParallel(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, FromMiddlePos_ToRightSwitchPath::GetInstance()->GetTimeLength()-1.2));
	AddSequential(new PathExecuter(FromMiddlePos_ToRightSwitchPath::GetInstance(), false));
	AddSequential(new AutoIntake(-0.40, 0.5));
	AddParallel(new AutoSetElevator(ELEVATOR_ZERO, 0.35, 500));
	AddSequential(new PathExecuter(FromRightSwitchFront_ToCenterPileReversed::GetInstance(), true));
	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
	AddSequential(new AutoDrive(46, 100, 0, 90, 0));

//	if(OI::GetInstance()->GetSw4())
//	{
//		if(ScaleRight) // R POS RR
//		{
//			AddSequential(new CenterPile_ToRightScaleGroup());
//
//		}
//		if(!ScaleRight) // R POS RR
//		{
//			AddSequential(new CenterPile_ToLeftScaleGroup());
//		}

//		AddSequential(new TurnPosition(270, .5)); // starts at 270
//		AddSequential(new PathExecuter(FromCenterPile_ToRightScaleSneak::GetInstance(), false));
//		AddSequential(new AutoDrive(-12, 150, 0, 100, 90)); // ends at 90
//		AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0, 500));
//		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
//		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
//		AddSequential(new AutoDrive(-12, 150, 0, 100, 90));



//	}
//	else // veryimportante
//	{

		AddSequential(new AutoDrive(-46, 150, 0, 100, 0));
		AddParallel(new AutoIntake(INTAKE_HOLD_AUTO_PERCENT, 3.0));
		AddParallel(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, FromCenterPile_ToRightSwitchFront::GetInstance()->GetTimeLength()-1.2));
		AddSequential(new PathExecuter(FromCenterPile_ToRightSwitchFront::GetInstance(), false));
		AddSequential(new AutoIntake(-0.40, 0.35));
		AddSequential(new AutoDrive(-10, 150, 0, 120, 0));
		AddParallel(new AutoSetElevator(ELEVATOR_ZERO, 0.0, 500));
		AddSequential(new TurnPositionMagic(55, 1.0, 150, 100));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
		AddSequential(new AutoDrive(30, 50, 0, 100 ,55));
		AddSequential(new PathExecuter(FromRightSwitchFront_ToRightScaleBackReversePath::GetInstance(), true));
//	}
}

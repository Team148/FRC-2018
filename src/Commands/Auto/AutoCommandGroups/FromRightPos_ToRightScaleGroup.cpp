/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "FromRightPos_ToRightScaleGroup.h"
#include "../../../Constants.h"
#include "CommonCommandHeaders.h"


FromRightPos_ToRightScaleGroup::FromRightPos_ToRightScaleGroup()
{

	// Run path and bring up elevator 1.0 second before path ends
	AddParallel(new ReleaseIntake());
	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH-2500, FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength()-1.0));
    AddSequential(new PathExecuter(FromRightPos_ToRightScalePath::GetInstance(), false));

    // spit cube out
    AddSequential(new AutoIntake(-0.40, 0.3));

    //Turn while bringing the elevator down
    AddParallel(new TurnPositionMagic(150, 1.6, 150, 70));
    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
}

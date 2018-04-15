/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "FromRightPos_ToLeftSwitchGroup.h"
#include "../../../Constants.h"
#include "CommonCommandHeaders.h"


FromRightPos_ToLeftSwitchGroup::FromRightPos_ToLeftSwitchGroup()
{

    AddParallel(new ReleaseIntake());
	AddParallel(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, FromRightPos_ToLeftSwitchPath::GetInstance()->GetTimeLength()-2.0));
	AddSequential(new PathExecuter(FromRightPos_ToLeftSwitchPath::GetInstance(), false)); // need to add

	AddSequential(new TurnPosition(185, 0.4));

	AddSequential(new AutoIntake(-0.45, 0.4));
}

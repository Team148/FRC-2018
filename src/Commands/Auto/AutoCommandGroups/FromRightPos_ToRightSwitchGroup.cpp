/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "FromRightPos_ToRightSwitchGroup.h"
#include "../../../Constants.h"
#include "CommonCommandHeaders.h"


FromRightPos_ToRightSwitchGroup::FromRightPos_ToRightSwitchGroup()
{

	AddParallel(new ReleaseIntake());
    AddParallel(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, FromRightPos_ToRightSwitchPath::GetInstance()->GetTimeLength()-1.5));
    AddSequential(new PathExecuter(FromRightPos_ToRightSwitchPath::GetInstance(), false, 0, 25));
    AddSequential(new TurnPositionMagic(170, 0.5,150,150));


//    AddSequential(new AutoIntake(INTAKE_SLOW_AUTO_PERCENT, 0.2));
    //Spit
    AddSequential(new AutoIntake(-0.45, 0.5));

    //Backup and home elevator

	AddSequential(new AutoDrive(-15, 150, 0, 100, 180));
	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

	//Grab cube and end

}

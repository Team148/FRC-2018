/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "FromRightPos_ToLeftScaleGroup.h"
#include "../../../Constants.h"
#include "CommonCommandHeaders.h"


FromRightPos_ToLeftScaleGroup::FromRightPos_ToLeftScaleGroup()
{

	AddParallel(new ReleaseIntake());
	AddSequential(new PathExecuter(FromRightPos_ToLeftScalePath::GetInstance(), false, 0, 25)); // add pls
	AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH-2500, 0.0));
//	AddParallel(new TurnPositionMagic(190, 0.3 ,120,70));


	//Spit
	AddSequential(new AutoIntake(-0.6, 0.3));
//			AddSequential(new AutoDrive(-10, 100, 0, 70, 0));

	//turn and bring elevator down
	AddParallel(new TurnPositionMagic(210, 1.2,120,90));
    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
}

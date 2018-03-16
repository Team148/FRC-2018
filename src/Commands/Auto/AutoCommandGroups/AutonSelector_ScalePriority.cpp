#include <Commands/Auto/AutoCommandGroups/AutonSelector_ScalePriority.h>
#include "../../AutoPaths/PathExecuter.h"
#include "./Paths/FakeStraightPath.h"
#include "./Paths/FromMiddlePos_ToLeftSwitchPath.h"
#include "./Paths/FromRightPos_ToLeftSwitchPath.h"
#include "./Paths/FromRightPos_ToLeftSwitchPathReversed.h"
#include "./Paths/FromRightPos_ToRightScalePath.h"
#include "./Paths/FromRightScale_ToRightFirstCubePath.h"
#include "./Paths/FromRightScale_ToRightSecondCubePath.h"
#include "./Paths/FromMiddlePos_ToRightSwitchPath.h"
#include "./Paths/FromRightFirstCube_ToRightScalePath.h"

#include "./Paths/GoStraightPath.h"
#include "../TurnPosition.h"
#include "../AutoIntake.h"
#include "../AutoSetElevator.h"
#include "../AutoDrive.h"
#include <iostream>



AutonSelector_ScalePriority::AutonSelector_ScalePriority(int start_pos, std::string FMS_Data, int cube_amount)
{

	std::string fms_data_truc = FMS_Data.substr (0,2);
    std::cout << "What I See: " << fms_data_truc << std::endl;



if(start_pos == tStartingPosition::RIGHT_POS)
{
	if(fms_data_truc.compare(autoConstData.R_R) == 0) // R POS RR
	{
	   // AddSequential(new FromMiddlePos_ToRightScale());
	    std::cout << FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength() << std::endl;

//	    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength()-1.1));
	    AddSequential(new PathExecuter(FromRightPos_ToRightScalePath::GetInstance(), false));
	    AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0)); // ADDED, NOT NORMAL
	    AddSequential(new WaitCommand(0.5));
	    AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.3));
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    AddSequential(new TurnPosition(170, 0.5));
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, FromRightScale_ToRightFirstCubePath::GetInstance()->GetTimeLength()+3.0));
	    AddSequential(new PathExecuter(FromRightScale_ToRightFirstCubePath::GetInstance(), false));
	    								//    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.5));
//	    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromRightFirstCube_ToRightScalePath::GetInstance()->GetTimeLength()-1.0));
	    								//    AddParallel(new AutoIntake(INTAKE_SLOW_PERCENT, 5.0));
	    AddSequential(new PathExecuter(FromRightFirstCube_ToRightScalePath::GetInstance(), true));
	    AddSequential(new TurnPosition(70, 0.5));
	    AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0)); // ADDED, NOT NORMAL
	    AddSequential(new WaitCommand(0.2));
	    AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
	    AddSequential(new AutoDrive(-15, 150, 0, 70));
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    AddSequential(new TurnPosition(135, 0.5));
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 10.0));
	    AddSequential(new PathExecuter(FromRightScale_ToRightSecondCubePath::GetInstance(), false));


	}

	if(fms_data_truc.compare(autoConstData.R_L) == 0) // R POS RL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;
	    AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, 1.2));
	    AddSequential(new PathExecuter(FromMiddlePos_ToRightSwitchPath::GetInstance(), false));
	    AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 2.0));
	    AddSequential(new AutoDrive(-15, 150, FromMiddlePos_ToRightSwitchPath::GetInstance()->GetEndHeading()));
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

	}
	if(fms_data_truc.compare(autoConstData.L_R) == 0) // R POS LR
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;
/*

*/
	}
	if(fms_data_truc.compare(autoConstData.L_L) == 0) // R POS LL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;
	    AddSequential(new WaitCommand(20.0));
	   AddSequential(new PathExecuter(FromRightPos_ToLeftSwitchPathReversed::GetInstance(),true));


	}
}





}

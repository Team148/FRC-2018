#include <Commands/Auto/AutoCommandGroups/AutonSelector_ScalePriority.h>
#include "../../AutoPaths/PathExecuter.h"
#include "./Paths/FromMiddlePos_ToLeftSwitchPath.h"
#include "./Paths/FromRightPos_ToLeftSwitchPath.h"
#include "./Paths/FromRightPos_ToLeftScalePath.h"
#include "./Paths/FromRightPos_ToLeftScalePathSpecial.h"
#include "./Paths/FromRightPos_ToLeftScale118Path.h"
#include "./Paths/FromRightPos_ToLeftSwitchPathReversed.h"
#include "./Paths/FromRightPos_ToRightScalePath.h"
#include "./Paths/FromRightScale_ToRightFirstCubePath.h"
#include "./Paths/FromRightScale_ToRightSecondCubePath.h"
#include "./Paths/FromMiddlePos_ToRightSwitchPath.h"
#include "./Paths/FromMiddlePos_ToLeftScaleDumpPath.h"
#include "./Paths/FromRightFirstCube_ToRightScalePath.h"

#include "Paths/FromRightPos_ToLeftScalePath_Part1.h"
#include "Paths/FromRightPos_ToLeftScalePath_Part2.h"
#include "Paths/FromRightPos_ToLeftScalePath_Part3.h"

#include "../../../OI.h"

#include "./Paths/GoStraightPath.h"
#include "../TurnPosition.h"
#include "../TurnPositionMagic.h"
#include "../DriveLineVelocity.h"
#include "../AutoIntake.h"
#include "../ReleaseIntake.h"
#include "../AutoSetElevator.h"
#include "../AutoDrive.h"
#include "../AutoDriveMagic.h"
#include <iostream>

#define RadianToDegrees(angleRadians) ((angleRadians) * 180 / M_PI)

AutonSelector_ScalePriority::AutonSelector_ScalePriority(int start_pos, std::string FMS_Data, int cube_amount)
{

	std::string fms_data_truc = FMS_Data.substr (0,2);
    std::cout << "What I See: " << fms_data_truc << std::endl;

if(start_pos == tStartingPosition::RIGHT_POS)
{
	if(fms_data_truc.compare(autoConstData.R_R) == 0 || fms_data_truc.compare(autoConstData.L_R) == 0) // R POS RR
	{
	   // AddSequential(new FromMiddlePos_ToRightScale());
	    std::cout << FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength() << std::endl;
	    AddParallel(new ReleaseIntake());
	    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength()-1.0)); // ADDED, NOT NORMAL
//	    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength()-1.1));

	    AddSequential(new PathExecuter(FromRightPos_ToRightScalePath::GetInstance(), false));
	//    AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0)); // ADDED, NOT NORMAL
	//    AddSequential(new WaitCommand(0.5));
	    AddSequential(new AutoIntake(-0.4, 0.3));
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    AddSequential(new TurnPosition(160, 0.5));
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.2));
	 //   AddSequential(new PathExecuter(FromRightScale_ToRightFirstCubePath::GetInstance(), false));
	    								//    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.5));
	    AddSequential(new AutoDrive(41, 150, 0, 100, 160));
	//    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromRightFirstCube_ToRightScalePath::GetInstance()->GetTimeLength()-1.0));
	    								//    AddParallel(new AutoIntake(INTAKE_SLOW_PERCENT, 5.0));
	    AddSequential(new AutoDrive(-44, 150, 0, 100, 160));


//	    AddSequential(new PathExecuter(FromRightFirstCube_ToRightScalePath::GetInstance(), true));
	    AddSequential(new TurnPosition(40, 0.5));
	    AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0)); // ADDED, NOT NORMAL
//	    AddSequential(new WaitCommand(0.2));
	    AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
//	    AddSequential(new AutoDrive(-15, 150, 0, 70));
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    AddSequential(new TurnPosition(135, 0.5));
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 10.0));
	    AddSequential(new AutoDrive(50, 150, 0, 100, 135));
	    AddSequential(new AutoDrive(-50, 150, 0, 100, 135));

	    AddSequential(new TurnPosition(40, 0.5));
	    AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
	    AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.3));
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	 //   AddSequential(new PathExecuter(FromRightScale_ToRightSecondCubePath::GetInstance(), false));


	}

	if(fms_data_truc.compare(autoConstData.R_L) == 0 || fms_data_truc.compare(autoConstData.L_L) == 0) // R POS RL
	{

		AddSequential(new PathExecuter(FromMiddlePos_ToLeftScaleDumpPath::GetInstance(), false));
		AddParallel(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
		AddSequential(new AutoDrive(-60, 150, 0, 100, RadianToDegrees(FromMiddlePos_ToLeftScaleDumpPath::GetInstance()->GetEndHeading())));
		AddSequential(new TurnPositionMagic(195, 1.0, 150, 90));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
		AddSequential(new AutoDrive(70, 150, 0, 100, 195));

		AddSequential(new AutoDrive(-10, 150, 0, 100, 195));
		AddSequential(new TurnPositionMagic(60, 1.0, 150, 90));
	//	AddSequential(new TurnPositionMagic(90, 0.5, 150, 90));
	//	AddSequential(new TurnPosition(90, 0.5));
		AddSequential(new AutoDrive(70, 150, 0, 100, 60));
		AddParallel(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
		AddSequential(new AutoDrive(-65, 150, 0, 100, 60));
		AddSequential(new TurnPositionMagic(180, 1.0, 150, 90));
		AddSequential(new AutoDrive(15, 150, 0, 100, 200));

//		AddSequential(new PathExecuter(FromRightPos_ToLeftScalePath_Part1::GetInstance(), false));
//
//		AddSequential(new PathExecuter(FromRightPos_ToLeftScalePath_Part2::GetInstance(), false));
//		AddSequential(new DriveLineVelocity(75, 75, FromRightPos_ToLeftScalePath_Part2::GetInstance()->GetEndHeading(), 300));
//		AddSequential(new PathExecuter(FromRightPos_ToLeftScalePath_Part3::GetInstance(), false));

//	    if(OI::GetInstance()->GetSw3()) // 118 special mode activated
//	    {
//			AddParallel(new ReleaseIntake());
//			AddSequential(new PathExecuter(FromRightPos_ToLeftScale118Path::GetInstance(), false)); //add me pls
//			AddSequential(new TurnPosition(270, 0.5));
//			AddSequential(new AutoSetElevator(ELEVATOR_DOUBLE_STACK, 0.0));
//			AddSequential(new WaitCommand(0.5));
//			AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
//			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
//			AddSequential(new AutoDrive(-15, 150, 0, RadianToDegrees(FromRightPos_ToLeftScale118Path::GetInstance()->GetEndHeading())));
////
//	    }
//	    else //normal left scale case
//	    {
//			AddParallel(new ReleaseIntake());
//			AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromRightPos_ToLeftScalePath::GetInstance()->GetTimeLength()-0.8)); // ADDED, NOT NORMALs
//			AddSequential(new PathExecuter(FromRightPos_ToLeftScalePath::GetInstance(), false)); // add pls
//			AddSequential(new AutoIntake(-0.4, 0.3));
//			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
//			AddSequential(new TurnPosition(202, 1.0));
//			AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.2));
//
//			AddSequential(new AutoDrive(52, 150, 0, 202));
//			AddSequential(new AutoDrive(-5, 150, 0, 202));
//
//			AddSequential(new TurnPosition(0, 1.0));
//			AddParallel(new AutoIntake(INTAKE_SLOW_PERCENT, 5.2));
//			AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.2)); // ADDED, NOT NORMAL
//			AddSequential(new AutoDrive(40, 150, 0, 0));
//			AddSequential(new AutoIntake(-0.15, 0.7));
//			AddSequential(new AutoDrive(-15, 150, 0, 0));
//			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
//
//
//	    }


	}
}





}

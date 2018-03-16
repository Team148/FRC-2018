#include <Commands/Auto/AutoCommandGroups/AutonSelector_Hybrid.h>
#include "../../AutoPaths/PathExecuter.h"
#include "./Paths/FakeStraightPath.h"
#include "./Paths/FromMiddlePos_ToLeftSwitchPath.h"
#include "./Paths/FromRightPos_ToLeftSwitchPath.h"
#include "./Paths/FromRightPos_ToLeftSwitchPathReversed.h"
#include "./Paths/FromRightPos_ToRightScalePath.h"
#include "./Paths/FromRightScale_ToRightFirstCubePath.h"
#include "./Paths/FromRightScale_ToRightSecondCubePath.h"
#include "./Paths/FromMiddlePos_ToRightSwitchPath.h"
#include "./Paths/FromRightSecondCube_ToRightScalePath.h"
#include "../../AutoPaths/PathExecuter.h"


#include "./Paths/GoStraightPath.h"
#include "../TurnPosition.h"
#include "../AutoIntake.h"
#include "../AutoSetElevator.h"
#include "../AutoDrive.h"
#include <iostream>



AutonSelector_Hybrid::AutonSelector_Hybrid(int start_pos, std::string FMS_Data, int cube_amount)
{

	std::string fms_data_truc = FMS_Data.substr (0,2);


if(start_pos == tStartingPosition::RIGHT_POS)
{
	if(fms_data_truc.compare(autoConstData.R_R) == 0) // R POS RR
	{

	    //drives to scale and scores in scale, grabs cube from behind and scores in switch, then a second in the scale.

	    AddParallel(new AutoIntake(OUTTAKE_MAX_PERCENT, 0.7));
	    	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 2.1));
	    	AddSequential(new PathExecuter(FromRightPos_ToRightScalePath::GetInstance(),false));
//	    	AddSequential(new WaitCommand(0.3));
	    	AddSequential(new AutoIntake(OUTTAKE_PERCENT, 1.0));
	    //	 scored first cube in scale, now grabbing next cube
	    	AddParallel(new AutoDrive(-17, 150, 0, 0));
	    	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    	AddSequential(new TurnPosition(-200.0, 2.0));
	    	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
	    	AddSequential(new PathExecuter(FromRightScale_ToRightFirstCubePath::GetInstance(), false));
	    	AddSequential(new AutoDrive(48, 80, 0, 165));
	    	AddSequential(new AutoDrive(-5, 150, 0, 165));
	    	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	    	AddSequential(new AutoDrive(10, 150, 0, 160));
	    	AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 1.5));
	    	AddSequential(new AutoDrive(-20, 150, 0, 160));
	    	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    	//scored in switch */
/*
	    	AddParallel(new AutoSetElevator(ELEVATOR_ZERO , 0.0));
//	    	AddSequential(new AutoDrive(-24, 150, 0, 170));
	    	AddSequential(new TurnPosition(-80.0));
	    	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
	    	AddSequential(new AutoDrive(48, 100, 0, 90));
	    	// picked up second cube

	    	AddSequential(new TurnPosition(-140.0));
	    	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	    	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 1.0));
	    	AddSequential(new FromRightSecondCube_ToRightScale());
	    	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));
	    	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
*/
	    	// scored in scale

	}

	if(fms_data_truc.compare(autoConstData.R_L) == 0) // R POS RL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;



	    	// score in right switch, grab cube then score in scale.

//	    	AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 0.25));
////	    	AddSequential(new AutoIntake(INTAKE_FAST_PERCENT, 0.15));
//	    	AddSequential(new FromRightPos_ToRightSwitch()); // need to add
//	    //	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
//	    	AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 2.0));
//	    	AddSequential(new AutoDrive(-15, 150,0));
//	    //	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
//	    	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
//	    	AddSequential(new AutoDrive(20, 150,0));
//	    	AddSequential(new AutoDrive(-20, 150,0));
//	    	AddSequential(new TurnPosition(-60.0));
//	    //	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 2.5));
//	    	AddSequential(new FromRightFirstCube_ToLeftScale());
//	    	AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 1.0));
//	    	AddSequential(new AutoDrive(-15, 50,0));
//	    //	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));


	    AddParallel(new AutoIntake(OUTTAKE_MAX_PERCENT, 0.7));
	    AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, 2.7));
//		AddSequential(new FromRightPos_ToRightSwitch()); // need to add

		AddSequential(new AutoIntake(-0.40, 2.0));
		AddSequential(new AutoDrive(-15, 150,0 , 179));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 4.0));
		AddSequential(new AutoDrive(15, 100,0, 179));
		AddSequential(new AutoDrive(-10, 150, 0, 179));
		AddSequential(new TurnPosition(-95.0, 1.0));
		AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 1.6));
//		AddSequential(new FromRightFirstCube_ToLeftScale());
	//	AddSequential(new TurnPosition(-10.0));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 1.0));
		AddSequential(new AutoDrive(-25, 50, 0, Drivetrain::GetInstance()->getRobotPathHeading()));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

	}
	if(fms_data_truc.compare(autoConstData.L_R) == 0) // R POS LR
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;

	    AddParallel(new AutoIntake(OUTTAKE_MAX_PERCENT, 0.7));
		AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 2.1));
//		AddSequential(new FromRightPos_ToRightScale());
//		AddSequential(new WaitCommand(0.7));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 1.0));
		AddParallel(new AutoDrive(-17, 150, 0, 0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddSequential(new TurnPosition(-200, 2.0));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 4.0));
		//AddSequential(new FromRightScale_ToFirstCube());
		AddSequential(new AutoDrive(30, 80, 0, 165));
		AddSequential(new AutoDrive(-15, 100, 0, 165));
		AddSequential(new TurnPosition(-97.0, 1.0));
		AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, 1.5));
//		AddSequential(new FromRightFirstCube_ToLeftSwitch());
//		AddSequential(new WaitCommand(0.5));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 2.0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

	}
	if(fms_data_truc.compare(autoConstData.L_L) == 0) // R POS LL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;

		// drives to left switch first from right pos, scores switch, then grabs cube to score in scale

	    AddParallel(new AutoIntake(OUTTAKE_MAX_PERCENT, 0.7));
		AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, 3.25));
//		AddSequential(new FromRightPos_ToLeftSwitch()); // need to add
		AddSequential(new WaitCommand(1.0));
		AddSequential(new AutoIntake(-0.40, 1.0));
		AddSequential(new AutoDrive(-20, 150,0, 180));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
		AddSequential(new AutoDrive(25, 150, 0, 180));
		AddSequential(new AutoDrive(-7.5, 150, 0, 180));
		AddSequential(new TurnPosition(-95.0, 1.0));
		AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.6));
//		AddSequential(new FromLeftSwitch_ToLeftScale());
	//	AddSequential(new TurnPosition(-25.0));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 2.0));
		AddSequential(new AutoDrive(-25, 150, 0, 0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));


	}
}





}
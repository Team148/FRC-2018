#include <Commands/Auto/AutoCommandGroups/AutonSelector_Hybrid.h>
#include "../../AutoPaths/PathExecuter.h"
#include "./Paths/FakeStraightPath.h"
#include "./Paths/FromRightPos_ToLeftSwitchPath.h"
#include "./Paths/FromRightPos_ToRightSwitchPath.h"
#include "./Paths/FromRightPos_ToLeftSwitchPathReversed.h"
#include "./Paths/FromLeftSwitch_ToLeftScalePathReversed.h"
#include "./Paths/FromRightFirstCube_ToLeftSwitchPathReversed.h"
#include "./Paths/FromRightPos_ToRightScalePath.h"
#include "./Paths/FromRightScale_ToRightFirstCubePath.h"
#include "./Paths/FromRightFirstCube_ToLeftScalePath.h"
#include "./Paths/FromRightScale_ToRightSecondCubePath.h"
#include "./Paths/FromRightSecondCube_ToRightScalePath.h"
#include "./Paths/FromRightFirstCube_ToLeftSwitchPath.h"
#include "./Paths/FromLeftSwitch_ToLeftScalePath.h"
#include "./Paths/FromRightPos_ToLeftSwitchPath.h"
#include "./Paths/FromRightPos_ToRightScalePath.h"
#include "../../AutoPaths/PathExecuter.h"


#include "./Paths/GoStraightPath.h"
#include "../TurnPosition.h"
#include "../AutoIntake.h"
#include "../AutoSetElevator.h"
#include "../AutoDrive.h"
#include <iostream>
#include "math.h"

#define RadianToDegrees(angleRadians) ((angleRadians) * 180 / M_PI)



AutonSelector_Hybrid::AutonSelector_Hybrid(int start_pos, std::string FMS_Data, int cube_amount)
{

	std::string fms_data_truc = FMS_Data.substr (0,2);


if(start_pos == tStartingPosition::RIGHT_POS)
{
	if(fms_data_truc.compare(autoConstData.R_R) == 0) // R POS RR
	{

	    //drives to scale and scores in scale, grabs cube from behind and scores in switch, then a second in the scale.
//		AddParallel(new AutoIntake(OUTTAKE_MAX_PERCENT, 0.2));
		AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength()-0.8)); // ADDED, NOT NORMAL
	    AddSequential(new PathExecuter(FromRightPos_ToRightScalePath::GetInstance(), false));
//	    AddSequential(new WaitCommand(0.5));
	    AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.3));
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    //Scored First Cube
	    AddSequential(new TurnPosition(RadianToDegrees(FromRightScale_ToRightFirstCubePath::GetInstance()->GetStartHeading()), 0.5));
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, FromRightScale_ToRightFirstCubePath::GetInstance()->GetTimeLength()+3.0));
	    AddSequential(new PathExecuter(FromRightScale_ToRightFirstCubePath::GetInstance(), false));
		AddSequential(new AutoDrive(-10, 150, 0, 160));
		AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
		AddSequential(new AutoDrive(10, 150, 0,  160));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 0.3));
		//Scored Second Cube
		AddSequential(new AutoDrive(-20, 150, 0,  160));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddSequential(new TurnPosition(135, 0.5));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
		AddSequential(new AutoDrive(35, 150, 0,  135));
		//Grabbed Third Cube
		AddSequential(new AutoDrive(-10, 150, 0,  135));
		AddSequential(new TurnPosition(170, 0.5));
		AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
		AddSequential(new AutoDrive(10, 150, 0,  180));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 1.5));
		AddSequential(new AutoDrive(-10, 150, 0,  180));
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




//	    AddParallel(new AutoIntake(OUTTAKE_MAX_PERCENT, 0.7));
	    AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, FromRightPos_ToRightSwitchPath::GetInstance()->GetTimeLength()-1.0));
	    AddSequential(new PathExecuter(FromRightPos_ToRightSwitchPath::GetInstance(), false));
	    AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 0.3));
		AddSequential(new AutoDrive(-15, 150,0 , 179));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 4.0));
		AddSequential(new AutoDrive(15, 100,0, 179));
		AddSequential(new AutoDrive(-10, 150, 0, 179));
		AddSequential(new TurnPosition(RadianToDegrees(FromRightFirstCube_ToLeftScalePath::GetInstance()->GetStartHeading()), 0.5));

		AddSequential(new PathExecuter(FromRightFirstCube_ToLeftScalePath::GetInstance(), false));
		AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
	//	AddSequential(new TurnPosition(-10.0));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 0.5));
	//	AddSequential(new AutoDrive(-25, 50, 0, Drivetrain::GetInstance()->getRobotPathHeading()));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

	}
	if(fms_data_truc.compare(autoConstData.L_R) == 0) // R POS LR
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;

//		AddParallel(new AutoIntake(OUTTAKE_MAX_PERCENT, 0.2));
		AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength()-0.8)); // ADDED, NOT NORMAL
		AddSequential(new PathExecuter(FromRightPos_ToRightScalePath::GetInstance(), false));
//		AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0)); // ADDED, NOT NORMAL

//	    AddSequential(new WaitCommand(0.5));
		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.3));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		//Scored First Cube
	    AddSequential(new TurnPosition(RadianToDegrees(FromRightScale_ToRightFirstCubePath::GetInstance()->GetStartHeading()), 0.5));
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, FromRightScale_ToRightFirstCubePath::GetInstance()->GetTimeLength()+5.0));
	    AddSequential(new PathExecuter(FromRightScale_ToRightFirstCubePath::GetInstance(), false));
		//Grabbed second cube
	 //   AddSequential(new AutoDrive(-5, 80, 0, 180));
		AddSequential(new PathExecuter(FromRightFirstCube_ToLeftSwitchPathReversed::GetInstance(), true)); // add reversed path here

		AddSequential(new TurnPosition(225, 0.7));
		AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
		AddSequential(new AutoDrive(25, 80, 0, 200));
		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
		AddSequential(new AutoDrive(-20, 100, 0, 200));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		//Scored second cube

		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 4.0));
		AddSequential(new AutoDrive(25, 80, 0, 200));
		AddSequential(new AutoDrive(-20, 100, 0, 200));
		//Grabbed third cube

		AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
		AddSequential(new AutoDrive(25, 80, 0, 200));
		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
		AddSequential(new AutoDrive(-20, 100, 0, 200));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		//Scored third cube


	}
	if(fms_data_truc.compare(autoConstData.L_L) == 0) // R POS LL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;

		// drives to left switch first from right pos, scores switch, then grabs cube to score in scale

//	    AddParallel(new AutoIntake(OUTTAKE_MAX_PERCENT, 0.7));
		AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, FromRightPos_ToLeftSwitchPath::GetInstance()->GetTimeLength()-0.8));
		AddSequential(new PathExecuter(FromRightPos_ToLeftSwitchPath::GetInstance(), false)); // need to add
		AddSequential(new TurnPosition(RadianToDegrees(FromRightPos_ToLeftSwitchPath::GetInstance()->GetEndHeading())+25, 0.7));
		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 1.0));
		AddSequential(new AutoDrive(-15, 150,0, RadianToDegrees(FromRightPos_ToLeftSwitchPath::GetInstance()->GetEndHeading())+25));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 6.0));
		AddSequential(new AutoDrive(20, 150, 0, RadianToDegrees(FromRightPos_ToLeftSwitchPath::GetInstance()->GetEndHeading())+25));
		AddSequential(new AutoDrive(-10, 150, 0, RadianToDegrees(FromRightPos_ToLeftSwitchPath::GetInstance()->GetEndHeading())+25));
		//AddSequential(new TurnPosition(RadianToDegrees(FromLeftSwitch_ToLeftScalePath::GetInstance()->GetStartHeading()), 1.0));

		AddSequential(new PathExecuter(FromLeftSwitch_ToLeftScalePathReversed::GetInstance(), true));
		AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
	//	AddSequential(new TurnPosition(-25.0));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 2.0));
	//	AddSequential(new AutoDrive(-25, 150, 0, 0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));


	}
}





}
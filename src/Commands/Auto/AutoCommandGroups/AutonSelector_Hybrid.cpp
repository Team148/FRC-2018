#include <Commands/Auto/AutoCommandGroups/AutonSelector_Hybrid.h>


#include "CommonCommandHeaders.h"




AutonSelector_Hybrid::AutonSelector_Hybrid(int start_pos, std::string FMS_Data, int cube_amount)
{

	std::string fms_data_truc = FMS_Data.substr (0,2);


if(start_pos == tStartingPosition::RIGHT_POS)
{
	if(fms_data_truc.compare(autoConstData.R_R) == 0) // R POS RR
	{

	    //drives to scale and scores in scale, grabs cube from behind and scores in switch, then a second in the scale.
	    AddSequential(new FromRightPos_ToRightScaleGroup());
	    //Scored First Cube
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 4.0));
	    AddSequential(new AutoDrive(44, 100, 0, 100, 160));

	    //   AddSequential(new PathExecuter(FromRightScale_ToRightFirstCubePath::GetInstance(), false));
		AddSequential(new AutoDrive(-5, 150, 0, 120, 160));
		AddParallel(new AutoIntake(INTAKE_SLOW_AUTO_PERCENT, 4.0));
		AddSequential(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, 0.0));
		AddSequential(new AutoDrive(10, 150, 0, 120,  160));
		AddSequential(new AutoIntake(-0.45, 0.5));
		//Scored Second Cube
		AddSequential(new AutoDrive(-25, 100, 0, 100, 160));
		AddParallel(new TurnPositionMagic(135, 0.5, 150, 150));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	//	AddSequential(new TurnPositionMagic(130, 0.5, 150, 150));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
		AddSequential(new AutoDrive(37, 100, 0, 100, 135));
		AddSequential(new AutoDrive(-10, 150, 0, 120, 135));
		//Grabbed Third Cube

		AddSequential(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, 0.0));
		AddSequential(new TurnPositionMagic(165, 0.5, 150, 150));

		AddSequential(new AutoDrive(15, 150, 0, 120, 165));
		AddParallel(new AutoIntake(-0.45, 0.5));
		AddSequential(new AutoDrive(-10, 150, 0, 120, 165));
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
	    AddSequential(new FromRightPos_ToRightSwitchGroup());

	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
	    	AddSequential(new AutoDrive(25, 100, 0, 100, 120));
		AddSequential(new AutoDrive(-45, 150, 0, 120, 120));
		AddSequential(new TurnPosition(RadianToDegrees(FromRightFirstCube_ToLeftScalePath::GetInstance()->GetStartHeading()), 0.5));
		AddParallel(new AutoIntake(INTAKE_SLOW_AUTO_PERCENT, 2.5));
		AddSequential(new PathExecuter(FromRightFirstCube_ToLeftScalePath::GetInstance(), false));
		AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH-2500, 0.0));
	//	AddSequential(new TurnPosition(-10.0));
		AddSequential(new AutoIntake(-.40, 0.3));
	//	AddSequential(new AutoDrive(-25, 50, 0, Drivetrain::GetInstance()->getRobotPathHeading()));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

	}
	if(fms_data_truc.compare(autoConstData.L_R) == 0) // R POS LR
	{


	    std::cout << "What I See: " << fms_data_truc << std::endl;

	    AddSequential(new FromRightPos_ToLeftSwitchGroup());

	    AddSequential(new TurnPosition(180, 0.4));
		AddSequential(new AutoDrive(-15, 150,0, 120, 180));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 4.0));
		AddSequential(new AutoDrive(25, 120, 0, 90, 180));
		AddSequential(new AutoDrive(-9, 150, 0, 120, 180));
		//AddSequential(new TurnPosition(RadianToDegrees(FromLeftSwitch_ToLeftScalePath::GetInstance()->GetStartHeading()), 1.0));
		AddParallel(new AutoIntake(INTAKE_HOLD_AUTO_PERCENT, 5.0));
		AddSequential(new TurnPosition(270,0.5));
//		AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromLeftSwitch_ToRightScalePath::GetInstance()->GetTimeLength()-0.2));
		AddSequential(new PathExecuter(FromLeftSwitch_ToRightScalePath::GetInstance(),false));
		AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
		AddSequential(new TurnPositionMagic(40, 0.5,120,90));
		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.3));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));


	    /*
		AddParallel(new ReleaseIntake());
		AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength()-1.0)); // ADDED, NOT NORMAL
		AddSequential(new PathExecuter(FromRightPos_ToRightScalePath::GetInstance(), false));
//		AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0)); // ADDED, NOT NORMAL

//	    AddSequential(new WaitCommand(0.5));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 0.3));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		//Scored First Cube
//	    AddSequential(new TurnPosition(RadianToDegrees(FromRightScale_ToRightFirstCubePath::GetInstance()->GetStartHeading()), 0.5));
//	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, FromRightScale_ToRightFirstCubePath::GetInstance()->GetTimeLength()+5.0));
//	    AddSequential(new PathExecuter(FromRightScale_ToRightFirstCubePath::GetInstance(), false));

		AddSequential(new TurnPosition(165, 0.5));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
		AddSequential(new AutoDrive(41, 150, 0, 160));

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
		//Scored third cube */
	}
	if(fms_data_truc.compare(autoConstData.L_L) == 0) // R POS LL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;

		// drives to left switch first from right pos, scores switch, then grabs cube to score in scale
	    AddSequential(new FromRightPos_ToLeftSwitchGroup());


		AddSequential(new AutoDrive(-15, 150,0, 100, 180));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 6.0));
		AddSequential(new AutoDrive(20, 150, 0, 100, 180));
		AddSequential(new AutoDrive(-10, 150, 0, 100, 180));
		//AddSequential(new TurnPosition(RadianToDegrees(FromLeftSwitch_ToLeftScalePath::GetInstance()->GetStartHeading()), 1.0));
		AddParallel(new AutoIntake(INTAKE_SLOW_AUTO_PERCENT, 3.0));
//		AddSequential(new PathExecuter(FromLeftSwitch_ToLeftScalePathReversed::GetInstance(), true));
		AddSequential(new TurnPosition(225, 0.5));
		AddSequential(new AutoDrive(-135, 150, 0, 100, 225));
		AddSequential(new TurnPosition(275, 0.5));
		AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
		AddSequential(new AutoDrive(3, 150, 0, 100, 275));

		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
		AddSequential(new AutoDrive(-12, 150, 0, 100, 275));

	//	AddSequential(new AutoDrive(-25, 150, 0, 0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));


	}
}





}

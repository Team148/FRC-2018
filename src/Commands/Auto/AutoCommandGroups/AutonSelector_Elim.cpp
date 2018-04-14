#include <Commands/Auto/AutoCommandGroups/AutonSelector_Elim.h>


#include "CommonCommandHeaders.h"



AutonSelector_Elim::AutonSelector_Elim(int start_pos, std::string FMS_Data, int cube_amount)
{

	std::string fms_data_truc = FMS_Data.substr (0,2);


if(start_pos == tStartingPosition::RIGHT_POS)
{
	if(fms_data_truc.compare(autoConstData.R_R) == 0) // R POS RR
	{

		   // AddSequential(new FromMiddlePos_ToRightScale());
		std::cout << "Two Scale One Switch Attempt" << std::endl;
		//two scale one switch
		    //std::cout << FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength() << std::endl;
			AddSequential(new FromRightPos_ToRightScaleGroup());

		    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.2));
		    AddSequential(new AutoDrive(43, 150, 0, 100, 160));
		    AddSequential(new AutoDrive(-45, 150, 0, 100, 160));
		    AddSequential(new TurnPosition(40, 0.5));
		    AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0)); // ADDED, NOT NORMAL
		    AddSequential(new AutoIntake(-0.25, 0.5));
		    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		    AddSequential(new TurnPosition(135, 0.5));
		    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 10.0));
		    AddSequential(new AutoDrive(58, 150, 0, 100, 135));
		    /* Normal Back to Scale Attempt
		    AddSequential(new AutoDrive(-50, 150, 0, 135));
		    AddSequential(new TurnPosition(40, 0.5));
		    AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
		    AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.3));
		    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0)); //end normal scale */

		    //Score in Switch

			AddSequential(new AutoDrive(-5, 150, 0, 100, 135));
			AddSequential(new TurnPosition(170, 0.5));
			AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
			AddSequential(new AutoDrive(10, 150, 0, 100, 170));
			AddSequential(new AutoIntake(-0.35, 0.3));
			AddSequential(new AutoDrive(-12, 150, 0, 100, 135));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		     //*/

	}

	if(fms_data_truc.compare(autoConstData.R_L) == 0) // R POS RL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;
//triple tap the switch
	    std::cout << "Triple Switch Attempt" << std::endl;
	    AddParallel(new ReleaseIntake());
	    AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, FromRightPos_ToRightSwitchPath::GetInstance()->GetTimeLength()-1.0));
	    AddSequential(new PathExecuter(FromRightPos_ToRightSwitchPath::GetInstance(), false));
	    AddSequential(new TurnPosition(170, 0.3));
	    //AddSequential(new AutoIntake(INTAKE_SLOW_AUTO_PERCENT, 0.5));
	    AddSequential(new AutoIntake(-0.35, 0.5));
	    AddSequential(new AutoDrive(-15, 150,0 , 100, 175));
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 4.0));
	    AddSequential(new AutoDrive(20, 100,0, 100, 175));
	    //picked up second cube
	    AddSequential(new AutoDrive(-5, 150, 0, 100, 175));
	    AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	    AddSequential(new AutoDrive(10, 150, 0, 100, 175));
	    AddSequential(new AutoIntake(-0.35, 0.5));
	    //Scored Second Cube
	    AddSequential(new AutoDrive(-25, 150, 0, 100,  175));
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    AddSequential(new TurnPosition(150, 0.5));
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
	    AddSequential(new AutoDrive(30, 150, 0, 100, 150));
	    AddSequential(new TurnPosition(130, 0.5));
	    //Grabbed Third Cube
	    AddSequential(new AutoDrive(-5, 150, 0, 100, 150));
	    AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	    AddSequential(new TurnPosition(165, 0.3));

	    AddSequential(new AutoDrive(5, 150, 0, 100, 165));
	    AddSequential(new AutoIntake(-0.35, 0.3));
	    AddSequential(new AutoDrive(-10, 150, 0, 100, 165));
	    //scored third cube
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    AddSequential(new TurnPosition(90, 0.5));
	    AddSequential(new AutoDrive(35, 150, 0, 100, 90));
	    AddSequential(new TurnPosition(180, 0.5));
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
	    AddSequential(new AutoDrive(15, 150, 0, 100, 180));
	    //grab fourth cube

	}
	if(fms_data_truc.compare(autoConstData.L_R) == 0) // R POS LR
	{


	    std::cout << "What I See: " << fms_data_truc << std::endl;
	    std::cout << "Triple Scale Attempt" << std::endl;
	//	    std::cout << FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength() << std::endl;
		    AddParallel(new ReleaseIntake());
		    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromRightPos_ToRightScalePath::GetInstance()->GetTimeLength()-1.0)); // ADDED, NOT NORMAL
		    AddSequential(new PathExecuter(FromRightPos_ToRightScalePath::GetInstance(), false));
		    AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 0.3));
		    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		    AddSequential(new TurnPosition(160, 0.5));
		    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.2));
		    AddSequential(new AutoDrive(41, 150, 0, 100, 160));
		    AddSequential(new AutoDrive(-44, 150, 0, 100, 160));
		    AddSequential(new TurnPosition(40, 0.5));
		    AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0)); // ADDED, NOT NORMAL
		    AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
		    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		    AddSequential(new TurnPosition(135, 0.5));
		    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 10.0));
		    AddSequential(new AutoDrive(50, 150, 0, 100, 135));
		    AddSequential(new AutoDrive(-50, 150, 0, 100, 135));
		    AddSequential(new TurnPosition(40, 0.5));
		    AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
		    AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.3));
		    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

	}
	if(fms_data_truc.compare(autoConstData.L_L) == 0) // R POS LL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;
	    std::cout << "Reach Around Attempt" << std::endl;
		AddParallel(new ReleaseIntake());
		AddSequential(new WaitCommand(0.0));
		AddSequential(new PathExecuter(FromRightPos_ToLeftScale118Path::GetInstance(), false)); //add me pls
		AddSequential(new TurnPosition(270, 0.5));
		AddSequential(new AutoSetElevator(ELEVATOR_DOUBLE_STACK, 0.0));
		AddSequential(new WaitCommand(0.5));
		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddSequential(new AutoDrive(-15, 150, 0, 100, RadianToDegrees(FromRightPos_ToLeftScale118Path::GetInstance()->GetEndHeading())));
	}
}





}

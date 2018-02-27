#include "AutonSelectorGroup.h"
#include "../../AutoPaths/FromRightPos_ToRightScale.h"
#include "../../AutoPaths/FromRightPos_ToRightSwitch.h"
#include "../../AutoPaths/FromRightPos_ToLeftSwitch.h"
#include "../../AutoPaths/FromRightScale_ToFirstCube.h"
#include "../../AutoPaths/FromRightSecondCube_ToRightScale.h"
#include "../../AutoPaths/FromRightScale_ToRightFirstCube.h"
#include "../../AutoPaths/FromRightFirstCube_ToLeftScale.h"
#include "../../AutoPaths/FromLeftSwitch_ToLeftScale.h"
#include "../../AutoPaths/FromRightFirstCube_ToLeftSwitch.h"
#include "../TurnPosition.h"
#include "../AutoIntake.h"
#include "../AutoSetElevator.h"
#include "../AutoDrive.h"
#include <iostream>



AutonSelectorGroup::AutonSelectorGroup(int start_pos, std::string FMS_Data, int cube_amount)
{


//	fms_data_truc[1] = FMS_Data[1];
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	std::string fms_data_truc = FMS_Data.substr (0,2);


	if(fms_data_truc.compare(autoConstData.R_R) == 0)
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;
	}


// R POS RR

//drives to scale and scores in scale, grabs cube from behind and scores in switch, then a second in the scale.
/*
	AddSequential(new AutoIntake(OUTTAKE_PERCENT, 0.25));
	AddSequential(new AutoIntake(INTAKE_FAST_PERCENT, 0.5));
	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 2.8));
	AddSequential(new FromRightPos_ToRightScale());

	AddSequential(new AutoIntake(OUTTAKE_PERCENT, 1.0));
//	 scored first cube in scale, now grabbing next cube

	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

	AddSequential(new TurnPosition(-195.0));
	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
//	AddSequential(new FromRightScale_ToRightFirstCube());
	AddSequential(new AutoDrive(100, 150));
	AddSequential(new AutoDrive(-5, 150));
	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
//	AddSequential(new AutoDrive(24, 150));
	AddSequential(new AutoIntake(OUTTAKE_PERCENT, 1.0));
	//scored in switch

	AddParallel(new AutoSetElevator(ELEVATOR_ZERO , 0.0));
//	AddSequential(new AutoDrive(-24, 150));
//	AddSequential(new TurnPosition(-75.0));
//	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
//	AddSequential(new AutoDrive(48, 150));
	// picked up second cube

	AddSequential(new TurnPosition(-135.0));
	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 1.0));
	AddSequential(new FromRightSecondCube_ToRightScale());
	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));
	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

	// scored in scale
*/
// R POS RL
//
//	AddSequential(new AutoDrive(20, 150,0));
//	AddSequential(new WaitCommand(10.0));
//	AddSequential(new AutoDrive(100, 150,0,1.5707));
	// score in right switch, grab cube then score in scale.
/*
	AddSequential(new AutoIntake(OUTTAKE_PERCENT, 0.25));
	AddSequential(new AutoIntake(INTAKE_FAST_PERCENT, 0.15));
	AddSequential(new FromRightPos_ToRightSwitch()); // need to add
//	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	AddSequential(new AutoIntake(OUTTAKE_PERCENT, 2.0));
	AddSequential(new AutoDrive(-15, 150,0));
//	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
	AddSequential(new AutoDrive(20, 150,0));
	AddSequential(new AutoDrive(-20, 150,0));
	AddSequential(new TurnPosition(-60.0));
//	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 2.5));
	AddSequential(new FromRightFirstCube_ToLeftScale());
	AddSequential(new AutoIntake(OUTTAKE_PERCENT, 1.0));
	AddSequential(new AutoDrive(-15, 50,0));
//	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	*/
/*
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 0.25));
		AddSequential(new AutoIntake(INTAKE_FAST_PERCENT, 0.15));
		AddSequential(new FromRightPos_ToRightSwitch()); // need to add
		AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 2.0));
		AddSequential(new AutoDrive(-15, 150,0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
		AddSequential(new AutoDrive(20, 150,0));
		AddSequential(new AutoDrive(-30, 150,0));
		AddSequential(new TurnPosition(-60.0));
		AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 2.5));
		AddSequential(new FromRightFirstCube_ToLeftScale());
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 1.0));
		AddSequential(new AutoDrive(-15, 50,0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
*/
// R POS LR

/*
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 0.25));
		AddSequential(new AutoIntake(INTAKE_FAST_PERCENT, 0.15));
		AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 3.0));
		AddSequential(new FromRightPos_ToRightScale());
		AddSequential(new WaitCommand(0.7));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 1.0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddSequential(new TurnPosition(-195));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
		//AddSequential(new FromRightScale_ToFirstCube());
		AddSequential(new AutoDrive(80, 150,0));
		AddSequential(new AutoDrive(-20, 150,0));
		AddSequential(new TurnPosition(-97.0));
		AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, 1.5));
		AddSequential(new FromRightFirstCube_ToLeftSwitch());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 2.0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
*/
// R POS LL

	// drives to left switch first from right pos, scores switch, then grabs cube to score in scale
/*
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 0.25));
		AddSequential(new AutoIntake(INTAKE_FAST_PERCENT, 0.15));
		AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, 3.6));
		AddSequential(new FromRightPos_ToLeftSwitch()); // need to add
		AddSequential(new WaitCommand(0.5));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 0.5));
		AddSequential(new AutoDrive(-20, 150,0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
		AddSequential(new AutoDrive(25, 150,0));
		AddSequential(new AutoDrive(-7.5, 150,0));
		AddSequential(new TurnPosition(-95.0));
		AddSequential(new FromLeftSwitch_ToLeftScale());
		AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new AutoIntake(OUTTAKE_PERCENT, 2.0));
		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

*/

}

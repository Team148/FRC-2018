#include "AutonSelectorGroup.h"
#include "../../AutoPaths/FromRightPos_ToRightScale.h"
#include "../../AutoPaths/FromRightScale_ToFirstCube.h"
#include "../../AutoPaths/FromRightSecondCube_ToRightScale.h"
#include "../TurnPosition.h"
#include "../AutoIntake.h"
#include "../AutoSetElevator.h"
//#include "../AutoDrive.h"



AutonSelectorGroup::AutonSelectorGroup(tStartingPosition start_pos, char* FMS_Data, tCubeAmount cube_amount)
{

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

// R POS RR

//drives to scale and scores in scale, grabs cube from behind and scores in switch, then a second in the scale.

	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 3.0));
	AddSequential(new FromRightPos_ToRightScale());
	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));
//	 scored first cube in scale, now grabbing next cube
	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	AddSequential(new TurnPosition(170.0));
	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
//	AddSequential(new AutoDrive(48, 150));
	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
//	AddSequential(new AutoDrive(24, 150));
	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 1.0));
	//scored in switch

	AddParallel(new AutoSetElevator(ELEVATOR_ZERO , 0.0));
//	AddSequential(new AutoDrive(-24, 150));
	AddSequential(new TurnPosition(-75.0));
	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
//	AddSequential(new AutoDrive(48, 150));
	// picked up second cube

	AddSequential(new TurnPosition(-135.0));
	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 1.0));
	AddSequential(new FromRightSecondCube_ToRightScale());
	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));

	// scored in scale

// R POS RL

	// score in right switch, grab cube then score in scale.

	//	AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, 3.0));
	//	AddSequential(new FromRightPos_ToRightSwitch()); // need to add
	//	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));
	//ADD back up a bit
	//	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	//	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
	//	AddSequential(new TurnPosition(90.0));
	//	AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	//	AddSequential(new FromRightSwitch_ToLeftScale());
	//	AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
	//	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 1.0));

// R POS LR

	//	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 3.0));
	//	AddSequential(new FromRightPos_ToRightScale());
	//	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));

	//	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	//	AddSequential(new TurnPosition(180.0));
	//	AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));

	//	AddSequential(new FromRightScale_ToFirstCube());
	//ADD Back up a bit
	//	AddSequential(new TurnPosition(-80.0));
	//	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	//	AddSequential(new FromRightSwitch_ToLeftSwitch());
	// maybe turn
	//	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));

// R POS LL

	// drives to left switch first from right pos, scores switch, then grabs cube to score in scale

//		AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, 3.0));
////		AddSequential(new FromRightPos_ToLeftSwitch()); // need to add
//		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));
//		//ADD backup a bit
//		AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
//		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
//		//ADD drive forward to grab cube
//		AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
//		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 1.0));
//		AddParallel(new AutoSetElevator(ELEVATOR_ZERO , 0.0));
//		AddSequential(new TurnPosition(100.0));
////		AddSequential(new FromLeftSwitch_ToLeftScale()); // need to add
//		AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
//		AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 1.0));
//		AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));



}

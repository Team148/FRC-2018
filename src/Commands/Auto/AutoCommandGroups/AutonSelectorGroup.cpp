#include "AutonSelectorGroup.h"
#include "../../AutoPaths/FromRightPos_ToRightScale.h"
#include "../../AutoPaths/FromRightScale_ToFirstCube.h"
#include "../TurnPosition.h"
#include "../AutoIntake.h"
#include "../AutoSetElevator.h"


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


	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 3.0));
	AddSequential(new FromRightPos_ToRightScale());
	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));
	AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	AddSequential(new TurnPosition(180.0));
	AddParallel(new AutoIntake(INTAKE_PERCENT, 3.0));
	AddSequential(new FromRightScale_ToFirstCube());
	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 1.0));
	AddParallel(new AutoSetElevator(ELEVATOR_ZERO , 0.0));
	AddSequential(new TurnPosition(-45.0));
	AddParallel(new AutoIntake(INTAKE_PERCENT, 3.0));
	AddSequential(new FromRightScale_ToFirstCube());
	AddSequential(new TurnPosition(-135.0));
	AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
	AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 1.0));
	AddSequential(new FromRightScale_ToFirstCube());
	AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 2.0));




}

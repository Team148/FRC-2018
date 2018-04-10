#include "AutonSelector_SwitchOnly.h"
#include "../../AutoPaths/PathExecuter.h"
#include "./Paths/FromMiddlePos_ToLeftSwitchPath.h"
#include "./Paths/FromMiddlePos_ToRightSwitchPath.h"
#include "./Paths/FromRightSwitchFront_ToLeftScaleBackReversePath.h"

#include "../TurnPosition.h"
#include "../TurnPositionMagic.h"
#include "../AutoIntake.h"
#include "../ReleaseIntake.h"

#include "../AutoSetElevator.h"
#include "../AutoDrive.h"
#include <iostream>



AutonSelector_SwitchOnly::AutonSelector_SwitchOnly(int start_pos, std::string FMS_Data, int cube_amount)
{

	std::string fms_data_truc = FMS_Data.substr (0,2);

//	if(start_pos == tStartingPosition::MIDDLE_POS)
//	{
		if(fms_data_truc.compare(autoConstData.R_R) == 0 || fms_data_truc.compare(autoConstData.R_L) == 0 ) // MIDDLE LINEUP, RIGHT SWITCHES
		{
		//	AddParallel(new ReleaseIntake());
			AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, FromMiddlePos_ToRightSwitchPath::GetInstance()->GetTimeLength()-1.2));
			AddSequential(new PathExecuter(FromMiddlePos_ToRightSwitchPath::GetInstance(), false));
			AddSequential(new AutoIntake(-0.40, 0.5));
			AddSequential(new TurnPositionMagic(65, 0.5, 150, 90));
			AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 2.0));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
			AddSequential(new AutoDrive(15, 150, 0, 100,65));
			AddSequential(new AutoDrive(-15, 150, 0, 100, 65));
			AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
			AddSequential(new TurnPositionMagic(0, 0.5, 150, 90));
			AddSequential(new AutoIntake(-0.40, 0.5));
			AddSequential(new TurnPositionMagic(65, 0.5, 150, 90));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
			AddSequential(new WaitCommand(0.5));
			AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 2.0));
			AddSequential(new AutoDrive(20, 150, 0, 100, 65));
			AddSequential(new AutoDrive(-20, 150, 0, 100, 65));
			AddSequential(new AutoSetElevator(ELEVATOR_SWITCH, 0.0));
			AddSequential(new TurnPositionMagic(0, 0.5, 150, 90));
			AddSequential(new AutoIntake(-0.40, 0.5));
			AddSequential(new TurnPositionMagic(65, 0.5, 150, 90));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
			AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 2.0));
			AddSequential(new AutoDrive(30, 150, 0, 100, 65));
			AddSequential(new PathExecuter(FromRightSwitchFront_ToLeftScaleBackReversePath::GetInstance(), true));

		}
		if(fms_data_truc.compare(autoConstData.L_L) == 0 || fms_data_truc.compare(autoConstData.L_R) == 0 ) // MIDDLE LINEUP, LEFT SWITCHES
		{
			AddParallel(new ReleaseIntake());
			AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, FromMiddlePos_ToLeftSwitchPath::GetInstance()->GetTimeLength()-1.0));
			AddSequential(new PathExecuter(FromMiddlePos_ToLeftSwitchPath::GetInstance(), false));
			AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 2.0));
			AddSequential(new AutoDrive(-10, 150, 0, 100, 0));
			AddSequential(new AutoDrive(-10, 150, 0, 100, 0));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		}
//	}
}


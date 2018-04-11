#include "AutonSelector_BackSwitchOnly.h"
#include "../../AutoPaths/PathExecuter.h"
#include "./Paths/FromMiddlePos_ToLeftSwitchPath.h"
#include "./Paths/FromMiddlePos_ToRightSwitchBackPath.h"
#include "./Paths/FromRightSwitchFront_ToLeftScaleBackReversePath.h"

#include "../TurnPosition.h"
#include "../TurnPositionMagic.h"
#include "../AutoIntake.h"
#include "../ReleaseIntake.h"

#include "../AutoSetElevator.h"
#include "../AutoDrive.h"
#include <iostream>



AutonSelector_BackSwitchOnly::AutonSelector_BackSwitchOnly(int start_pos, std::string FMS_Data, int cube_amount)
{

	std::string fms_data_truc = FMS_Data.substr (0,2);

//	if(start_pos == tStartingPosition::MIDDLE_POS)
//	{
		if(fms_data_truc.compare(autoConstData.R_R) == 0 || fms_data_truc.compare(autoConstData.R_L) == 0 ) // MIDDLE LINEUP, RIGHT SWITCHES
		{
		//	AddParallel(new ReleaseIntake());
			AddParallel(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, FromMiddlePos_ToRightSwitchBackPath::GetInstance()->GetTimeLength()-1.5), 500);
			AddSequential(new PathExecuter(FromMiddlePos_ToRightSwitchBackPath::GetInstance(), false));
			AddSequential(new AutoIntake(-0.40, 0.5));
			AddSequential(new AutoDrive(-20, 150, 0, 100, 180));
			AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 10.0));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0, 500));
			AddSequential(new AutoDrive(25, 150, 0, 100, 180));
			AddSequential(new AutoDrive(-5, 150, 0, 100, 180));
			AddSequential(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, 0.0));
			AddSequential(new AutoDrive(20 , 150, 0, 100, 180));
			AddSequential(new AutoIntake(-0.40, 0.5));
			AddSequential(new AutoDrive(-10, 150, 0, 100, 180));
			AddSequential(new TurnPositionMagic(100, 0.5, 150, 90));
			AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 10.0));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0, 500));
			AddSequential(new AutoDrive(30, 150, 0, 100, 110));
			AddSequential(new TurnPositionMagic(60, 0.5, 150, 90));
			AddSequential(new AutoDrive(50 , 150, 0, 100, 60));


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


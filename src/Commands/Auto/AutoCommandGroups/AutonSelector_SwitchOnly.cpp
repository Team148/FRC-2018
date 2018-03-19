#include "AutonSelector_SwitchOnly.h"
//#include "../../AutoPaths/FromRightPos_ToRightScale.h"
//#include "../../AutoPaths/FromRightPos_ToRightSwitch.h"
//#include "../../AutoPaths/FromRightPos_ToLeftSwitch.h"
//#include "../../AutoPaths/FromRightScale_ToFirstCube.h"
//#include "../../AutoPaths/FromRightSecondCube_ToRightScale.h"
//#include "../../AutoPaths/FromRightScale_ToRightFirstCube.h"
//#include "../../AutoPaths/FromRightFirstCube_ToLeftScale.h"
//#include "../../AutoPaths/FromLeftSwitch_ToLeftScale.h"
//#include "../../AutoPaths/FromRightFirstCube_ToLeftSwitch.h"
//#include "../../AutoPaths/FromMiddlePos_ToLeftSwitch.h"
//#include "../../AutoPaths/FromMiddlePos_ToRightSwitch.h"
//#include "../../AutoPaths/FromMiddlePos_ToRightScale.h"
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

#include "./Paths/GoStraightPath.h"
#include "../TurnPosition.h"
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
			AddParallel(new ReleaseIntake());
			AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, FromMiddlePos_ToRightSwitchPath::GetInstance()->GetTimeLength()-1.0));
			AddSequential(new PathExecuter(FromMiddlePos_ToRightSwitchPath::GetInstance(), false));
			AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 2.0));
			AddSequential(new AutoDrive(-10, 150, 0, 0));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		}
		if(fms_data_truc.compare(autoConstData.L_L) == 0 || fms_data_truc.compare(autoConstData.L_R) == 0 ) // MIDDLE LINEUP, LEFT SWITCHES
		{
			AddParallel(new ReleaseIntake());
			AddParallel(new AutoSetElevator(ELEVATOR_SWITCH, FromMiddlePos_ToLeftSwitchPath::GetInstance()->GetTimeLength()-1.0));
			AddSequential(new PathExecuter(FromMiddlePos_ToLeftSwitchPath::GetInstance(), false));
			AddSequential(new AutoIntake(OUTTAKE_PERCENT_AUTO, 2.0));
			AddSequential(new AutoDrive(-10, 150, 0, 0));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
		}
//	}
}


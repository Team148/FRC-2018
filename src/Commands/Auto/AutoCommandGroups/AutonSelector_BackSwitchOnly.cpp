#include "AutonSelector_BackSwitchOnly.h"
#include "../../AutoPaths/PathExecuter.h"
#include "./Paths/FromMiddlePos_ToLeftSwitchPath.h"
#include "./Paths/FromMiddlePos_ToRightSwitchBackPath.h"

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
			AddParallel(new ReleaseIntake());
		    AddParallel(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, FromMiddlePos_ToRightSwitchBackPath::GetInstance()->GetTimeLength()-1.5));
		    AddSequential(new PathExecuter(FromMiddlePos_ToRightSwitchBackPath::GetInstance(), false, 0, 25));
		    AddSequential(new TurnPositionMagic(140, 0.3,150,150));


		//    AddSequential(new AutoIntake(INTAKE_SLOW_AUTO_PERCENT, 0.2));
		    //Spit
		    AddSequential(new AutoIntake(-0.45, 0.4));

		    //Backup and home elevator

			AddSequential(new AutoDrive(-15, 150, 0, 120, 140));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

		    AddSequential(new TurnPositionMagic(120, 0.5,150,150));

		    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
		    	AddSequential(new AutoDrive(30, 60, 0, 100, 120));
			AddSequential(new AutoDrive(-20, 60, 0, 100, 120));

			AddParallel(new AutoSetElevator(ELEVATOR_SWITCH_AUTO, 0.0));
		    AddSequential(new TurnPositionMagic(140, 0.5,150, 150));


			AddSequential(new AutoDrive(20, 100, 0, 90, 140));
			AddSequential(new AutoIntake(-0.40, 0.5));

			AddParallel(new AutoSetElevator(ELEVATOR_ZERO, 0.35));
			AddSequential(new AutoDrive(-40, 150, 0, 110, 140));

		    AddSequential(new TurnPositionMagic(120, 0.5,150, 150));

		    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 3.0));
			AddSequential(new AutoDrive(62 , 100, 0, 100, 120));

		    AddSequential(new TurnPositionMagic(90, 0.5,150, 150));

//			AddSequential(new AutoIntake(-0.40, 0.5));

//			AddSequential(new AutoDrive(-10, 150, 0, 100, 180));
//			AddSequential(new TurnPositionMagic(100, 0.5, 150, 90));
//			AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 10.0));
//			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0, 500));
//			AddSequential(new AutoDrive(30, 150, 0, 100, 110));
//			AddSequential(new TurnPositionMagic(60, 0.5, 150, 90));
//			AddSequential(new AutoDrive(50 , 150, 0, 100, 60));


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


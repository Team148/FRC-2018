#include <Commands/Auto/AutoCommandGroups/AutonSelector_Biffers.h>
#include "../../AutoPaths/PathExecuter.h"
#include "./Paths/FromMiddlePos_ToLeftScaleDumpPath.h"
#include "../../AutoPaths/PathExecuter.h"


#include "./Paths/GoStraightPath.h"
#include "../TurnPosition.h"
#include "../TurnPositionMagic.h"
#include "../AutoDriveMagic.h"


#include "../AutoIntake.h"
#include "../ReleaseIntake.h"
#include "../AutoSetElevator.h"
#include "../AutoDrive.h"
#include "../../EnableVisionTracking.h"

#include <iostream>
#include "math.h"

#define RadianToDegrees(angleRadians) ((angleRadians) * 180 / M_PI)



AutonSelector_Biffers::AutonSelector_Biffers(int start_pos, std::string FMS_Data, int cube_amount)
{

	std::string fms_data_truc = FMS_Data.substr (0,2);


if(start_pos == tStartingPosition::MIDDLE_POS)
{
	if(fms_data_truc.compare(autoConstData.R_R) == 0) // R POS RR
	{
		std::cout << "What I See: " << fms_data_truc << std::endl;


	}

	if(fms_data_truc.compare(autoConstData.R_L) == 0) // R POS RL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;

		AddSequential(new PathExecuter(FromMiddlePos_ToLeftScaleDumpPath::GetInstance(), false));
		AddParallel(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
		AddSequential(new AutoDrive(-60, 150, 0,  100,RadianToDegrees(FromMiddlePos_ToLeftScaleDumpPath::GetInstance()->GetEndHeading())));
		AddSequential(new TurnPositionMagic(195, 1.0, 150, 90));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
		AddSequential(new AutoDrive(70, 150, 0, 100, 195));

		AddSequential(new AutoDrive(-10, 150, 0,  100, 195));
		AddSequential(new TurnPositionMagic(60, 1.0, 150, 90));
	//	AddSequential(new TurnPositionMagic(90, 0.5, 150, 90));
	//	AddSequential(new TurnPosition(90, 0.5));
		AddSequential(new AutoDrive(70, 150, 0, 100, 60));
		AddParallel(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
		AddSequential(new AutoDrive(-65, 150, 0,  100, 60));
		AddSequential(new TurnPositionMagic(180, 1.0, 150, 90));
		AddSequential(new AutoDrive(15, 150, 0,  100, 200));


	}
	if(fms_data_truc.compare(autoConstData.L_R) == 0) // R POS LR
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;


	}
	if(fms_data_truc.compare(autoConstData.L_L) == 0) // R POS LL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;



	}
}





}

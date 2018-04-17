#include <Commands/Auto/AutoCommandGroups/AutonSelector_Biffers.h>

#include "CommonCommandHeaders.h"


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
		AddSequential(new EnableVisionTracking(false, 2.0));

		AddParallel(new ReleaseIntake());
		AddSequential(new PathExecuter(FromMiddlePos_ToLeftScaleDumpPath::GetInstance(), false));
		AddParallel(new AutoIntake(-0.40, 2.0));
		AddSequential(new AutoDrive(-20, 150, 0,  90, 90));
		AddSequential(new TurnPositionMagic(180, 0.5, 150, 150));

		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
//		AddSequential(new AutoDrive(25, 150, 50, 100, 195));
//		AddSequential(new EnableVisionTracking(true, 2.0));
		AddSequential(new AutoDrive(60, 100, 0, 90, 180));
//		AddSequential(new EnableVisionTracking(false, 2.0));


		AddSequential(new AutoDrive(-10, 150, 0,  120, 180));
		AddParallel(new AutoIntake(INTAKE_SLOW_AUTO_PERCENT, 5.0));
		AddSequential(new TurnPositionMagic(60, 0.5, 150, 150));
	//	AddSequential(new TurnPositionMagic(90, 0.5, 150, 90));
	//	AddSequential(new TurnPosition(90, 0.5));
		AddSequential(new AutoDrive(60, 150, 0, 100, 60));
		AddParallel(new AutoIntake(OUTTAKE_PERCENT, 2.0));
		AddSequential(new AutoDrive(-40, 150, 0,  100, 60));
		AddSequential(new TurnPositionMagic(180, 0.5, 150, 150));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
//		AddSequential(new EnableVisionTracking(true, 2.0));
		AddSequential(new AutoDrive(30, 120, 0,  80, 180));
//		AddSequential(new EnableVisionTracking(false, 2.0));
		AddSequential(new AutoDrive(-10, 150, 0,  80, 180));
		AddParallel(new AutoIntake(INTAKE_SLOW_AUTO_PERCENT, 5.0));
		AddSequential(new TurnPositionMagic(315, 1.0, 150, 150));
		AddSequential(new AutoDrive(-30, 150, 0, 80, 315));


	}
	if(fms_data_truc.compare(autoConstData.L_R) == 0) // R POS LR
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;
		AddSequential(new EnableVisionTracking(false, 2.0));

		AddParallel(new ReleaseIntake());
		AddSequential(new PathExecuter(FromMiddlePos_ToRightScaleDumpPath::GetInstance(), false));
		AddParallel(new AutoIntake(-0.40, 2.0));


		//work in progress

		AddSequential(new AutoDrive(-20, 150, 0,  90, 279));
		AddSequential(new TurnPositionMagic(180, 0.5, 150, 150));

		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
//		AddSequential(new AutoDrive(25, 150, 50, 100, 195));
//		AddSequential(new EnableVisionTracking(true, 2.0));
		AddSequential(new AutoDrive(60, 100, 0, 90, 180));
//		AddSequential(new EnableVisionTracking(false, 2.0));


		AddSequential(new AutoDrive(-10, 150, 0,  120, 180));
		AddParallel(new AutoIntake(INTAKE_SLOW_AUTO_PERCENT, 5.0));
		AddSequential(new TurnPositionMagic(300, 0.5, 150, 150));
	//	AddSequential(new TurnPositionMagic(90, 0.5, 150, 90));
	//	AddSequential(new TurnPosition(90, 0.5));
		AddSequential(new AutoDrive(60, 150, 0, 100, 300));
		AddParallel(new AutoIntake(OUTTAKE_PERCENT, 2.0));
		AddSequential(new AutoDrive(-40, 150, 0,  100, 300));
		AddSequential(new TurnPositionMagic(180, 0.5, 150, 150));
		AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.0));
//		AddSequential(new EnableVisionTracking(true, 2.0));
		AddSequential(new AutoDrive(30, 120, 0,  80, 180));
//		AddSequential(new EnableVisionTracking(false, 2.0));
		AddSequential(new AutoDrive(-10, 150, 0,  80, 180));
		AddParallel(new AutoIntake(INTAKE_SLOW_AUTO_PERCENT, 5.0));
		AddSequential(new TurnPositionMagic(45, 1.0, 150, 150));
		AddSequential(new AutoDrive(-30, 150, 0, 80, 45));

	}
	if(fms_data_truc.compare(autoConstData.L_L) == 0) // R POS LL
	{
	    std::cout << "What I See: " << fms_data_truc << std::endl;



	}
}





}

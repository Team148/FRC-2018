#include <Commands/Auto/AutoCommandGroups/AutonSelector_ScalePriority.h>
#include "CommonCommandHeaders.h"



#include "../../../OI.h"




#define RadianToDegrees(angleRadians) ((angleRadians) * 180 / M_PI)

AutonSelector_ScalePriority::AutonSelector_ScalePriority(int start_pos, std::string FMS_Data, int cube_amount)
{

	std::string fms_data_truc = FMS_Data.substr (0,2);
    std::cout << "What I See: " << fms_data_truc << std::endl;

if(start_pos == tStartingPosition::RIGHT_POS)
{
	if(fms_data_truc.compare(autoConstData.R_R) == 0 || fms_data_truc.compare(autoConstData.L_R) == 0) // R POS RR
	{
		if(OI::GetInstance()->GetSw3()) // 118 special mode activated
		{
			AddParallel(new ReleaseIntake());
			AddSequential(new PathExecuter(FromMiddlePos_ToRightScaleSneakPath::GetInstance(), false)); //add me pls
			AddSequential(new TurnPosition(90, 0.5));
			AddSequential(new AutoDrive(-12, 150, 0, 100, 90));
			AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
			AddSequential(new WaitCommand(0.5));
			AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
			AddSequential(new AutoDrive(-15, 150, 0, 100, 90));
		}
		else
		{

	    AddSequential(new FromRightPos_ToRightScaleGroup());

	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.2));
	    AddSequential(new AutoDrive(48, 150, 0, 100, 155));
	    AddSequential(new AutoDrive(-48, 150, 0, 100, 155));
	    AddParallel(new AutoIntake(INTAKE_HOLD_AUTO_PERCENT, 5.0));
	    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
	    AddSequential(new TurnPositionMagic(40, 1.0,150,90));
	    AddSequential(new AutoIntake(-0.6, 0.5));
	    AddParallel(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    AddSequential(new TurnPositionMagic(140, 0.5,150,90));
	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 4.0));
	    AddSequential(new AutoDrive(63, 150, 0, 100, 140));
	    AddSequential(new AutoDrive(-65, 150, 0, 100, 140));
//	    AddParallel(new AutoIntake(INTAKE_SLOW_PERCENT, 5.0));
	    AddParallel(new AutoIntake(INTAKE_HOLD_AUTO_PERCENT, 3.0));
	    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0, 500));
	    AddSequential(new TurnPositionMagic(45, 1.0,150,90));
	    AddSequential(new AutoIntake(-0.6, 0.5));
	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));

		}

	}

	if(fms_data_truc.compare(autoConstData.R_L) == 0 || fms_data_truc.compare(autoConstData.L_L) == 0) // R POS RL
	{


//		AddSequential(new PathExecuter(FromRightPos_ToLeftScalePath_Part1::GetInstance(), false));
//
//		AddSequential(new PathExecuter(FromRightPos_ToLeftScalePath_Part2::GetInstance(), false));
//		AddSequential(new DriveLineVelocity(75, 75, FromRightPos_ToLeftScalePath_Part2::GetInstance()->GetEndHeading(), 300));
//		AddSequential(new PathExecuter(FromRightPos_ToLeftScalePath_Part3::GetInstance(), false));

	    if(OI::GetInstance()->GetSw3()) // 118 special mode activated
	    {
			AddParallel(new ReleaseIntake());
		//	AddSequential(new PathExecuter(FromRightPos_ToLeftScale118Path::GetInstance(), false)); //add me pls
//			AddSequential(new PathExecuter(FromMiddlePos_ToLeftScaleSneakPath::GetInstance(), false)); //add me pls

			AddSequential(new TurnPosition(270, 0.5));
			AddSequential(new AutoDrive(-12, 150, 0, 100, 270));
			AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
			AddSequential(new WaitCommand(0.5));
			AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
			AddSequential(new AutoDrive(-15, 150, 0, 100, 270));

//			//RightScaleSneak
//	    	AddSequential(new PathExecuter(FromMiddlePos_ToRightScaleSneakPath::GetInstance(), false)); //add me pls
//			AddSequential(new TurnPosition(90, 0.5));
//			AddSequential(new AutoDrive(-12, 150, 0, 100, 90));
//			AddSequential(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
//			AddSequential(new WaitCommand(0.5));
//			AddSequential(new AutoIntake(OUTTAKE_FULL_PERCENT, 0.5));
//			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
//			AddSequential(new AutoDrive(-15, 150, 0, 100, 90));
//
	    }
	    else //normal left scale case
	    {

		//	AddParallel(new ReleaseIntake());
//			AddParallel(new AutoIntake(0.10, 4.0));

		    AddSequential(new FromRightPos_ToLeftScaleGroup());

			AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 4.0));
			AddSequential(new AutoDrive(55, 100, 0, 100, 210));
			AddSequential(new AutoDrive(-55, 150, 0, 120, 210));
			AddParallel(new AutoIntake(INTAKE_HOLD_AUTO_PERCENT, 5.2));
			AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH-2500, 0.0, 500));
		    AddSequential(new TurnPositionMagic(320, 1.0, 150, 90));
		    AddSequential(new AutoIntake(-0.4, 0.4));
//			AddSequential(new AutoDrive(50, 150, 0, 100, 0));
//			AddSequential(new AutoIntake(-0.4, 0.3));
//			AddSequential(new AutoDrive(-15, 150, 0, 100, 0));

		    AddParallel(new TurnPositionMagic(215, 1.2,120,90));
		    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0, 500));
			AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 4.0));
			AddSequential(new AutoDrive(75, 100, 0, 100, 215));
//			AddSequential(new AutoDrive(-45, 100, 0, 120, 215));

//			AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0, 500));
//			AddSequential(new TurnPositionMagic(330, 0.5,150,90));
//			AddSequential(new CheckHeading(330, 10, 1.0));
//			AddSequential(new AutoIntake(-0.6, 0.5));
//			AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
	    }


	}
}

//if(start_pos == tStartingPosition::LEFT_POS)
//{
//
//	if(fms_data_truc.compare(autoConstData.L_L) == 0 || fms_data_truc.compare(autoConstData.R_L) == 0) // R POS RR
//	{
//
//	    std::cout << FromLeftPos_ToLeftScalePath::GetInstance()->GetTimeLength() << std::endl;
////	    AddParallel(new ReleaseIntake());
//	    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, FromLeftPos_ToLeftScalePath::GetInstance()->GetTimeLength()-1.0)); // ADDED, NOT NORMAL
//	    AddSequential(new PathExecuter(FromLeftPos_ToLeftScalePath::GetInstance(), false));
//	    AddSequential(new AutoIntake(-0.4, 0.3));
//	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
//	    AddSequential(new TurnPositionMagic(210, 0.6,150,90));
//	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 5.2));
//	    AddSequential(new AutoDrive(48, 150, 0, 100, 210));
//	    AddSequential(new AutoDrive(-48, 150, 0, 100, 210));
//	    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.0));
//	    AddSequential(new TurnPositionMagic(320, 0.5,150,90));
//	    AddSequential(new WaitCommand(0.5));
//	    AddSequential(new AutoIntake(-0.6, 0.5));
//	    AddParallel(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
//	    AddSequential(new TurnPositionMagic(220, 0.5,150,90));
//	    AddParallel(new AutoIntake(INTAKE_FAST_PERCENT, 10.0));
//	    AddSequential(new AutoDrive(60, 150, 0, 100, 220));
//	    AddSequential(new AutoDrive(-50, 150, 0, 100, 220));
//	    AddParallel(new AutoSetElevator(ELEVATOR_SCALE_HIGH, 0.1));
//	    AddSequential(new TurnPositionMagic(320, 0.5,150,80));
//	    AddSequential(new WaitCommand(0.7));
//	    AddSequential(new AutoIntake(-0.6, 0.5));
//	    AddSequential(new AutoSetElevator(ELEVATOR_ZERO, 0.0));
//	}
//
//}




}

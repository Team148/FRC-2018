 /*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <Commands/Auto/AutoCommandGroups/AutonSelector_Hybrid.h>
#include <Commands/Auto/AutoCommandGroups/AutonSelector_SwitchOnly.h>
#include <Commands/Auto/AutoCommandGroups/AutonSelector_ScalePriority.h>

#include <Commands/Auto/AutoDrive.h>
#include <Commands/Auto/LockHeading.h>
#include <Commands/Auto/AutoTurnPID.h>
#include <Commands/Auto/AutoIntake.h>
#include <Commands/Auto/TurnPosition.h>
#include <Commands/Auto/AutoDriveTurnPID.h>
#include <Commands/Auto/AutoIntake.h>
#include <Commands/Auto/AutoCommandGroups/DriveAndScore.h>
#include <Commands/Auto/AutoSetElevator.h>
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>
#include "math.h"
#include <iostream>
//#include <Commands/Pathfind.h>
//#include <Commands/AutoPaths/GoStraightPath.h>
#include "Constants.h"
#include "RobotMap.h"
#include "OI.h"

#include "Subsystems/Drivetrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Climber.h"
#include <Subsystems/Wrangler.h>

#include "Commands/DriveWithJoystick.h"
#include "Commands/TankDriveJoystick.h"
#include "Commands/RunIntake.h"
#include "Util/UnitMaster.h"
#include "Commands/ElevatorWithJoystick.h"
#include "Commands/SetElevator.h"
#include "Commands/RunClimber.h"
#include "Commands/GrabPartner.h"
#include "Commands/OI_Refresh.h"


#include "Commands/SetDrivetrainVelocity.h"
#include <string>

class Robot : public frc::TimedRobot {
private:
	float m_armAngle = 0.0;
	Command* command;
	int m_timeindex = 0;

public:

	Drivetrain *drivetrain = 0;
	Intake *intake = 0;
	Elevator *elevator = 0;
	Climber *climber = 0;
	Wrangler *wrangler = 0;
	OI *oi = 0;
	UnitMaster unit_master;

	std::string gameData = "";


	void RobotInit() override {

		oi = OI::GetInstance();
		drivetrain = Drivetrain::GetInstance();
		intake = Intake::GetInstance();
		elevator = Elevator::GetInstance();
		climber = Climber::GetInstance();
		wrangler = Wrangler::GetInstance();

	}

	/**
	 * This function is called once each time the robot enters Disabled
	 * mode.
	 * You can use it to reset any subsystem information you want to clear
	 * when
	 * the robot is disabled.
	 */
	void DisabledInit() override {
		frc::Scheduler::GetInstance()->RemoveAll();
	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

	}

	/**
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to
	 * the
	 * chooser code above (like the commented example) or additional
	 * comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		frc::Scheduler::GetInstance()->RemoveAll();
		frc::TimedRobot::SetPeriod(AUTO_PERIODIC_DT);
		Drivetrain::GetInstance()->InitPathDriveHeading();
		//frc::Scheduler::GetInstance()->AddCommand(new TurnPosition(200.0, true, 5.0));
//		frc::Scheduler::GetInstance()->AddCommand(new LockHeading(10.0));
		int current_auto_selection = 0;
		enum currentAutoSelection
		{
			SWITCH_ONLY = 10,
			HYBRID_MODE = 11,
			SCALE_MODE = 12
		};


		int autoPosition = 0;
		int cubeAmount = 0;
//		char fms_data[3] = {};

		if (!elevator->IsClosedLoop()){
			elevator->ConfigClosedLoop();
		}

		frc::Scheduler::GetInstance()->AddCommand(new SetElevator(ELEVATOR_ZERO));
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

		if(gameData.length() > 0)
		{
//			cubeAmount = oi->GetInstance()->GetSelectorA();
			autoPosition = tStartingPosition::RIGHT_POS;

			if(cubeAmount > 3) cubeAmount = 3;


			if(oi->GetInstance()->GetSw4())
			{
//				autoPosition = tStartingPosition::LEFT_POS;
			}
			else
			{
				autoPosition = tStartingPosition::RIGHT_POS;
			}

			if(oi->GetInstance()->GetSw1()) // THIS OVERRIDES ALL
			{
				current_auto_selection = currentAutoSelection::SWITCH_ONLY;
			}
			else
			{
				if(oi->GetInstance()->GetSw2())
				{
					current_auto_selection = currentAutoSelection::SCALE_MODE;
				}
				else
				{
					current_auto_selection = currentAutoSelection::HYBRID_MODE;

				}
			}
			switch(current_auto_selection)
			{
				case currentAutoSelection::SWITCH_ONLY:
					frc::Scheduler::GetInstance()->AddCommand(new AutonSelector_SwitchOnly(tStartingPosition::MIDDLE_POS, gameData, cubeAmount));

				break;
				case currentAutoSelection::HYBRID_MODE:
					frc::Scheduler::GetInstance()->AddCommand(new AutonSelector_Hybrid(tStartingPosition::RIGHT_POS, gameData, cubeAmount));

				break;
				case currentAutoSelection::SCALE_MODE:
					frc::Scheduler::GetInstance()->AddCommand(new AutonSelector_ScalePriority(tStartingPosition::RIGHT_POS, gameData, cubeAmount));
				break;
				default:
				break;
			}
	//		frc::Scheduler::GetInstance()->AddCommand(new AutonSelector_Hybrid(autoPosition, gameData, cubeAmount));
	//        frc::Scheduler::GetInstance()->AddCommand(new AutonSelector_SwitchOnly(tStartingPosition::MIDDLE_POS, gameData, cubeAmount));


//			if(oi->GetInstance()->GetSw1())
//			{
//		        frc::Scheduler::GetInstance()->AddCommand(new AutonSelector_ScalePriority(autoPosition, gameData, cubeAmount));
//			}
//			if(oi->GetInstance()->GetSw2())
//			{
//		        frc::Scheduler::GetInstance()->AddCommand(new AutonSelector_Hybrid(autoPosition, gameData, cubeAmount));
//			}
//			if(oi->GetInstance()->GetSw3())
//			{
//		        frc::Scheduler::GetInstance()->AddCommand(new AutonSelector_SwitchOnly(tStartingPosition::MIDDLE_POS, gameData, cubeAmount));
//			}
	        std::cout << "FMS_DATA: " << gameData << " What I See: " << gameData << "AutoPosition: " << autoPosition << "CubeAmount: " << cubeAmount << std::endl;
//	        frc::Scheduler::GetInstance()->AddCommand(new AutonSelectorGroup(autoPosition, gameData, cubeAmount));
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
		frc::SmartDashboard::PutNumber("Time", m_timeindex);
		m_timeindex++;



	}

	void TeleopInit() override
	{
		frc::Scheduler::GetInstance()->RemoveAll();
		frc::TimedRobot::SetPeriod(TELE_PERIODIC_DT);

		Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::OPEN_LOOP);


		if (!elevator->IsClosedLoop()){
			elevator->ConfigClosedLoop();
		}

//		frc::Scheduler::GetInstance()->AddCommand(new SetElevator(ELEVATOR_ZERO));
		frc::Scheduler::GetInstance()->AddCommand(new OI_Refresh());

	}


	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();

		frc::SmartDashboard::PutNumber("Elevator Position", elevator->GetElevatorPosition());

		static double IntakeSpeed = 0.0;
		static double ClimberSpeed = 0.0;
		static double WranglerSpeed = 0.0;

		IntakeSpeed = 0.0; // MAKES SURE THERE IS NOT A STICKY SET
		ClimberSpeed = 0.0;
		WranglerSpeed = 0.0;

		if (oi->drvStick->GetRawAxis(2) >= 0.2 || oi->opStick->GetRawAxis(3) >= 0.2)
			IntakeSpeed = OUTTAKE_PERCENT;
		else if (oi->drvStick->GetRawButton(5) || oi->opStick->GetRawButton(6))
			IntakeSpeed = OUTTAKE_FULL_PERCENT;
		else if (oi->opStick->GetRawButton(5))
			IntakeSpeed = INTAKE_FAST_PERCENT;
		else if (oi->opStick->GetRawAxis(2) >= 0.2)
			IntakeSpeed = INTAKE_SLOW_PERCENT;

		if (oi->drvStick->GetRawButton(7) && oi->drvStick->GetRawButton(8))
			WranglerSpeed = WRANGLER_FAST_PERCENT;

		if (oi->opStick->GetRawButton(7) && oi->opStick->GetRawButton(8))
			ClimberSpeed = CLIMBER_OUTPUT_PERCENT;

		//POV buttons
		if (oi->opStick->GetPOV() == 0)  frc::Scheduler::GetInstance()->AddCommand(new SetElevator(ELEVATOR_DOUBLE_STACK));
		if (oi->opStick->GetPOV() == 180) frc::Scheduler::GetInstance()->AddCommand(new SetElevator(ELEVATOR_HANG));

		if(OI::GetInstance()->drvStick->GetRawAxis(3) > 0.2)
		{
			IntakeSpeed = OUTTAKE_AUTOSCORE_PERCENT;
		}

		intake->SetIntakeMotor(IntakeSpeed);
		climber->SetClimberMotor(ClimberSpeed);
		wrangler->SetWranglerMotor(WranglerSpeed);
	}

	void TestPeriodic() override {

	}

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.

};

START_ROBOT_CLASS(Robot)

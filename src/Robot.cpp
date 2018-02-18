 /*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <Commands/Auto/AutoDrive.h>
#include <Commands/Auto/AutoTurnPID.h>
#include <Commands/Auto/AutoIntake.h>
#include <Commands/Auto/TurnPosition.h>
#include <Commands/Auto/AutoCommandGroups/AutonSelectorGroup.h>
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
#include <Commands/AutoPaths/GoStraightPath.h>
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
//#include "Commands/OI_Refresh.h"


#include "Commands/SetDrivetrainVelocity.h"

class Robot : public frc::TimedRobot {
private:
	float m_armAngle = 0.0;
	Command* command;

public:

	Drivetrain *drivetrain = 0;
	Intake *intake = 0;
	Elevator *elevator = 0;
	Climber *climber = 0;
	Wrangler *wrangler = 0;
	OI *oi = 0;
	UnitMaster unit_master;

	void RobotInit() override {
		//m_chooser.AddDefault("Default Auto", &m_defaultAuto);
		//m_chooser.AddObject("My Auto", &m_myAuto);
		//frc::SmartDashboard::PutData("Auto Modes", &m_chooser);



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
		//frc::Scheduler::GetInstance()->AddCommand(new AutoIntake(INTAKE_PERCENT,5));
		//frc::Scheduler::GetInstance()->AddCommand(new TurnPID(45));
		//frc::Scheduler::GetInstance()->AddCommand(new SetElevator(ELEVATOR_SCALE_HIGH));
		char* meh = 0;
        frc::Scheduler::GetInstance()->AddCommand(new AutonSelectorGroup(tStartingPosition::RIGHT_POS, meh, tCubeAmount::THREE_CUBE));
		//frc::Scheduler::GetInstance()->AddCommand(new AutoIntake());

//		frc::Scheduler::GetInstance()->AddCommand(new TurnPosition(180.0));
		//frc::Scheduler::GetInstance()->AddCommand(new Right_S_Scale_S_Switch_S_Scale());


//		frc::Scheduler::GetInstance()->AddCommand(new GoStraightPath);

		if (!elevator->IsClosedLoop()){
			elevator->ConfigClosedLoop();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();


	}

	void TeleopInit() override
	{
		frc::Scheduler::GetInstance()->RemoveAll();
		frc::TimedRobot::SetPeriod(TELE_PERIODIC_DT);

		drivetrain->configOpenLoop();
//		drivetrain->configClosedLoop();

		if (!elevator->IsClosedLoop()){
			elevator->ConfigClosedLoop();
		}
//		frc::Scheduler::GetInstance()->AddCommand(new OI_Refresh());

	}


	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();

		static double IntakeSpeed = 0.0;

		IntakeSpeed = 0.0; // MAKES SURE THERE IS NOT A STICKY SET

		if (oi->drvStick->GetRawAxis(2) >= 0.2 || oi->opStick->GetRawAxis(3) >= 0.2)
			IntakeSpeed = OUTTAKE_PERCENT;
		else if (oi->drvStick->GetRawButton(5) || oi->opStick->GetRawButton(6))
			IntakeSpeed = OUTTAKE_FULL_PERCENT;
		else if (oi->opStick->GetRawButton(5))
			IntakeSpeed = INTAKE_PERCENT;


		if (oi->drvStick->GetRawButton(7) && oi->drvStick->GetRawButton(8))
			climber->SetClimberMotor(CLIMBER_OUTPUT_PERCENT);
		else
			climber->SetClimberMotor(0.0);

		if (oi->opStick->GetRawButton(7) && oi->opStick->GetRawButton(8))
			wrangler->SetWranglerMotor(WRANGLER_OUTPUT_PERCENT);
		else
			wrangler->SetWranglerMotor(0.0);

		//POV buttons
		if (oi->opStick->GetPOV() == 0)
			elevator->SetElevatorPosition(ELEVATOR_DOUBLE_STACK);
		if (oi->opStick->GetPOV() == 180)
			elevator->SetElevatorPosition(ELEVATOR_HANG);

//		if
		if(OI::GetInstance()->drvStick->GetRawAxis(3) > 0.2)
		{
			IntakeSpeed = OUTTAKE_AUTOSCORE_PERCENT;
		}

		intake->SetIntakeMotor(IntakeSpeed);

//



//		if (oi->opStick->GetRawAxis(1) >= 0.2) {
//			elevator->SetElevatorJoystickPosition(oi->opStick->GetRawAxis(1));
//		}

//		//Intake Commands
//		if (oi->drvStick->GetRawButton(5) || oi->opStick->GetRawButton(6))
//			new RunIntake(OUTTAKE_FULL_PERCENT);
//		else if (oi->opStick->GetRawButton(5))
//			new RunIntake(INTAKE_PERCENT);
//		else if (oi->drvStick->GetRawAxis(2) >= 0.2 || oi->opStick->GetRawAxis(3) >= 0.2)
//			new RunIntake(OUTTAKE_PERCENT);
//		else
//			new RunIntake(0.0);

		//std::cout << "left encoder value: " << drivetrain->updateLeftEncoder() << std::endl;


//		std::cout << "left encoder value: " << drivetrain->updateLeftEncoder() << std::endl;
//		std::cout << "\n right encoder value " << drivetrain->updateRightEncoder() << std::endl;

//		drivetrain->unitConversionTest();

//		drivetrain->getLeftDriveVelocity();

//		std::cout << "Yaw:\t\t" << drivetrain->updateGyroYaw() << std::endl;
//		std::cout << "Pitch:\t\t" << drivetrain->updateGyroPitch() << std::endl;
//		std::cout << "Roll:\t\t" << drivetrain->updateGyroRoll() << std::endl;

//		std::cout << "Get raw gyro yaw: " << drivetrain->updatePigeon() << std::endl;
//		std::cout << "Get accum gyro yaw: " << drivetrain->updatePigey() << std::endl;
//		drivetrain->SetDriveVelocity(unit_master.GetTicksPer100ms((120*OI::GetInstance()->drvStick->GetRawAxis(1))), unit_master.GetTicksPer100ms((120*OI::GetInstance()->drvStick->GetRawAxis(1))));

	}

	void TestPeriodic() override {
//		drivetrain->SetDriveVelocity(0.0, unit_master.GetTicksPer100ms((150*OI::GetInstance()->drvStick->GetRawAxis(1))));
//		frc::SmartDashboard::PutNumber("DriveVelocity",drivetrain->getLeftDriveVelocity());
	}

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.


};

START_ROBOT_CLASS(Robot)

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
#include <Commands/Auto/AutoCommandGroups/Right_S_Scale_S_Switch_S_Scale.h>
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
#include <Subsystems/Wrangler.h>
//#include "constants.h"
#include "RobotMap.h"
#include "OI.h"

#include "Subsystems/Drivetrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Climber.h"

#include "Commands/DriveWithJoystick.h"
#include "Commands/TankDriveJoystick.h"
#include "Commands/RunIntake.h"
#include "Util/UnitMaster.h"
#include "Commands/ElevatorWithJoystick.h"
#include "Commands/RunClimber.h"
#include "Commands/GrabPartner.h"

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
		//command = new PathFind();
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
	void DisabledInit() override {}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	//	std::cout << OI::GetInstance()->opStick->GetRawAxis(2) << std::endl;
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
		//frc::Scheduler::GetInstance()->AddCommand(new AutoIntake(INTAKE_PERCENT,5));
		//frc::Scheduler::GetInstance()->AddCommand(new TurnPID(45));
		//frc::Scheduler::GetInstance()->AddCommand(new SetElevator(ELEVATOR_SCALE_HIGH));
        frc::Scheduler::GetInstance()->AddCommand(new AutoSetElevator(true,ELEVATOR_SCALE_HIGH,5));
		//frc::Scheduler::GetInstance()->AddCommand(new AutoIntake());

//		frc::Scheduler::GetInstance()->AddCommand(new TurnPosition(180.0));
		//frc::Scheduler::GetInstance()->AddCommand(new Right_S_Scale_S_Switch_S_Scale());


		if (!elevator->IsClosedLoop()){
			elevator->ConfigClosedLoop();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();

//		frc::SmartDashboard::PutNumber("LeftEncoderVelocity", drivetrain->getLeftDriveVelocity());
//		frc::SmartDashboard::PutNumber("RightEncoderVelocity", drivetrain->getRightDriveVelocity());

	}

	void TeleopInit() override
	{
		drivetrain->configOpenLoop();
//		drivetrain->configClosedLoop();

		if (!elevator->IsClosedLoop()){
			elevator->ConfigClosedLoop();
		}
	}


	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();

		frc::SmartDashboard::PutNumber("ElevatorEncoderPosition", elevator->GetElevatorPosition());
		frc::SmartDashboard::PutNumber("ElevatorEncoderVelocity", elevator->GetElevatorVelocity());
		frc::SmartDashboard::PutNumber("Average Intake Current",Intake::GetInstance()->GetAverageCurrent());
		std::cout<< "Time: " << frc::Timer::GetFPGATimestamp() <<"Avg Current" << Intake::GetInstance()->GetAverageCurrent() << std::endl;
		//

		//Driver Outtake
//		if(oi->drvStick->GetRawAxis(2) > 0.1)
//			frc::Scheduler::GetInstance()->AddCommand(new RunIntake(true, true, false));
//		else
//			frc::Scheduler::GetInstance()->AddCommand(new RunIntake(false, false, false));
//
//		//Operator Intake
//		if((oi->opStick->GetRawAxis(2)) > 0.1)
//			frc::Scheduler::GetInstance()->AddCommand(new RunIntake(true, false, false));
//		else {
//			if(oi->opStick->GetRawButton(6)){
//
//			}
//			frc::Scheduler::GetInstance()->AddCommand(new RunIntake(false,false,false));
//			}
//
//		//Operator Outtake
//		if((oi->opStick->GetRawAxis(3)) > 0.1)
//			frc::Scheduler::GetInstance()->AddCommand(new RunIntake(true, true, false));
//		else
//			frc::Scheduler::GetInstance()->AddCommand(new RunIntake(false,false,false));

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

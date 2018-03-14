
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>
#include "math.h"
#include <iostream>
#include "Constants.h"
#include "RobotMap.h"
#include "OI.h"

#include "Subsystems/Drivetrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Wrist.h"

#include "Commands/DriveWithJoystick.h"
#include "Commands/TankDriveJoystick.h"
#include "Commands/RunIntake.h"
#include "Commands/RunWrist.h"

#include <string>

class Robot : public frc::TimedRobot {
private:
	float m_armAngle = 0.0;
	Command* command;

public:

	Drivetrain *drivetrain = 0;
	Intake *intake = 0;
	Wrist *wrist = 0;
	OI *oi = 0;


	void RobotInit() override {

		oi = OI::GetInstance();
		drivetrain = Drivetrain::GetInstance();
		intake = Intake::GetInstance();
		wrist = Wrist::GetInstance();

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
	}
	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();

	}

	void TeleopInit() override
	{
		frc::Scheduler::GetInstance()->RemoveAll();
	}


	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();

		static double WristSpeed = 0.0;

		WristSpeed = 0.0;

		if (oi->drvStick->GetRawAxis(2) >= 0.2)
			WristSpeed = WRIST_PERCENT;
		else if (oi->drvStick->GetRawAxis(3) >= 0.2)
			WristSpeed = -WRIST_PERCENT;

		wrist->SetWristMotor(WristSpeed);
	}

	void TestPeriodic() override {

	}

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.

};

START_ROBOT_CLASS(Robot)

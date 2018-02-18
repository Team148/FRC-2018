#include "DriveWithJoystick.h"
#include "OI.h"
#include <iostream>

#include <Commands/Scheduler.h>
#include "Commands/AutoScoreCube.h"
#include "Commands/ExitAutoScoreCube.h"

DriveWithJoystick::DriveWithJoystick() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());

}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
//	//Drivetrain::GetInstance()->Arcade(OI::GetInstance()->drvStick->GetRawAxis(4), OI::GetInstance()->drvStick->GetRawAxis(1));
//	if(OI::GetInstance()->drvStick->GetRawButton(1)){
//		Drivetrain::GetInstance()->SetDriveVelocity(unit_master.GetTicksPer100ms(140.0), unit_master.GetTicksPer100ms(140.0));
//	//	std::cout << "works" << std::endl;
//	}
//	else
//		Drivetrain::GetInstance()->Arcade(OI::GetInstance()->drvStick->GetRawAxis(4), -OI::GetInstance()->drvStick->GetRawAxis(1));
	if(!OI::GetInstance()->drvStick->GetRawButton(6))  Drivetrain::GetInstance()->Arcade(-(OI::GetInstance()->drvStick->GetRawAxis(1)), OI::GetInstance()->drvStick->GetRawAxis(4));
	else Drivetrain::GetInstance()->Arcade((-(OI::GetInstance()->drvStick->GetRawAxis(1))*DRIVETRAIN_TURBO_THROTTLE_FILTER), OI::GetInstance()->drvStick->GetRawAxis(4)*DRIVETRAIN_TURBO_TURN_FILTER);

	static bool isAutoScoreActive = false;
	if(OI::GetInstance()->drvStick->GetRawAxis(3) > 0.2 && !isAutoScoreActive)
	{
		frc::Scheduler::GetInstance()->AddCommand(new AutoScoreCube());
		isAutoScoreActive = true;
	}
	if(OI::GetInstance()->drvStick->GetRawAxis(3) < 0.2 && isAutoScoreActive)
	{
		frc::Scheduler::GetInstance()->AddCommand(new ExitAutoScoreCube());
		isAutoScoreActive = false;

	}
	if(!isAutoScoreActive)
	{
		if(!OI::GetInstance()->drvStick->GetRawButton(6)) 	Drivetrain::GetInstance()->Arcade(OI::GetInstance()->drvStick->GetRawAxis(4)*DRIVETRAIN_TURN_FILTER, (-(OI::GetInstance()->drvStick->GetRawAxis(1))*DRIVETRAIN_THROTTLE_FILTER));
		else Drivetrain::GetInstance()->Arcade(OI::GetInstance()->drvStick->GetRawAxis(4)*DRIVETRAIN_TURBO_TURN_FILTER, (-(OI::GetInstance()->drvStick->GetRawAxis(1))*DRIVETRAIN_TURBO_THROTTLE_FILTER));
	}

}
// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {
	Drivetrain::GetInstance()->Arcade(0,0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {

}

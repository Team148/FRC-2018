#include "TankDriveJoystick.h"
#include "OI.h"


TankDriveJoystick::TankDriveJoystick() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
}

// Called just before this Command runs the first time
void TankDriveJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDriveJoystick::Execute() {
	Drivetrain::GetInstance()->Tank(OI::GetInstance()->drvStick->GetY(Joystick::JoystickHand::kLeftHand), \
			OI::GetInstance()->drvStick->GetY(Joystick::JoystickHand::kRightHand));
}

// Make this return true when this Command no longer needs to run execute()
bool TankDriveJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDriveJoystick::End() {
	Drivetrain::GetInstance()->Tank(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDriveJoystick::Interrupted() {
	End();
}

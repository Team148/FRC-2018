#include "ElevatorWithJoystick.h"
#include "OI.h"
#include <iostream>


ElevatorWithJoystick::ElevatorWithJoystick() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Elevator::GetInstance());
}

// Called just before this Command runs the first time
void ElevatorWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ElevatorWithJoystick::Execute() {

	std::cout <<"drive execute" << std::endl;
	Elevator::GetInstance()->JoystickControl(OI::GetInstance()->drvStick->GetRawAxis(1));
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ElevatorWithJoystick::End() {
	Elevator::GetInstance()->JoystickControl(0.0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorWithJoystick::Interrupted() {

}

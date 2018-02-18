#include "VibrateController.h"
#include "OI.h"
#include <iostream>


VibrateController::VibrateController(bool x) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	m_x = x;
}

// Called just before this Command runs the first time
void VibrateController::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void VibrateController::Execute() {
	if(m_x){
	std::cout <<"vibrate execute" << std::endl;
	//Drivetrain::GetInstance()->Arcade(OI::GetInstance()->drvStick->GetRawAxis(4), -(OI::GetInstance()->drvStick->GetRawAxis(1)));
	//OI::GetInstance()->opStick->SetRumble(Joystick::kLeftRumble,1.0);
	OI::GetInstance()->opStick->SetRumble(Joystick::kRightRumble,1.0);
	}
	else
		m_finished = true;

}

// Make this return true when this Command no longer needs to run execute()
bool VibrateController::IsFinished() {
	//return OI::GetInstance()->opStick->GetRawButton(2);
	//return false;
	return m_finished;
}

// Called once after isFinished returns true
void VibrateController::End() {
//	Drivetrain::GetInstance()->Arcade(0,0);
	OI::GetInstance()->opStick->SetRumble(Joystick::kLeftRumble,0.0);
	OI::GetInstance()->opStick->SetRumble(Joystick::kRightRumble,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VibrateController::Interrupted() {

}

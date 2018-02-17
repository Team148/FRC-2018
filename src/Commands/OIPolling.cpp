#include "OIPolling.h"

OIPolling::OIPolling() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void OIPolling::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void OIPolling::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool OIPolling::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OIPolling::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OIPolling::Interrupted() {

}

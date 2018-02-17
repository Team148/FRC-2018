#include "SetElevator.h"
#include "OI.h"

SetElevator::SetElevator(bool on, double position) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Elevator::GetInstance());
	m_on = on;
	m_position = position;
	m_isFinished = false;
}

// Called once when the command executes
void SetElevator::Initialize() {

	if (m_on) {
		Elevator::GetInstance()->SetElevatorPosition(m_position);
		if(m_position != ELEVATOR_ZERO)
			m_isFinished = true;
	}
	else {
		Elevator::GetInstance()->SetElevatorPosition(1.0);
	}
}

// Called repeatedly when this Command is scheduled to run
void SetElevator::Execute() {
	if(Elevator::GetInstance()->GetElevatorPosition() < ELEVATOR_BOTTOM_NEUTRAL){
		Elevator::GetInstance()->ConfigNeutralClosedLoop();
		m_isFinished = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SetElevator::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void SetElevator::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetElevator::Interrupted() {

}

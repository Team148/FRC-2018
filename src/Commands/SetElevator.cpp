#include "SetElevator.h"
#include "OI.h"

SetElevator::SetElevator(bool on, double position) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Elevator::GetInstance());
	m_on = on;
	m_position = position;
}

// Called once when the command executes
void SetElevator::Initialize() {

	if (m_on) {
		Elevator::GetInstance()->SetElevatorPosition(m_position);
	}
	else {
		Elevator::GetInstance()->SetElevatorPosition(1.0);
	}
}

bool SetElevator::IsFinished() {
	return m_isFinished;
}
void SetElevator::End() {

}
void SetElevator::Interrupted(){

}

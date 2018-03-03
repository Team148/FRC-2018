#include "SetElevator.h"
#include "OI.h"
#include <iostream>

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
		if(m_position != ELEVATOR_ZERO){
			m_isFinished = true;
		}
	}
//	else {
//		Elevator::GetInstance()->SetElevatorPosition(ELEVATOR_ZERO);
//	}
	m_isFinished = false;
}

void SetElevator::Execute() {

	if(Elevator::GetInstance()->GetElevatorPosition() < ELEVATOR_ZERO_NEUTRAL_POSITION && (m_position == ELEVATOR_ZERO)){
		Elevator::GetInstance()->ConfigNeutralClosedLoop();
		std::cout << "set elevator neutral" << std::endl;
		m_isFinished = true;
	}

}

bool SetElevator::IsFinished() {
	return m_isFinished;
}
void SetElevator::End() {

}
void SetElevator::Interrupted(){

}

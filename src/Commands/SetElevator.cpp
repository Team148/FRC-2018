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



//	if(m_position != ELEVATOR_ZERO)
//	{
//		m_isFinished = true;
//	}
////	else {
////		Elevator::GetInstance()->SetElevatorPosition(ELEVATOR_ZERO);
////	}
//	m_isFinished = false;
}

void SetElevator::Execute() {
	double slope = (ELEVATOR_F - ELEVATOR_ZERO_F) / (ELEVATOR_ZERO_NEUTRAL_POSITION - ELEVATOR_ZERO_NEUTRAL_POSITION_DEADBAND);
	double linear_F = slope*(Elevator::GetInstance()->GetElevatorPosition()) - ELEVATOR_ZERO_F;



	if(m_position == ELEVATOR_ZERO)
	{
		if(Elevator::GetInstance()->GetElevatorPosition() > ELEVATOR_ZERO_NEUTRAL_POSITION )
		{
			Elevator::GetInstance()->SetElevatorPosition(m_position, ELEVATOR_F);
		}
		else
		{
				Elevator::GetInstance()->SetElevatorPosition(m_position, linear_F);

			if(Elevator::GetInstance()->GetElevatorPosition() < ELEVATOR_ZERO_NEUTRAL_POSITION_DEADBAND)
			{
				Elevator::GetInstance()->SetElevatorPosition(m_position, ELEVATOR_ZERO_F);
				m_isFinished = true;

			}
		}

	}
	else
	{
		Elevator::GetInstance()->SetElevatorPosition(m_position, ELEVATOR_F);
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

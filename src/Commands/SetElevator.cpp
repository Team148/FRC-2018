#include "SetElevator.h"
#include "OI.h"
#include <iostream>

SetElevator::SetElevator(double position) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Elevator::GetInstance());
	m_position = position;
	m_isFinished = false;
	std::cout << "SetElevatorConstructor" <<std::endl;
}


// Called once when the command executes
void SetElevator::Initialize() {

	m_isFinished = false;
	//Elevator::GetInstance()->ConfigClosedLoopMagic(4200,6000);

}

void SetElevator::Execute() {

//	Elevator::GetInstance()->SetElevatorPositionMagic(m_position, ELEVATOR_F);
//	m_isFinished = true;

	double slope = (ELEVATOR_F_DOWN - ELEVATOR_ZERO_F) / (ELEVATOR_ZERO_NEUTRAL_POSITION - ELEVATOR_ZERO_NEUTRAL_POSITION_DEADBAND);
	double y_intercept = ELEVATOR_ZERO_F - (slope*ELEVATOR_ZERO_NEUTRAL_POSITION_DEADBAND); //std::cout << "y-intercept : " << y_intercept << " ";
	double linear_F = slope*(Elevator::GetInstance()->GetElevatorPosition()) + y_intercept;



	if(m_position > ELEVATOR_ZERO)
	{
		Elevator::GetInstance()->SetElevatorPosition(m_position, ELEVATOR_F);
		m_isFinished = true;
//		std::cout << "finish std case" <<std::endl;

	}
		if(m_isFinished == false)
		{
			if(Elevator::GetInstance()->GetElevatorPosition() > ELEVATOR_ZERO_NEUTRAL_POSITION )
			{
				Elevator::GetInstance()->SetElevatorPosition(m_position, ELEVATOR_F_DOWN);
			}
			else
			{

				if(Elevator::GetInstance()->GetElevatorPosition() < ELEVATOR_ZERO_NEUTRAL_POSITION_DEADBAND)
				{
					Elevator::GetInstance()->SetElevatorPosition(m_position, ELEVATOR_ZERO_F);
//					Elevator::GetInstance()->SetElevatorPosition(m_position, 0.0);
					m_isFinished = true;

				}
				Elevator::GetInstance()->SetElevatorPosition(m_position, linear_F);
			//	std::cout << "feedforward: " << linear_F << "pos: " << Elevator::GetInstance()->GetElevatorPosition() << std::endl;
			}
		}


}

bool SetElevator::IsFinished() {
	std::cout << "finished SetElevator" << std::endl;
	return m_isFinished;
}
void SetElevator::End() {

}
void SetElevator::Interrupted(){
	End();
	std::cout << "SetElevator Interrupted" << std::endl;
}

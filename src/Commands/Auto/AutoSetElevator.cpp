#include <Commands/Auto/AutoSetElevator.h>
#include <iostream>
AutoSetElevator::AutoSetElevator(int position, double timeToWait = 0) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Elevator::GetInstance());

	m_IsFinished = false;

	m_position = position;
	m_timeToWait = timeToWait;
}

// Called just before this Command runs the first time
void AutoSetElevator::Initialize() {
	SetTimeout(1.5 + m_timeToWait);
	m_IsFinished = false;
	m_startTime = frc::Timer::GetFPGATimestamp();

}

// Called repeatedly when this Command is scheduled to run
void AutoSetElevator::Execute() {
	double elaspedTime = frc::Timer::GetFPGATimestamp() - m_startTime;
	double currentPosition = Elevator::GetInstance()->GetElevatorPosition();
	double posErr = m_position - currentPosition;

	double slope = (ELEVATOR_F - ELEVATOR_ZERO_F) / (ELEVATOR_ZERO_NEUTRAL_POSITION - ELEVATOR_ZERO_NEUTRAL_POSITION_DEADBAND);
	double linear_F = slope*(Elevator::GetInstance()->GetElevatorPosition()) - ELEVATOR_ZERO_F;


	if(elaspedTime >= m_timeToWait)
	{

		if(abs(posErr) < ELEVATOR_ERROR_TOLERANCE)
		{

			m_IsFinished = true;
		}

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

					}
				}

			}
			else
			{
				Elevator::GetInstance()->SetElevatorPosition(m_position, ELEVATOR_F);
			}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoSetElevator::IsFinished() {
	return m_IsFinished || IsTimedOut();
}

// Called once after isFinished returns true
void AutoSetElevator::End() {
	std::cout << "FINISHED: AutoSetElevator" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoSetElevator::Interrupted() {
	End();
}

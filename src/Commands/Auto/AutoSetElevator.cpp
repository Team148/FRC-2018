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

	if(elaspedTime >= m_timeToWait)
	{
		Elevator::GetInstance()->SetElevatorPosition(m_position);

		if(abs(posErr) < ELEVATOR_ERROR_TOLERANCE)
		{
			if(m_position == ELEVATOR_ZERO)
			{
				Elevator::GetInstance()->ConfigNeutralClosedLoop();
				std::cout << "set elevator neutral" << std::endl;
			}
			m_IsFinished = true;
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

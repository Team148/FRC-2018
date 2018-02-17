#include <Commands/Auto/AutoElevatorUpAfterTime.h>

ElevatorUpAfterTime::ElevatorUpAfterTime(bool on,int position, double timeToWait) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Elevator::GetInstance());

	m_IsFinished = false;

	m_on = on;
	m_position = position;
	m_timeToWait = timeToWait;
}

// Called just before this Command runs the first time
void ElevatorUpAfterTime::Initialize() {
	m_IsFinished = false;
	m_startTime = frc::Timer::GetFPGATimestamp();

}

// Called repeatedly when this Command is scheduled to run
void ElevatorUpAfterTime::Execute() {
	double elaspedTime = frc::Timer::GetFPGATimestamp() - m_startTime;

	if(   elaspedTime >= m_timeToWait)
	{
		if (m_on)
			{
				Elevator::GetInstance()->SetElevatorPosition(m_position);
				m_IsFinished = true;
			}
			else
			{
				Elevator::GetInstance()->SetElevatorPosition(0.0);
				m_IsFinished = true;
			}
	}


}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorUpAfterTime::IsFinished() {
	return m_IsFinished;
}

// Called once after isFinished returns true
void ElevatorUpAfterTime::End() {
	m_IsFinished = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorUpAfterTime::Interrupted() {
	m_IsFinished = false;
}

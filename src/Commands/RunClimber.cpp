#include "RunClimber.h"

RunClimber::RunClimber(bool on) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Climber::GetInstance());
	m_on = on;
}

// Called just before this Command runs the first time
void RunClimber::Initialize() {

	if(m_on)
	{
		Climber::GetInstance()->Set(CLIMBER_OUTPUT_PERCENT);
	}
	else
	{
		Climber::GetInstance()->Set(0.0);

	}
}

#include "GrabPartner.h"

GrabPartner::GrabPartner(bool on) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Forklift::GetInstance());
	m_on = on;
}

// Called just before this Command runs the first time
void GrabPartner::Initialize() {

	if(m_on)
	{
		Forklift::GetInstance()->Set(CLIMBER_OUTPUT_PERCENT);
	}
	else
	{
		Forklift::GetInstance()->Set(0.0);

	}
}

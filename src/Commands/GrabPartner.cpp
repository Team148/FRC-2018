#include "GrabPartner.h"
#include "OI.h"

GrabPartner::GrabPartner(bool on) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Wrangler::GetInstance());
	m_on = on;
}

// Called just before this Command runs the first time
void GrabPartner::Initialize() {

	if(m_on)
	{
		Wrangler::GetInstance()->SetWranglerMotor(WRANGLER_OUTPUT_PERCENT);
	}
	else
	{
		Wrangler::GetInstance()->SetWranglerMotor(0.0);

	}
}

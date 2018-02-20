#include "GrabPartner.h"
#include "OI.h"

GrabPartner::GrabPartner(double percent) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Wrangler::GetInstance());
	m_percent = percent;
}

// Called just before this Command runs the first time
void GrabPartner::Initialize() {

		Wrangler::GetInstance()->SetWranglerMotor(m_percent);
}

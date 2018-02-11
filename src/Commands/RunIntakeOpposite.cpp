#include "RunIntakeOpposite.h"
#include "OI.h"

RunIntakeOpposite::RunIntakeOpposite(bool on) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Intake::GetInstance());
	m_on = on;
}

// Called once when the command executes
void RunIntakeOpposite::Initialize() {

	if(m_on)
	{
		Intake::GetInstance()->SetIntakeMotorOpposite(INTAKE_PERCENT);
	}
	else
	{
		Intake::GetInstance()->SetIntakeMotorOpposite(0.0);
	}

}

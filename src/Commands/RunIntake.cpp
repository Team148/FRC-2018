#include "RunIntake.h"
#include "OI.h"

RunIntake::RunIntake(bool on, bool reversed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Intake::GetInstance());
	m_on = on;
	m_reversed = reversed;
}

// Called once when the command executes
void RunIntake::Initialize() {

	if(m_on) {
		if(m_reversed) {
			Intake::GetInstance()->SetIntakeMotor(OUTTAKE_PERCENT);
		}
		else {
			Intake::GetInstance()->SetIntakeMotor(1.0);
		}

	}
	else {
		Intake::GetInstance()->SetIntakeMotor(0.0);
	}

}

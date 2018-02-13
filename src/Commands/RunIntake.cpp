#include "RunIntake.h"
#include "OI.h"

RunIntake::RunIntake(bool on, bool reversed, bool reversedFull) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Intake::GetInstance());
	m_on = on;
	m_reversed = reversed;
	m_reversedFull = reversedFull;
}

// Called once when the command executes
void RunIntake::Initialize() {

	if(m_on) {
		if(m_reversed) {
			Intake::GetInstance()->SetIntakeMotor(OUTTAKE_PERCENT);
		}
		if(m_reversedFull) {
			Intake::GetInstance()->SetIntakeMotor(OUTTAKE_FULL_PERCENT);
		}
		else {
			Intake::GetInstance()->SetIntakeMotor(INTAKE_PERCENT);
		}

	}
	else {
		Intake::GetInstance()->SetIntakeMotor(0.0);
	}

}

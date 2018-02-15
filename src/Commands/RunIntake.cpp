#include "RunIntake.h"
#include "OI.h"

RunIntake::RunIntake(double percent) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Intake::GetInstance());
	m_percent = percent;
}

// Called once when the command executes
void RunIntake::Initialize() {

	Intake::GetInstance()->SetIntakeMotor(m_percent);
//	if(m_on) {
//		if(m_reversed) {
//			Intake::GetInstance()->SetIntakeMotor(OUTTAKE_PERCENT);
//		}
//		if(m_reversedFull) {
//			Intake::GetInstance()->SetIntakeMotor(OUTTAKE_FULL_PERCENT);
//		}
//		else {
//			Intake::GetInstance()->SetIntakeMotor(INTAKE_PERCENT);
//		}
//
//	}
//	else {
//		Intake::GetInstance()->SetIntakeMotor(0.0);
//	}

}

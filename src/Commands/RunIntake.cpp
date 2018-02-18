#include "RunIntake.h"
#include "OI.h"
#include <iostream>

RunIntake::RunIntake(double percent) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Intake::GetInstance());
	m_percent = percent;
}

// Called once when the command executes
void RunIntake::Initialize() {

	Intake::GetInstance()->SetIntakeMotor(m_percent);

}

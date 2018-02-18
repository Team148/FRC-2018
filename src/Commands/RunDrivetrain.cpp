#include "RunDrivetrain.h"
#include "OI.h"

RunDrivetrain::RunDrivetrain() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	Drivetrain::GetInstance()->configClosedLoopVelocity();
//	m_on = on;
//	m_reversed = reversed;
}

// Called once when the command executes
void RunDrivetrain::Initialize() {

	Drivetrain::GetInstance()->SetDriveVelocity(70.0,70.0);
//	if(m_on) {
//		if(m_reversed) {
//			Drivetrain::GetInstance()->SetIntakeMotor(OUTTAKE_PERCENT);
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

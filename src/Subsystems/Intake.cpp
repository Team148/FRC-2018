#include "Intake.h"
#include "../RobotMap.h"
#include <iostream>

Intake *Intake::m_instance = 0;

Intake::Intake() : Subsystem("Intake"){

	//intake motors
	m_IntakeMotor1 = new WPI_TalonSRX(INTAKE_MOTOR_1);
	m_IntakeMotor2 = new WPI_TalonSRX(INTAKE_MOTOR_2);

	//intake motor configuration
	m_IntakeMotor1->SetSafetyEnabled(false);
}

Intake* Intake::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating Intake Class" << std::endl;
		m_instance = new Intake();
	}
	return m_instance;
}

void Intake::InitDefaultCommand() {

}

void Intake::SetIntakeMotor(float percent)
{
	m_IntakeMotor1->Set(ControlMode::PercentOutput, percent);
}

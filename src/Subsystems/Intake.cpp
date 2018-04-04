#include "Intake.h"
#include "../RobotMap.h"
#include <iostream>

Intake *Intake::m_instance = 0;

Intake::Intake() : Subsystem("Intake"){

	//intake motors
	m_IntakeMotor1 = new WPI_TalonSRX(INTAKE_MOTOR_1);
	m_IntakeMotor2 = new WPI_VictorSPX(INTAKE_MOTOR_2);

	m_IntakeMotor1->ConfigVoltageCompSaturation(12.0, 0);
	m_IntakeMotor1->EnableVoltageCompensation(true);

	m_IntakeMotor2->ConfigVoltageCompSaturation(12.0, 0);
	m_IntakeMotor2->EnableVoltageCompensation(true);

	m_IntakeMotor1->SetNeutralMode(NeutralMode::Brake);
	m_IntakeMotor2->SetNeutralMode(NeutralMode::Brake);

	//intake motor configuration
	m_IntakeMotor1->SetSafetyEnabled(false);
	m_IntakeMotor2->SetSafetyEnabled(false);

	m_IntakeMotor1->SetInverted(true);
	m_IntakeMotor2->SetInverted(false);
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
	m_IntakeMotor2->Set(ControlMode::PercentOutput, percent);
}

float Intake::GetAverageCurrent()
{
	return (m_IntakeMotor1->GetOutputCurrent() + m_IntakeMotor2->GetOutputCurrent())/2;
}



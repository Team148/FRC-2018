#include "Forklift.h"
#include "../RobotMap.h"
#include <iostream>

Forklift *Forklift::m_instance = 0;

Forklift::Forklift() : Subsystem("Forklift")
{

	//forklift motor
	m_ForkliftMotor1 = new WPI_TalonSRX(FORKLIFT_MOTOR_1);

	//forklift motor configuration
	m_ForkliftMotor1->SetNeutralMode(NeutralMode::Brake);

	m_ForkliftMotor1->EnableVoltageCompensation(true);

	m_ForkliftMotor1->ConfigVoltageCompSaturation(12.0,0);

	m_ForkliftMotor1->SetSafetyEnabled(false);
}

Forklift* Forklift::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating Climber Class" << std::endl;
		m_instance = new Forklift();
	}
	return m_instance;
}

void Forklift::InitDefaultCommand() {

}

void Forklift::Set(float percent) {
	m_ForkliftMotor1->Set(ControlMode::PercentOutput, percent);
}

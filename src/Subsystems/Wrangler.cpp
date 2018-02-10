#include "Wrangler.h"
#include "../RobotMap.h"
#include <iostream>

Wrangler *Wrangler::m_instance = 0;

Wrangler::Wrangler() : Subsystem("Wrangler")
{

	//forklift motor
	m_WranglerMotor1 = new WPI_VictorSPX(WRANGLER_MOTOR_1);

	//forklift motor configuration
	m_WranglerMotor1->SetNeutralMode(NeutralMode::Brake);

	m_WranglerMotor1->EnableVoltageCompensation(true);

	m_WranglerMotor1->ConfigVoltageCompSaturation(12.0,0);

	m_WranglerMotor1->SetSafetyEnabled(false);
}

Wrangler* Wrangler::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating Climber Class" << std::endl;
		m_instance = new Wrangler();
	}
	return m_instance;
}

void Wrangler::InitDefaultCommand() {

}

void Wrangler::SetWranglerMotor(float percent) {
	m_WranglerMotor1->Set(ControlMode::PercentOutput, percent);
}

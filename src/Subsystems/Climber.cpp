#include "Climber.h"
#include "../RobotMap.h"
#include <iostream>

Climber *Climber::m_instance = 0;

Climber::Climber() : Subsystem("Climber") {

	//climb motors
	m_ClimbMotor1 = new WPI_TalonSRX(CLIMBER_MOTOR_1);
	m_ClimbMotor2 = new WPI_TalonSRX(CLIMBER_MOTOR_2);
	//m_ClimbMotor3 = new WPI_TalonSRX(CLIMBER_MOTOR_3);

	//climb motor configuration
	m_ClimbMotor1->SetNeutralMode(NeutralMode::Brake);
	m_ClimbMotor2->SetNeutralMode(NeutralMode::Brake);
	//m_ClimbMotor3->SetNeutralMode(NeutralMode::Brake);

	m_ClimbMotor1->EnableVoltageCompensation(true);
	m_ClimbMotor2->EnableVoltageCompensation(true);
	//m_ClimbMotor3->EnableVoltageCompensation(true);

	//climber ONLY goes backwards
	m_ClimbMotor1->ConfigVoltageCompSaturation(12.0,0);
	m_ClimbMotor2->ConfigVoltageCompSaturation(12.0,0);
	//m_ClimbMotor3->ConfigVoltageCompSaturation(12.0,0);

	m_ClimbMotor1->SetSafetyEnabled(false);
	m_ClimbMotor2->SetSafetyEnabled(false);
	//m_ClimbMotor3->SetSafetyEnabled(false);
}

Climber* Climber::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating Climber Class" << std::endl;
		m_instance = new Climber();
	}
	return m_instance;
}

void Climber::InitDefaultCommand() {

}

void Climber::Set(float percent) {
	m_ClimbMotor1->Set(ControlMode::PercentOutput, percent);
	m_ClimbMotor2->Set(ControlMode::PercentOutput, -percent);
	//m_ClimbMotor3->Set(ControlMode::PercentOutput, -percent);
}

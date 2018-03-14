#include "Wrist.h"
#include "Commands/RunWrist.h"
#include <iostream>

Wrist *Wrist::m_instance = 0;

Wrist::Wrist() : Subsystem("Wrist") {

	m_wristMotor1 = new WPI_TalonSRX(WRIST_MOTOR_1);

	m_wristMotor1->ConfigNominalOutputForward(0,0);

	m_wristMotor1->ConfigNominalOutputReverse(0,0);

	m_wristMotor1->ConfigPeakOutputForward(1, 0);

	m_wristMotor1->ConfigPeakOutputForward(1, 0);

	m_wristMotor1->SetNeutralMode(NeutralMode::Brake);
}

Wrist* Wrist::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating Drivetrain Class" << std::endl;
		m_instance = new Wrist();
	}
	return m_instance;
}

void Wrist::InitDefaultCommand() {

}

void Wrist::SetWristMotor(float percent)
{
	m_wristMotor1->Set(ControlMode::PercentOutput, percent);
}

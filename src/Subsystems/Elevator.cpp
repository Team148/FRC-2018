#include "Elevator.h"
#include "../RobotMap.h"
#include <iostream>

Elevator *Elevator::m_instance = 0;

Elevator::Elevator() : Subsystem("Elevator") {

	//elevator motors
	m_ElevatorMotor1 = new WPI_TalonSRX(ELEVATOR_MOTOR_1);
	m_ElevatorMotor2 = new WPI_TalonSRX(ELEVATOR_MOTOR_2);
	//m_ElevatorMotor3 = new WPI_TalonSRX(ELEVATOR_MOTOR_3);

	//elevator motor configuration
	m_ElevatorMotor1->SetSafetyEnabled(false);
	m_ElevatorMotor2->SetSafetyEnabled(false);
	//m_ElevatorMotor3->SetSafetyEnabled(false);
}

Elevator* Elevator::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating Intake Class" << std::endl;
		m_instance = new Elevator();
	}
	return m_instance;
}

void Elevator::InitDefaultCommand() {

}

void Elevator::ConfigureOpenLoop() {

}

void Elevator::ConfigureClosedLoop() {

	m_isClosedLoop = 1;
}

bool Elevator::IsClosedLoop() {
	return m_isClosedLoop;
}

//implement this correctly before using, otherwise damage will occur
bool Elevator::IsElevatorUp() {
//	if(m_UpLimit)
//		return true;
//	else
//		return false;
	return true;
}


//implement this correctly before using, otherwise damage will occur
bool Elevator::IsElevatorDown() {
//	return !m_DownLimit->Get();
	return true;
}

#include "Elevator.h"
#include "Commands/ElevatorWithJoystick.h"
#include "../RobotMap.h"
#include <iostream>

Elevator *Elevator::m_instance = 0;

Elevator::Elevator() : Subsystem("Elevator") {

	//elevator motors
	m_ElevatorMotor1 = new WPI_TalonSRX(ELEVATOR_MOTOR_1);
	m_ElevatorMotor2 = new WPI_TalonSRX(ELEVATOR_MOTOR_2);
	//m_ElevatorMotor3 = new WPI_TalonSRX(ELEVATOR_MOTOR_3);

	m_ElevatorMotor2->Set(ControlMode::Follower, ELEVATOR_MOTOR_1);

	m_ElevatorMotor1->SetNeutralMode(NeutralMode::Brake);
//	m_ElevatorMotor2->SetNeutralMode(NeutralMode::Brake);
	//m_ElevatorMotor3->SetNeutralMode(NeutralMode::Brake);

	m_ElevatorMotor1->ConfigOpenloopRamp(1, 0);
//	m_ElevatorMotor2->ConfigOpenloopRamp(1, 0);

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
	SetDefaultCommand(new ElevatorWithJoystick());
}

void Elevator::JoystickControl(float ystick)
{
	m_ElevatorMotor1->Set(ControlMode::PercentOutput, ystick*ELEVATOR_OUTPUT_PERCENT);
}


void Elevator::ConfigOpenLoop()
{

}

void Elevator::ConfigClosedLoop() {
	m_ElevatorMotor1->Set(ControlMode::MotionMagic,0.0);
	m_ElevatorMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	m_ElevatorMotor1->SetSensorPhase(false);

	m_ElevatorMotor1->Config_kF(0, ELEVATOR_F, 0);
	m_ElevatorMotor1->Config_kP(0, ELEVATOR_P, 0);
	m_ElevatorMotor1->Config_kI(0, ELEVATOR_I, 0);
	m_ElevatorMotor1->Config_kD(0, ELEVATOR_D, 0);

	// zero sensor
	m_ElevatorMotor1->ConfigMotionCruiseVelocity(MOTION_MAGIC_VELOCITY, 0);
	m_ElevatorMotor1->ConfigMotionAcceleration(MOTION_MAGIC_ACCELERATION, 0);

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

int Elevator::GetElevatorPosition() {
	return m_ElevatorMotor1->GetSelectedSensorPosition(0);
}

int Elevator::GetElevatorVelocity() {
	return m_ElevatorMotor1->GetSelectedSensorVelocity(0);
}

void Elevator::SetElevatorPosition(double position) {
	m_ElevatorMotor1->Set(ControlMode::MotionMagic, position);
}

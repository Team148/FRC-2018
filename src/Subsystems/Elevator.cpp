#include "Elevator.h"
#include "Commands/ElevatorWithJoystick.h"
#include "../RobotMap.h"
#include <iostream>

Elevator *Elevator::m_instance = 0;

Elevator::Elevator() : Subsystem("Elevator") {

	//elevator motors
	m_ElevatorMotor1 = new WPI_TalonSRX(ELEVATOR_MOTOR_1);
	m_ElevatorMotor2 = new WPI_TalonSRX(ELEVATOR_MOTOR_2);

	m_ElevatorMotor2->Set(ControlMode::Follower, ELEVATOR_MOTOR_1);

	m_ElevatorMotor1->SetNeutralMode(NeutralMode::Brake);
	m_ElevatorMotor2->SetNeutralMode(NeutralMode::Brake);

	m_ElevatorMotor1->ConfigOpenloopRamp(1, 0);
	m_ElevatorMotor2->ConfigOpenloopRamp(0, 0);

	//elevator motor configuration
	m_ElevatorMotor1->SetSafetyEnabled(false);
	m_ElevatorMotor2->SetSafetyEnabled(false);

	m_ElevatorMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	m_ElevatorMotor1->SetSelectedSensorPosition(0,0,0);
}

Elevator* Elevator::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating Intake Class" << std::endl;
		m_instance = new Elevator();
	}
	return m_instance;
}

void Elevator::InitDefaultCommand() {
//	SetDefaultCommand(new ElevatorWithJoystick());
}

void Elevator::JoystickControl(float ystick)
{
	m_ElevatorMotor1->Set(ControlMode::PercentOutput, ystick*ELEVATOR_OUTPUT_PERCENT);
}


void Elevator::ConfigOpenLoop()
{

}

void Elevator::ConfigClosedLoop() {
	m_ElevatorMotor1->ConfigVoltageCompSaturation(11.0, 0);
	m_ElevatorMotor1->EnableVoltageCompensation(true);

	m_ElevatorMotor1->ConfigNominalOutputForward(0.0,0);
	m_ElevatorMotor1->ConfigNominalOutputReverse(0.0,0);

	m_ElevatorMotor1->ConfigPeakOutputReverse(-0.25,0);
	m_ElevatorMotor1->ConfigForwardSoftLimitThreshold(ELEVATOR_SOFT_LIMIT,0);

	m_ElevatorMotor1->Set(ControlMode::Position,0.0);
	m_ElevatorMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	m_ElevatorMotor1->SetSensorPhase(false);

	m_ElevatorMotor1->ConfigClosedloopRamp(0.25, 0);

	m_ElevatorMotor1->Config_kF(0, ELEVATOR_F, 0);
	m_ElevatorMotor1->Config_kP(0, ELEVATOR_P, 0);
	m_ElevatorMotor1->Config_kI(0, ELEVATOR_I, 0);
	m_ElevatorMotor1->Config_kD(0, ELEVATOR_D, 0);

	m_ElevatorMotor1->SetSelectedSensorPosition(0, 0, 0);

	m_isClosedLoop = 1;
}

void Elevator::ConfigNeutralClosedLoop() {
	m_ElevatorMotor1->Config_kF(0, ELEVATOR_ZERO_F, 0);
	m_ElevatorMotor1->Config_kP(0, ELEVATOR_P, 0);
	m_ElevatorMotor1->Config_kI(0, ELEVATOR_I, 0);
	m_ElevatorMotor1->Config_kD(0, ELEVATOR_D, 0);
}

bool Elevator::IsClosedLoop() {
	return m_isClosedLoop;
}

//implement this correctly before using, otherwise damage will occur
bool Elevator::IsElevatorUp() {
	//implement proper logic if you want to use this function
	return true;
}


//implement this correctly before using, otherwise damage will occur
bool Elevator::IsElevatorDown() {
	//implement proper logic if you want to use this function
	return true;
}

int Elevator::GetElevatorPosition() {
	return m_ElevatorMotor1->GetSelectedSensorPosition(0);
}

int Elevator::GetElevatorVelocity() {
	return m_ElevatorMotor1->GetSelectedSensorVelocity(0);
}

void Elevator::SetElevatorPosition(double a_position, double arb_ff)
{
	if(!m_isClosedLoop)
		ConfigClosedLoop();




	m_position = a_position;
	if(m_position < 1) m_position = 1; //prevent less than 1 numbers
//	double scaled_elevator_F = ELEVATOR_F / m_position;

//	m_ElevatorMotor1->Config_kF(0, scaled_elevator_F, 0);
	m_ElevatorMotor1->Set(ControlMode::Position, m_position, DemandType::DemandType_ArbitraryFeedForward, arb_ff);
}

void Elevator::SetElevatorEncoderZero() {
	m_ElevatorMotor1->SetSelectedSensorPosition(0,0,0);
}

void Elevator::IncrementElevatorPosition(double dPosition){
	if(!m_isClosedLoop)
		ConfigClosedLoop();

	double local_position = m_position;
	local_position += dPosition;

	SetElevatorPosition(local_position, ELEVATOR_F);
}

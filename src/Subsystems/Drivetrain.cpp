#include "Drivetrain.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/TankDriveJoystick.h"
#include "../RobotMap.h"
#include <iostream>

Drivetrain *Drivetrain::m_instance = 0;

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

	//left drive motors
	m_leftMotor1 = new WPI_TalonSRX(DRIVE_LEFTMOTOR_1);
	m_leftMotor2 = new WPI_VictorSPX(DRIVE_LEFTMOTOR_2);
	m_leftMotor3 = new WPI_VictorSPX(DRIVE_LEFTMOTOR_3);

	//right drive motors
	m_rightMotor1 = new WPI_TalonSRX(DRIVE_RIGHTMOTOR_1);
	m_rightMotor2 = new WPI_VictorSPX(DRIVE_RIGHTMOTOR_2);
	m_rightMotor3 = new WPI_VictorSPX(DRIVE_RIGHTMOTOR_3);

	m_leftMotor2->Follow(*m_leftMotor1);
	m_leftMotor3->Follow(*m_leftMotor1);

	m_rightMotor2->Follow(*m_rightMotor1);
	m_rightMotor3->Follow(*m_rightMotor1);

//	m_leftMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	m_leftMotor1->SetInverted(false);
	m_leftMotor2->SetInverted(false);
	m_leftMotor3->SetInverted(false);

//	m_rightMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);

	m_rightMotor1->SetInverted(true);
	m_rightMotor2->SetInverted(true);
	m_rightMotor3->SetInverted(true);

	//Set ALL motors to coast
	SetBrakeMode(0);

//	//set left motors 2 and 3 to follow mode
//	m_leftMotor2->Set(ControlMode::Follower,DRIVE_LEFTMOTOR_1);
//	m_leftMotor3->Set(ControlMode::Follower,DRIVE_LEFTMOTOR_1);
//	//set right motors 2 and 3 to follow mode
//	m_rightMotor2->Set(ControlMode::Follower,DRIVE_RIGHTMOTOR_1);
//	m_rightMotor3->Set(ControlMode::Follower,DRIVE_RIGHTMOTOR_1);

	//Set motors to safety disabled
	m_leftMotor1->SetSafetyEnabled(false);
	m_leftMotor2->SetSafetyEnabled(false);
	m_leftMotor3->SetSafetyEnabled(false);

	m_rightMotor1->SetSafetyEnabled(false);
	m_rightMotor2->SetSafetyEnabled(false);
	m_rightMotor3->SetSafetyEnabled(false);

	m_drive = new DifferentialDrive(*m_leftMotor1,*m_rightMotor1);
	m_drive->SetSafetyEnabled(false);

	//PDP
	//m_pdp = new PowerDistributionPanel();

	//pigeon gyro initialization
	pigeon = new PigeonIMU(PIGEON_GYRO);
	PigeonIMU::GeneralStatus generalStatus;

	//pigeon calibration
	pigeon->GetGeneralStatus(generalStatus);

}

Drivetrain* Drivetrain::GetInstance() {
	if (m_instance ==  0) {
		//std::cout << "info: GetInstance Creating Drivetrain Class" << std::endl;
		m_instance = new Drivetrain();
	}
	return m_instance;
}


void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::Arcade(double ystick, double xstick) {
	m_drive->ArcadeDrive(ystick,xstick);
}

void Drivetrain::Tank(double leftstick, double rightstick) {
	m_drive->TankDrive(leftstick,rightstick);
}


void Drivetrain::SetBrakeMode(bool on) {
	if(on) {
		m_leftMotor1->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
		m_leftMotor2->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
		m_leftMotor3->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
		m_rightMotor1->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
		m_rightMotor2->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
		m_rightMotor3->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	}
	else {
		m_leftMotor1->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
		m_leftMotor2->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
		m_leftMotor3->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
		m_rightMotor1->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
		m_rightMotor2->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
		m_rightMotor3->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
	}
}

void Drivetrain::configClosedLoop() {
	//left drive encoder initialize
	m_leftMotor1->Set(ControlMode::MotionProfile,0.0);
	m_leftMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	m_leftMotor1->SetInverted(false);
	m_leftMotor1->ConfigAllowableClosedloopError(0,0,0);
	m_leftMotor1->Set(0.0);

	//right drive encoder initialize
	m_rightMotor1->Set(ControlMode::MotionProfile,0.0);
	m_rightMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	m_rightMotor1->SetInverted(true);
	m_rightMotor1->ConfigAllowableClosedloopError(0,0,0);
	m_rightMotor1->Set(0.0);

	m_leftMotor1->ConfigNominalOutputForward(83,0);
	m_rightMotor1->ConfigNominalOutputForward(83,0);

	m_closedLoop = true;
}

bool Drivetrain::isClosedLoop() {
	return m_closedLoop;
}

int Drivetrain::updateLeftEncoder() {
	int value = 0;
	value = m_leftMotor1->GetSelectedSensorPosition(0);
	return value;
}

int Drivetrain::updateRightEncoder() {
	int value = 0;
	value = m_rightMotor1->GetSelectedSensorPosition(0);
	return value;
}

double Drivetrain::updateGyroYaw() {
	pigeon->GetYawPitchRoll(yawPitchRoll);

	return yawPitchRoll[0];
}

double Drivetrain::updateGyroPitch() {
	pigeon->GetYawPitchRoll(yawPitchRoll);

	return yawPitchRoll[1];
}

double Drivetrain::updateGyroRoll() {
	pigeon->GetYawPitchRoll(yawPitchRoll);

	return yawPitchRoll[2];
}

double Drivetrain::updatePigeon() {
	//need to include printout of current yaw
	//pigeon calibration

	pigeon->GetRawGyro(yawPitchRoll);

	return yawPitchRoll[0];
}

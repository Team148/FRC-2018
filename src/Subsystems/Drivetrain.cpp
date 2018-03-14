#include "Drivetrain.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/TankDriveJoystick.h"
#include "Timer.h"
#include "../RobotMap.h"
#include <iostream>
#include "SmartDashboard/SmartDashboard.h"
#include <cmath>

Drivetrain *Drivetrain::m_instance = 0;

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

	//left drive motors
	m_leftMotor1 = new WPI_TalonSRX(DRIVE_LEFTMOTOR_1);
	m_leftMotor2 = new WPI_TalonSRX(DRIVE_LEFTMOTOR_2);
	m_leftMotor3 = new WPI_TalonSRX(DRIVE_LEFTMOTOR_3);

	//right drive motors
	m_rightMotor1 = new WPI_TalonSRX(DRIVE_RIGHTMOTOR_1);
	m_rightMotor2 = new WPI_TalonSRX(DRIVE_RIGHTMOTOR_2);
	m_rightMotor3 = new WPI_TalonSRX(DRIVE_RIGHTMOTOR_3);

	m_leftMotor2->Follow(*m_leftMotor1);
	m_leftMotor3->Follow(*m_leftMotor1);

	m_rightMotor2->Follow(*m_rightMotor1);
	m_rightMotor3->Follow(*m_rightMotor1);

	m_leftMotor1->SetInverted(false);
	m_leftMotor2->SetInverted(false);
	m_leftMotor3->SetInverted(false);

	m_rightMotor1->SetInverted(true);
	m_rightMotor2->SetInverted(true);
	m_rightMotor3->SetInverted(true);

	m_leftMotor1->ConfigNominalOutputForward(0,0);
	m_rightMotor1->ConfigNominalOutputForward(0,0);

	m_leftMotor1->ConfigNominalOutputReverse(0,0);
	m_rightMotor1->ConfigNominalOutputReverse(0,0);

	m_leftMotor1->ConfigPeakOutputForward(1, 0);
	m_leftMotor1->ConfigPeakOutputReverse(-1, 0);

	m_rightMotor1->ConfigPeakOutputForward(1, 0);
	m_rightMotor1->ConfigPeakOutputReverse(-1, 0);

	//Set ALL motors to coast
	SetBrakeMode(0);

	//Set motors to safety disabled
	m_leftMotor1->SetSafetyEnabled(false);
	m_leftMotor2->SetSafetyEnabled(false);
	m_leftMotor3->SetSafetyEnabled(false);

	m_rightMotor1->SetSafetyEnabled(false);
	m_rightMotor2->SetSafetyEnabled(false);
	m_rightMotor3->SetSafetyEnabled(false);

	m_drive = new DifferentialDrive(*m_leftMotor1,*m_rightMotor1);
	m_drive->SetSafetyEnabled(false);
}

Drivetrain* Drivetrain::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating Drivetrain Class" << std::endl;
		m_instance = new Drivetrain();
	}
	return m_instance;
}


void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::Arcade(double xstick, double ystick) {
	m_drive->ArcadeDrive(xstick, ystick);
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

#include "Drivetrain.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/TankDriveJoystick.h"
#include "Timer.h"
#include "Util/UnitMaster.h"
#include "../RobotMap.h"
#include <iostream>
#include "SmartDashboard/SmartDashboard.h"

Drivetrain *Drivetrain::m_instance = 0;
UnitMaster unit_master;

//create yawPitchRoll array
double ypr [3];
double yawPitchRoll [3];

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

	m_leftMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	m_leftMotor1->SetInverted(false);
	m_leftMotor2->SetInverted(false);
	m_leftMotor3->SetInverted(false);

	m_rightMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);

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


	m_leftMotor1->Config_kF(0, DRIVETRAIN_F, 0);
	m_rightMotor1->Config_kF(0, DRIVETRAIN_F, 0);

	m_leftMotor1->Config_kP(0, DRIVETRAIN_P, 0);
	m_rightMotor1->Config_kP(0, DRIVETRAIN_P, 0);

	m_leftMotor1->Config_kI(0, DRIVETRAIN_I, 0);
	m_rightMotor1->Config_kI(0, DRIVETRAIN_I, 0);

	m_leftMotor1->Config_kD(0, DRIVETRAIN_D, 0);
	m_rightMotor1->Config_kD(0, DRIVETRAIN_D, 0);

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

	//PDP
	//m_pdp = new PowerDistributionPanel();

	//pigeon gyro initialization
	pigeon = new PigeonIMU(PIGEON_GYRO);
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

void Drivetrain::Arcade(double ystick, double xstick) {
	m_drive->ArcadeDrive(ystick,xstick);
}

void Drivetrain::Tank(double leftstick, double rightstick) {
	m_drive->TankDrive(leftstick,rightstick);
}

void Drivetrain::SetDriveVelocity(double left_velocity, double right_velocity)
{
//	std::cout << "DriveVelocityFromFunc: " << left_velocity << std::endl;
	double FA = 1; // what is FA

	double left_corrected_velocity = (DRIVETRAIN_F*left_velocity) + FA*  /getLeftDrivetrainError();




	m_leftMotor1->Set(ControlMode::Velocity, left_velocity);
	m_rightMotor1->Set(ControlMode::Velocity, right_velocity);




	frc::SmartDashboard::PutNumber("PathVelocityLeft", left_velocity);
	frc::SmartDashboard::PutNumber("PathVelocityRight", right_velocity);
	frc::SmartDashboard::PutNumber("LeftEncoderVelocity", getLeftDriveVelocity());
	frc::SmartDashboard::PutNumber("VelocityError", right_velocity-getRightDriveVelocity());
}
double *Drivetrain::GetCorrectedVelocitySetPoint(double left_velocity, double right_velocity, Segment *leftTrajectory, Segment *rightTrajectory)
{
	double FA = 1; // what is FA


	double corrected_velocity[1] = { 0 };

//	double left_corrected_velocity = (DRIVETRAIN_F*left_velocity) + FA*leftTrajectory[index]


	return corrected_velocity;
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
	m_leftMotor1->Set(ControlMode::Velocity,0.0);
	m_leftMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	m_leftMotor1->SetSensorPhase(false);
//	m_leftMotor1->ConfigAllowableClosedloopError(0,0,0);


	//right drive encoder initialize
	m_rightMotor1->Set(ControlMode::Velocity,0.0);
	m_rightMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
	m_rightMotor1->SetSensorPhase(false);
//	m_rightMotor1->ConfigAllowableClosedloopError(0,0,0);
//	m_rightMotor1->Set(0.0);

	m_leftMotor1->ConfigNominalOutputForward(0,0);
	m_rightMotor1->ConfigNominalOutputForward(0,0);

	m_leftMotor1->ConfigVoltageCompSaturation(12.0, 0);
	m_leftMotor1->EnableVoltageCompensation(true);

	m_rightMotor1->ConfigVoltageCompSaturation(12.0, 0);
	m_rightMotor1->EnableVoltageCompensation(true);


	m_leftMotor1->Config_kF(0, DRIVETRAIN_F, 0);
	m_rightMotor1->Config_kF(0, DRIVETRAIN_F, 0);

	m_leftMotor1->Config_kP(0, DRIVETRAIN_P, 0);
	m_rightMotor1->Config_kP(0, DRIVETRAIN_P, 0);

	m_leftMotor1->Config_kI(0, DRIVETRAIN_I, 0);
	m_rightMotor1->Config_kI(0, DRIVETRAIN_I, 0);

//	m_leftMotor1->Config_IntegralZone(0, 300, 0);
//	m_rightMotor1->Config_IntegralZone(0, 300, 0);


	m_leftMotor1->Config_kD(0, DRIVETRAIN_D, 0);
	m_rightMotor1->Config_kD(0, DRIVETRAIN_D, 0);
	SetBrakeMode(1);


	m_closedLoop = true;
}

void Drivetrain::configOpenLoop()
{
	m_leftMotor1->Set(ControlMode::PercentOutput, 0.0);
	m_rightMotor1->Set(ControlMode::PercentOutput, 0.0);

	m_leftMotor1->EnableVoltageCompensation(false);
	m_rightMotor1->EnableVoltageCompensation(false);
	m_leftMotor1->ConfigNominalOutputForward(0,0);
	m_rightMotor1->ConfigNominalOutputForward(0,0);

	m_leftMotor1->ConfigNominalOutputReverse(0,0);
	m_rightMotor1->ConfigNominalOutputReverse(0,0);

	m_leftMotor1->ConfigPeakOutputForward(1, 0);
	m_leftMotor1->ConfigPeakOutputReverse(-1, 0);

	m_rightMotor1->ConfigPeakOutputForward(1, 0);
	m_rightMotor1->ConfigPeakOutputReverse(-1, 0);

	SetBrakeMode(false);
}

bool Drivetrain::isClosedLoop() {
	return m_closedLoop;
}

int Drivetrain::getLeftDrivePosition() {
	return m_leftMotor1->GetSelectedSensorPosition(0);

}

int Drivetrain::getRightDrivePosition() {
	return m_rightMotor1->GetSelectedSensorPosition(0);

}
double Drivetrain::getLeftDriveVelocity()
{
	return m_leftMotor1->GetSelectedSensorVelocity(0);
}
double Drivetrain::getRightDriveVelocity()
{
	return m_rightMotor1->GetSelectedSensorVelocity(0);
}

double Drivetrain::getLeftDrivetrainError()
{
	return m_leftMotor1->GetClosedLoopError(0);
}
double Drivetrain::getRightDrivetrainError()
{
	return m_rightMotor1->GetClosedLoopError(0);

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

void Drivetrain::getPigeonStatus() {
	PigeonIMU::GeneralStatus generalStatus;
	pigeon->GetGeneralStatus(generalStatus);
}

void Drivetrain::unitConversionTest()
{
//	unit_master.SetTicks(m_leftMotor1->GetSelectedSensorPosition(0));
//	unit_master.SetTicksPer100ms(m_leftMotor1->GetSelectedSensorVelocity(0));
//	unit_master.SetInches(18.8495);

//	std::cout << "Inches: " << unit_master.GetInches() << " Rotations: " << unit_master.GetRotations() << std::endl;
//	std::cout << "Time: " << frc::Timer::GetFPGATimestamp() << "InchesPerSec: " << unit_master.GetInchesPerSec() << std::endl;
//	std::cout << "Ticks: " << unit_master.GetTicks() << " Rotations: " << unit_master.GetRotations() << std::endl;

}

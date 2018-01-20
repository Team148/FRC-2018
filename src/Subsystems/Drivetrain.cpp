#include "Drivetrain.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/TankDriveJoystick.h"
#include "../RobotMap.h"

//Drivetrain *Drivetrain::m_instance

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

	//left drive motors
	m_leftMotor1 = new WPI_TalonSRX(DRIVE_LEFTMOTOR_1);
	m_leftMotor2 = new WPI_VictorSPX(DRIVE_LEFTMOTOR_2);
	m_leftMotor3 = new WPI_VictorSPX(DRIVE_LEFTMOTOR_3);
	//right drive motors
	m_rightMotor1 = new WPI_TalonSRX(DRIVE_RIGHTMOTOR_1);
	m_rightMotor2 = new WPI_VictorSPX(DRIVE_RIGHTMOTOR_2);
	m_rightMotor3 = new WPI_VictorSPX(DRIVE_RIGHTMOTOR_3);

	//Set ALL motors to coast
	SetBrakeMode(0);

	//set left motors 2 and 3 to follow mode
	m_leftMotor2->Set(ControlMode::Follower,DRIVE_LEFTMOTOR_1);
	m_leftMotor3->Set(ControlMode::Follower,DRIVE_LEFTMOTOR_1);
	//set right motors 2 and 3 to follow mode
	m_rightMotor2->Set(ControlMode::Follower,DRIVE_RIGHTMOTOR_1);
	m_rightMotor3->Set(ControlMode::Follower,DRIVE_RIGHTMOTOR_1);

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
	m_pdp = new PowerDistributionPanel();



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
		//    m_leftMotor3->ConfigNeutralMode(TalonSRX::NeutralMode::kNeutralMode_Brake);
		m_rightMotor1->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
		m_rightMotor2->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
		//    m_rightMotor3->ConfigNeutralMode(TalonSRX::NeutralMode::kNeutralMode_Brake);
	}
	else {
		m_leftMotor1->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
		m_leftMotor2->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
		//    m_leftMotor3->ConfigNeutralMode(TalonSRX::NeutralMode::kNeutralMode_Coast);
		m_rightMotor1->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
		m_rightMotor2->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
		//    m_rightMotor3->ConfigNeutralMode(TalonSRX::NeutralMode::kNeutralMode_Coast);
	}
}

/*
void Drivetrain::configClosedLoop() {
	m_leftMotor1->SetControlMode(TalonSRX::ControlMode::kSpeed);
	m_leftMotor1->SetFeedbackDevice(TalonSRX::FeedbackDevice::QuadEncoder);
	m_leftMotor1->ConfigEncoderCodesPerRev(256*ENCODER_GEAR_REDUCTION);
	m_leftMotor1->SetSensorDirection(true);
	m_leftMotor1->SetAllowableClosedLoopErr(0);
	m_leftMotor1->SetClosedLoopOutputDirection(true);
	m_leftMotor1->Set(0.0);
	m_rightMotor1->SetControlMode(TalonSRX::ControlMode::kSpeed);
	m_rightMotor1->SetFeedbackDevice(TalonSRX::FeedbackDevice::QuadEncoder);
	m_rightMotor1->ConfigEncoderCodesPerRev(256*ENCODER_GEAR_REDUCTION);
	m_rightMotor1->SetSensorDirection(false);
	m_rightMotor1->SetAllowableClosedLoopErr(0);
	m_rightMotor1->Set(0.0);

	m_leftMotor1->DisableNominalClosedLoopVoltage();
	m_rightMotor1->DisableNominalClosedLoopVoltage();
	m_leftMotor1->SetNominalClosedLoopVoltage(10.0f);
	m_rightMotor1->SetNominalClosedLoopVoltage(10.0f);
	//Setup Ramp Rate
	//m_leftMotor1->SetVoltageRampRate(24);
	//m_rightMotor1->SetVoltageRampRate(24);

	//Set some PIDF values

	m_leftMotor1->SetF(DRIVETRAIN_F);
	m_rightMotor1->SetF(DRIVETRAIN_F);
	m_leftMotor1->SetP(DRIVETRAIN_P);
	m_rightMotor1->SetP(DRIVETRAIN_P);
	m_leftMotor1->SetI(DRIVETRAIN_I);
	m_rightMotor1->SetI(DRIVETRAIN_I);
	m_leftMotor1->SetD(DRIVETRAIN_D);
	m_rightMotor1->SetD(DRIVETRAIN_D);
	//m_leftMotor1->SetIzone(DRIVETRAIN_I_ZONE_L);
	//m_rightMotor1->SetIzone(DRIVETRAIN_I_ZONE_R);


	m_closedLoop = true;
}
*/

bool Drivetrain::isClosedLoop() {
	return m_closedLoop;
}

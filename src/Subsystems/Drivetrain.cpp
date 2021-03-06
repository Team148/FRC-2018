#include "Drivetrain.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/TankDriveJoystick.h"
#include "Timer.h"
#include "Util/UnitMaster.h"
#include "../RobotMap.h"
#include <iostream>
#include "SmartDashboard/SmartDashboard.h"
#include <cmath>

#define DegreesToRadians(angleDegrees) ((angleDegrees) * M_PI/180)

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

	m_leftMotor1->ConfigVelocityMeasurementWindow(32, 0);
	m_leftMotor1->ConfigVelocityMeasurementPeriod(VelocityMeasPeriod::Period_10Ms , 0 );
	m_rightMotor1->ConfigVelocityMeasurementWindow(32, 0);
	m_rightMotor1->ConfigVelocityMeasurementPeriod(VelocityMeasPeriod::Period_10Ms , 0 );

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

	m_leftMotor1->Config_kF(0, DRIVETRAIN_F_VEL, 0);
	m_rightMotor1->Config_kF(0, DRIVETRAIN_F_VEL, 0);

	m_leftMotor1->Config_kP(0, DRIVETRAIN_P_VEL, 0);
	m_rightMotor1->Config_kP(0, DRIVETRAIN_P_VEL, 0);

	m_leftMotor1->Config_kI(0, DRIVETRAIN_I_VEL, 0);
	m_rightMotor1->Config_kI(0, DRIVETRAIN_I_VEL, 0);

	m_leftMotor1->Config_kD(0, DRIVETRAIN_D_VEL, 0);
	m_rightMotor1->Config_kD(0, DRIVETRAIN_D_VEL, 0);

	m_leftMotor1->Config_IntegralZone(0, 0, 0);
	m_rightMotor1->Config_kD(0, 0, 0);

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
	pigeon->SetStatusFramePeriod(PigeonIMU_StatusFrame::PigeonIMU_CondStatus_1_General, 5, 0);

	lineTracker_fr = new AnalogInput(LINETRACKER_FRONT_R);
	lineTracker_fl = new AnalogInput(LINETRACKER_FRONT_L);
	lineTracker_rr = new AnalogInput(LINETRACKER_REAR_R);
	lineTracker_rl = new AnalogInput(LINETRACKER_REAR_L);
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

void Drivetrain::SetLeftRight(double left, double right){
	m_leftMotor1->Set(left);
	m_rightMotor1->Set(right);
}

void Drivetrain::SetDriveVelocity(double left_velocity, double right_velocity)
{

	double FA = 1; // what is FA


//	std::cout << "DriveVelocityFromFunc: " << left_velocity << std::endl;

	m_leftMotor1->Set(ControlMode::Velocity, left_velocity);
	m_rightMotor1->Set(ControlMode::Velocity, right_velocity);



//	frc::SmartDashboard::PutNumber("PathVelocityLeft", left_velocity);
//	frc::SmartDashboard::PutNumber("PathVelocityRight", right_velocity);
//	frc::SmartDashboard::PutNumber("LeftEncoderVelocity", getLeftDriveVelocity());
//	frc::SmartDashboard::PutNumber("VelocityError", right_velocity-getRightDriveVelocity());
//	std::cout << "DriveVelocityFromFunc: " << right_velocity  << "VelocityError " << right_velocity-getRightDriveVelocity() << std::endl;

}

void Drivetrain::InitPathDriveHeading()
{
	initDriveHeading = getGyroYaw();
}
double Drivetrain::GetInitPathDriveHeading()
{
	return initDriveHeading;
}

double Drivetrain::getRobotPathHeading()
{
	double m_robot_heading = fmod(getGyroYaw()-initDriveHeading,360.0);

	if(m_robot_heading <0)
		m_robot_heading += 360.0;

	return m_robot_heading;
}

void Drivetrain::InitPathDrive()
{
	initLeftDrivePos = getLeftDrivePosition();
	initRightDrivePos = getRightDrivePosition();
}


void Drivetrain::SetPathDriveVelocity(double l_pos, double l_velo, double l_accel, double r_pos, double r_velo, double r_accel, double heading, bool isReverse, bool headingCorrectionOn, bool positionCorrectionOn){
	double m_l_pos = l_pos;
	double m_l_velo = l_velo;
	double m_l_accel = l_accel;
	double m_r_pos = r_pos;
	double m_r_velo = r_velo;
	double m_r_accel = r_accel;
	double m_heading = heading * 57.2958;


	if(isReverse)
	{
		m_l_pos = -r_pos;
		m_l_velo = -r_velo;
		m_l_accel = -r_accel;
		m_r_pos = -l_pos;
		m_r_velo = -l_velo;
		m_r_accel = -l_accel;
		m_heading = fmod(m_heading + 180.0,360.0);
	}


	unit_master.SetTicks(getLeftDrivePosition() - initLeftDrivePos);
	double cur_pos_l = unit_master.GetInches();
	unit_master.SetTicks(getRightDrivePosition() - initRightDrivePos);
	double cur_pos_r = unit_master.GetInches();

	double robot_heading = getRobotPathHeading();

	double heading_contrib = m_heading - robot_heading;

	if(heading_contrib<-180)
		heading_contrib += 360;
	if(heading_contrib>180)
		heading_contrib -= 360;

	frc::SmartDashboard::PutNumber("HeadingError", heading_contrib);
//	std::cout << "Delta Heading: " << heading_contrib << std::endl;

	if(!isReverse)
		heading_contrib *= DRIVETRAIN_PATH_KP_HEADING;
	else
		heading_contrib *= DRIVETRAIN_PATH_KP_HEADING_REVERSE;

//	heading_contrib = 0; //uncomment for no gyro mode

	double left_error = m_l_pos - cur_pos_l;
	double right_error = m_r_pos - cur_pos_r;

	frc::SmartDashboard::PutNumber("LeftPosError", left_error);
	frc::SmartDashboard::PutNumber("RightPosError", right_error);

	if(left_error > DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT) left_error = DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT;

	if(left_error < -DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT) left_error = -DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT;

	if(right_error > DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT) right_error = DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT;

	if(right_error < -DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT) right_error = -DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT;


	left_error = right_error = (left_error + right_error)*0.5;

//	positionCorrectionOn = false;

	if(!positionCorrectionOn)
		left_error = right_error = 0;

	if(!headingCorrectionOn)
		heading_contrib = 0;

//	std::cout << heading_contrib << std::endl;

	double left_output = 	(DRIVETRAIN_PATH_FV * m_l_velo) +
							(DRIVETRAIN_PATH_FA * m_l_accel) +
							(DRIVETRAIN_PATH_KP * left_error)
							- heading_contrib;
	double right_output =	(DRIVETRAIN_PATH_FV * m_r_velo) +
							(DRIVETRAIN_PATH_FA * m_r_accel) +
							(DRIVETRAIN_PATH_KP * right_error)
							+ heading_contrib;

	//check if output is saturated
	double left_sat_factor = fabs(left_output / DRIVETRAIN_MAX_VEL);
	double right_sat_factor = fabs(right_output / DRIVETRAIN_MAX_VEL);



//	if(left_sat_factor > 1.0) std::cout << "WARNING : LEFT SIDE SATURATED BY " << left_sat_factor << "x" << std::endl;
//	if(right_sat_factor > 1.0) std::cout << "WARNING : RIGHT SIDE SATURATED BY " << right_sat_factor << "x" << std::endl;

	double max_sat_factor = std::max(left_sat_factor, right_sat_factor);

	if(max_sat_factor > 1.0){
		left_output /= max_sat_factor;
		right_output /= max_sat_factor;
	}
	// end saturation check

	if(isReverse)
	{
		left_output = 	(DRIVETRAIN_PATH_FV * m_l_velo) +
								(DRIVETRAIN_PATH_FA * m_l_accel) +
								(DRIVETRAIN_PATH_KP_REVERSE * left_error)
								- heading_contrib;
		right_output =	(DRIVETRAIN_PATH_FV * m_r_velo) +
								(DRIVETRAIN_PATH_FA * m_r_accel) +
								(DRIVETRAIN_PATH_KP_REVERSE * right_error)
								+ heading_contrib;

	}
	frc::SmartDashboard::PutNumber("LeftTrajectory", unit_master.GetTicksPer100ms(m_l_velo));
	frc::SmartDashboard::PutNumber("LeftActual", getLeftDriveVelocity());
	frc::SmartDashboard::PutNumber("RightTrajectory", unit_master.GetTicksPer100ms(m_r_velo));
	frc::SmartDashboard::PutNumber("RightActual", getRightDriveVelocity());
	frc::SmartDashboard::PutNumber("LeftVelError", unit_master.GetInchesPerSec(getLeftDriveVelocity())-m_l_velo);
	frc::SmartDashboard::PutNumber("RightVelError", unit_master.GetInchesPerSec(getRightDriveVelocity())-m_r_velo);
	frc::SmartDashboard::PutNumber("LeftPosError", left_error);
	frc::SmartDashboard::PutNumber("RightPosError", right_error);
	frc::SmartDashboard::PutNumber("LeftSat", left_sat_factor);
	frc::SmartDashboard::PutNumber("RightSat",right_sat_factor);
	frc::SmartDashboard::PutNumber("LeftOutputError", unit_master.GetInchesPerSec(getLeftDriveVelocity())-left_output);
	frc::SmartDashboard::PutNumber("LeftOutputError", unit_master.GetInchesPerSec(getRightDriveVelocity())-right_output);


//	std::cout << "left_output: " << left_output << " right_output: " << right_output << std::endl;

//	std::cout << "VelocityError " << unit_master.GetTicksPer100ms(right_output)-getRightDriveVelocity() << std::endl;
//	std::cout << "Tra Left Pos: " << m_l_pos <<"Act Left Pos: " << cur_pos_l;
//	std::cout << "Position Error: " << (left_error + right_error)/2.0 << std::endl;

	SetDriveVelocity(unit_master.GetTicksPer100ms(left_output), unit_master.GetTicksPer100ms(right_output));

}

void Drivetrain::SetPathDriveKinematics(double l_pos, double l_velo, double l_accel, double r_pos, double r_velo, double r_accel, double heading, double dt, bool isReverse, bool headingCorrectionOn, bool positionCorrectionOn)
{
	double m_l_pos = l_pos;
	double m_l_velo = l_velo;
	double m_l_accel = l_accel;
	double m_r_pos = r_pos;
	double m_r_velo = r_velo;
	double m_r_accel = r_accel;
	double m_heading = heading * 57.2958;


	if(isReverse)
	{
		m_l_pos = -r_pos;
		m_l_velo = -r_velo;
		m_l_accel = -r_accel;
		m_r_pos = -l_pos;
		m_r_velo = -l_velo;
		m_r_accel = -l_accel;
		m_heading = fmod(m_heading + 180.0,360.0);
	}


	unit_master.SetTicks(getLeftDrivePosition() - initLeftDrivePos);
	double cur_pos_l = unit_master.GetInches();
	unit_master.SetTicks(getRightDrivePosition() - initRightDrivePos);
	double cur_pos_r = unit_master.GetInches();

	double robot_heading = getRobotPathHeading();

	double heading_contrib = m_heading - robot_heading;


	if(heading_contrib<-180)
		heading_contrib += 360;
	if(heading_contrib>180)
		heading_contrib -= 360;

	double heading_error = heading_contrib;

	frc::SmartDashboard::PutNumber("HeadingError", heading_contrib);
//	std::cout << "Delta Heading: " << heading_contrib << std::endl;

	if(!isReverse)
		heading_contrib *= DRIVETRAIN_PATH_KP_HEADING;
	else
		heading_contrib *= DRIVETRAIN_PATH_KP_HEADING_REVERSE;

//	heading_contrib = 0; //uncomment for no gyro mode

	double left_error = m_l_pos - cur_pos_l;
	double right_error = m_r_pos - cur_pos_r;

	frc::SmartDashboard::PutNumber("LeftPosError", left_error);
	frc::SmartDashboard::PutNumber("RightPosError", right_error);


//	if(left_error > DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT) left_error = DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT;
//
//	if(left_error < -DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT) left_error = -DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT;
//
//	if(right_error > DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT) right_error = DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT;
//
//	if(right_error < -DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT) right_error = -DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT;

//	double rotationsNeeded = heading_error/360; // 45/360 26pi
//	double inchesNeeded = rotationsNeeded*(DRIVETRAIN_BASE_DIAMETER*M_PI); // look into drivebase
//
//	frc::SmartDashboard::PutNumber("RotationsNeeded",rotationsNeeded);

	double avg_pos_error = (left_error + right_error)*0.5;
	double avg_pos_error_contrib = avg_pos_error * DRIVETRAIN_PATH_KP;

	if(avg_pos_error > DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT) avg_pos_error = DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT;
	if(avg_pos_error < -DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT) avg_pos_error = -DRIVETRAIN_MAX_VEL * DRIVETRAIN_PATH_POS_LIMIT;


	//double avg_vel = (m_l_velo + m_r_velo)*0.5;
	frc::SmartDashboard::PutNumber("AvgPosError", avg_pos_error);

//	double left_pos_change = avg_vel * dt + avg_pos_error - inchesNeeded;
//	double right_pos_change = avg_vel * dt + avg_pos_error + inchesNeeded;
//
//	double left_velocity_kinematics = left_pos_change / dt;
//	double right_velocity_kinematics = right_pos_change / dt;

	double delta_v = (DRIVETRAIN_BASE_DIAMETER * heading_error/57.2958) / (2*DRIVETRAIN_SCRUB_FACTOR);
//	double avg_pos_veloci
	double left_velocity_kinematics = m_l_velo - delta_v;
	double right_velocity_kinematics = m_r_velo + delta_v;

	double c_l_velocity = (left_velocity_kinematics + right_velocity_kinematics)*0.5;

	double left_pos_contrib = avg_pos_error_contrib * (left_velocity_kinematics/c_l_velocity);
	double right_pos_contrib = avg_pos_error_contrib * (right_velocity_kinematics/c_l_velocity);


	frc::SmartDashboard::PutNumber("LeftKinematicsVel", left_velocity_kinematics);
	frc::SmartDashboard::PutNumber("RightKinematicsVel", right_velocity_kinematics);



	positionCorrectionOn = false;
//	headingCorrectionOn = false;

	if(!positionCorrectionOn)
		left_error = right_error = 0;

	if(!headingCorrectionOn)
		heading_contrib = 0;

//	std::cout << heading_contrib << std::endl;

	double left_output = 	(DRIVETRAIN_PATH_FV * left_velocity_kinematics) +
							(DRIVETRAIN_PATH_FA * m_l_accel) +
							left_pos_contrib +
							- heading_contrib;
	double right_output =	(DRIVETRAIN_PATH_FV * right_velocity_kinematics) +
							(DRIVETRAIN_PATH_FA * m_r_accel) +
							right_pos_contrib +
							+ heading_contrib;

	//check if output is saturated
	double left_sat_factor = fabs(left_output / DRIVETRAIN_MAX_VEL);
	double right_sat_factor = fabs(right_output / DRIVETRAIN_MAX_VEL);



//	if(left_sat_factor > 1.0) std::cout << "WARNING : LEFT SIDE SATURATED BY " << left_sat_factor << "x" << std::endl;
//	if(right_sat_factor > 1.0) std::cout << "WARNING : RIGHT SIDE SATURATED BY " << right_sat_factor << "x" << std::endl;

	double max_sat_factor = std::max(left_sat_factor, right_sat_factor);

	if(max_sat_factor > 1.0){
		left_output /= max_sat_factor;
		right_output /= max_sat_factor;
	}
	// end saturation check

//	if(isReverse)
//	{
//		left_output = 	(DRIVETRAIN_PATH_FV * left_velocity_kinematics) +
//								(DRIVETRAIN_PATH_FA * m_l_accel) +
//								(DRIVETRAIN_PATH_KP_REVERSE * left_error)
//								- heading_contrib;
//		right_output =	(DRIVETRAIN_PATH_FV * right_velocity_kinematics) +
//								(DRIVETRAIN_PATH_FA * m_r_accel) +
//								(DRIVETRAIN_PATH_KP_REVERSE * right_error)
//								+ heading_contrib;
//	}
	frc::SmartDashboard::PutNumber("LeftTrajectory", unit_master.GetTicksPer100ms(m_l_velo));
	frc::SmartDashboard::PutNumber("LeftActual", getLeftDriveVelocity());
	frc::SmartDashboard::PutNumber("RightTrajectory", unit_master.GetTicksPer100ms(m_r_velo));
	frc::SmartDashboard::PutNumber("RightActual", getRightDriveVelocity());
	frc::SmartDashboard::PutNumber("LeftVelError", unit_master.GetInchesPerSec(getLeftDriveVelocity())-m_l_velo);
	frc::SmartDashboard::PutNumber("RightVelError", unit_master.GetInchesPerSec(getRightDriveVelocity())-m_r_velo);
	frc::SmartDashboard::PutNumber("LeftPosError", left_error);
	frc::SmartDashboard::PutNumber("RightPosError", right_error);
	frc::SmartDashboard::PutNumber("LeftSat", left_sat_factor);
	frc::SmartDashboard::PutNumber("RightSat",right_sat_factor);
	frc::SmartDashboard::PutNumber("LeftOutputError", unit_master.GetInchesPerSec(getLeftDriveVelocity())-left_output);
	frc::SmartDashboard::PutNumber("LeftOutputError", unit_master.GetInchesPerSec(getRightDriveVelocity())-right_output);

	std::cout << "left_output_SetPathDrive: " << left_output << "right_output_SetPathDrive: " << right_output << std::endl;


	SetDriveVelocity(unit_master.GetTicksPer100ms(left_output), unit_master.GetTicksPer100ms(right_output));
}

void Drivetrain::SetDrivePosition(double left_position, double right_position)
{
	m_leftMotor1->Set(ControlMode::Position, left_position);
	m_rightMotor1->Set(ControlMode::Position, right_position);
}
void Drivetrain::SetDrivePositionMagic(double left_position, double right_position)
{
	m_leftMotor1->Set(ControlMode::MotionMagic, left_position);
	m_rightMotor1->Set(ControlMode::MotionMagic, right_position);
}


void Drivetrain::SetEncoderPosition(int l, int r)
{
	m_leftMotor1->SetSelectedSensorPosition(l, 0, 0);
	m_rightMotor1->SetSelectedSensorPosition(r, 0, 0);
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


void Drivetrain::configDrivetrain(tDriveConfigs drive_config, double cruiseVelocity, double acceleration)
{
	if(drive_config == tDriveConfigs::OPEN_LOOP)
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

		m_current_drive_config = tDriveConfigs::OPEN_LOOP;
		std::cout << "CONFIG: OPEN LOOP" << std::endl;

	}
	if(drive_config == tDriveConfigs::VELOCITY_CONFIG || drive_config == tDriveConfigs::PATH_CONFIG)
	{
		//left drive encoder initialize
		m_leftMotor1->Set(ControlMode::Velocity,0.0);
		m_leftMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
		m_leftMotor1->SetSensorPhase(false);

		//right drive encoder initialize
		m_rightMotor1->Set(ControlMode::Velocity,0.0);
		m_rightMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
		m_rightMotor1->SetSensorPhase(false);

		m_leftMotor1->ConfigNominalOutputForward(0,0);
		m_rightMotor1->ConfigNominalOutputForward(0,0);

		m_leftMotor1->ConfigVoltageCompSaturation(12.0, 0);
		m_leftMotor1->EnableVoltageCompensation(true);

		m_rightMotor1->ConfigVoltageCompSaturation(12.0, 0);
		m_rightMotor1->EnableVoltageCompensation(true);

		m_leftMotor1->ConfigClosedloopRamp(0, 0);
		m_rightMotor1->ConfigClosedloopRamp(0, 0);

		m_leftMotor1->Config_kF(0, DRIVETRAIN_F_VEL, 0);
		m_rightMotor1->Config_kF(0, DRIVETRAIN_F_VEL, 0);

		m_leftMotor1->Config_kP(0, DRIVETRAIN_P_VEL, 0);
		m_rightMotor1->Config_kP(0, DRIVETRAIN_P_VEL, 0);

		m_leftMotor1->Config_kI(0, DRIVETRAIN_I_VEL, 0);
		m_rightMotor1->Config_kI(0, DRIVETRAIN_I_VEL, 0);

		m_leftMotor1->Config_kD(0, DRIVETRAIN_D_VEL, 0);
		m_rightMotor1->Config_kD(0, DRIVETRAIN_D_VEL, 0);

		if(drive_config == tDriveConfigs::PATH_CONFIG)
		{
			InitPathDrive();

			m_leftMotor1->ConfigNominalOutputReverse(-DRIVETRAIN_PATH_NOMINALOUT, 0);
			m_leftMotor1->ConfigNominalOutputForward(DRIVETRAIN_PATH_NOMINALOUT, 0);
			m_rightMotor1->ConfigNominalOutputReverse(-DRIVETRAIN_PATH_NOMINALOUT, 0);
			m_rightMotor1->ConfigNominalOutputForward(DRIVETRAIN_PATH_NOMINALOUT, 0);

			m_leftMotor1->ConfigVelocityMeasurementWindow(32, 0);
			m_leftMotor1->ConfigVelocityMeasurementPeriod(VelocityMeasPeriod::Period_10Ms , 0 );
			m_rightMotor1->ConfigVelocityMeasurementWindow(32, 0);
			m_rightMotor1->ConfigVelocityMeasurementPeriod(VelocityMeasPeriod::Period_10Ms , 0 );

			m_leftMotor1->SetStatusFramePeriod(StatusFrameEnhanced::Status_2_Feedback0,5,0);
			m_rightMotor1->SetStatusFramePeriod(StatusFrameEnhanced::Status_2_Feedback0,5,0);
			std::cout << "CONFIG: PATH (w vel)" << std::endl;

		}

		SetBrakeMode(true);

		m_current_drive_config = tDriveConfigs::VELOCITY_CONFIG;
		std::cout << "CONFIG: VELOCITY" << std::endl;

	}
	if(drive_config == tDriveConfigs::POSITION_CONFIG)
	{
		//left drive encoder initialize
		m_leftMotor1->Set(ControlMode::Position,0.0);
		m_leftMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
		m_leftMotor1->SetSensorPhase(false);
	//	m_leftMotor1->ConfigAllowableClosedloopError(0,0,0);

		m_leftMotor1->SetSelectedSensorPosition(0,0,0);
		m_rightMotor1->SetSelectedSensorPosition(0,0,0);
		//right drive encoder initialize
		m_rightMotor1->Set(ControlMode::Position,0.0);
		m_rightMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
		m_rightMotor1->SetSensorPhase(false);

		m_leftMotor1->ConfigNominalOutputForward(0,0);
		m_rightMotor1->ConfigNominalOutputForward(0,0);

		m_leftMotor1->ConfigVoltageCompSaturation(12.0, 0);
		m_leftMotor1->EnableVoltageCompensation(true);

		m_rightMotor1->ConfigVoltageCompSaturation(12.0, 0);
		m_rightMotor1->EnableVoltageCompensation(true);

		m_rightMotor1->ConfigClosedloopRamp(0, 0);
		m_rightMotor1->ConfigClosedloopRamp(0, 0);

		m_leftMotor1->Config_kF(0, DRIVETRAIN_F_POS, 0);
		m_rightMotor1->Config_kF(0, DRIVETRAIN_F_POS, 0);

		m_leftMotor1->Config_kP(0, DRIVETRAIN_P_POS, 0);
		m_rightMotor1->Config_kP(0, DRIVETRAIN_P_POS, 0);

		m_leftMotor1->Config_kI(0, DRIVETRAIN_I_POS, 0);
		m_rightMotor1->Config_kI(0, DRIVETRAIN_I_POS, 0);

		m_leftMotor1->Config_kD(0, DRIVETRAIN_D_POS, 0);
		m_rightMotor1->Config_kD(0, DRIVETRAIN_D_POS, 0);

		m_current_drive_config = tDriveConfigs::POSITION_CONFIG;

		SetBrakeMode(true);
		std::cout << "CONFIG: POSITION" << std::endl;
	}
	if(drive_config == tDriveConfigs::MOTION_MAGIC_CONFIG)
	{
		//left drive encoder initialize
				m_leftMotor1->Set(ControlMode::MotionMagic,0.0);
				m_leftMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
				m_leftMotor1->SetSensorPhase(false);


				//right drive encoder initialize
				m_rightMotor1->Set(ControlMode::MotionMagic,0.0);
				m_rightMotor1->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
				m_rightMotor1->SetSensorPhase(false);

				m_leftMotor1->ConfigNominalOutputForward(0,0);
				m_rightMotor1->ConfigNominalOutputForward(0,0);

				m_leftMotor1->ConfigVoltageCompSaturation(12.0, 0);
				m_leftMotor1->EnableVoltageCompensation(true);

				m_rightMotor1->ConfigVoltageCompSaturation(12.0, 0);
				m_rightMotor1->EnableVoltageCompensation(true);

				m_leftMotor1->ConfigClosedloopRamp(0, 0);
				m_rightMotor1->ConfigClosedloopRamp(0, 0);

				m_leftMotor1->Config_kF(0, DRIVETRAIN_F_MAJ, 0);
				m_rightMotor1->Config_kF(0, DRIVETRAIN_F_MAJ, 0);

				m_leftMotor1->Config_kP(0, DRIVETRAIN_P_MAJ, 0);
				m_rightMotor1->Config_kP(0, DRIVETRAIN_P_MAJ, 0);

				m_leftMotor1->Config_kI(0, DRIVETRAIN_I_MAJ, 0);
				m_rightMotor1->Config_kI(0, DRIVETRAIN_I_MAJ, 0);

				m_leftMotor1->Config_kD(0, DRIVETRAIN_D_MAJ, 0);
				m_rightMotor1->Config_kD(0, DRIVETRAIN_D_MAJ, 0);

				m_rightMotor1->ConfigMotionCruiseVelocity(unit_master.GetTicksPer100ms(cruiseVelocity), 0);
				m_rightMotor1->ConfigMotionAcceleration(unit_master.GetTicksPer100ms(acceleration), 0);

				m_leftMotor1->ConfigMotionCruiseVelocity(unit_master.GetTicksPer100ms(cruiseVelocity), 0);
				m_leftMotor1->ConfigMotionAcceleration(unit_master.GetTicksPer100ms(acceleration), 0);
				/* Remote 1 will be a pigeon */
//				m_leftMotor1->ConfigRemoteFeedbackFilter(	pigeon->GetDeviceNumber(),
//														RemoteSensorSource::RemoteSensorSource_GadgeteerPigeon_Yaw,
//														Constants.REMOTE_1,
//														Constants.kTimeoutMs);

				SetBrakeMode(true);

				m_current_drive_config = tDriveConfigs::MOTION_MAGIC_CONFIG;

				std::cout << "CONFIG: MOTION MAGIC" << std::endl;
	}

}
bool Drivetrain::isDrivetrainConfiged(tDriveConfigs drive_config)
{

	if(m_current_drive_config == drive_config)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//
//bool Drivetrain::isClosedLoopPosition() {
//	return m_closedLoopPosition;
//}
//bool Drivetrain::isClosedLoopVelocity() {
//	return m_closedLoopVelocity;
//}
//void Drivetrain::configPathLoop()
//{
//	configClosedLoopVelocity();
//
//	InitPathDrive();
//
//	m_leftMotor1->ConfigNominalOutputReverse(-DRIVETRAIN_PATH_NOMINALOUT, 0);
//	m_leftMotor1->ConfigNominalOutputForward(DRIVETRAIN_PATH_NOMINALOUT, 0);
//	m_rightMotor1->ConfigNominalOutputReverse(-DRIVETRAIN_PATH_NOMINALOUT, 0);
//	m_rightMotor1->ConfigNominalOutputForward(DRIVETRAIN_PATH_NOMINALOUT, 0);
//
//	m_leftMotor1->ConfigVelocityMeasurementWindow(32, 0);
//	m_leftMotor1->ConfigVelocityMeasurementPeriod(VelocityMeasPeriod::Period_10Ms , 0 );
//	m_rightMotor1->ConfigVelocityMeasurementWindow(32, 0);
//	m_rightMotor1->ConfigVelocityMeasurementPeriod(VelocityMeasPeriod::Period_10Ms , 0 );
//
//	m_leftMotor1->SetStatusFramePeriod(StatusFrameEnhanced::Status_2_Feedback0,5,0);
//	m_rightMotor1->SetStatusFramePeriod(StatusFrameEnhanced::Status_2_Feedback0,5,0);
//
//}


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

double Drivetrain::getLeftDriveVelocityError()
{
	return m_leftMotor1->GetClosedLoopError(0);
}
double Drivetrain::getRightDriveVelocityError()
{
	return m_rightMotor1->GetClosedLoopError(0);

}

double Drivetrain::getGyroYaw() {

	pigeon->GetYawPitchRoll(yawPitchRoll);
//	std::cout << yawPitchRoll[0] << std::endl;
	return yawPitchRoll[0];
}

double Drivetrain::getGyroPitch() {
	pigeon->GetYawPitchRoll(yawPitchRoll);

	return yawPitchRoll[1];
}

double Drivetrain::getGyroRoll() {
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

void Drivetrain::accumRobotPosition()
{
	static bool init = false;

	static double d_position = 0;
	static double lastPosition = 0;
	static double currentPosition = 0;

	if(!init)
	{
		unit_master.SetTicks((getRightDrivePosition() + getLeftDrivePosition())/2);
		lastPosition = unit_master.GetInches();
		init = true;

	}

	unit_master.SetTicks((getRightDrivePosition() + getLeftDrivePosition())/2);
	currentPosition = unit_master.GetInches();
	d_position = currentPosition - lastPosition;
	pos_x += d_position *cos(DegreesToRadians(getRobotPathHeading()));
	pos_y += d_position *sin(DegreesToRadians(getRobotPathHeading()));

	lastPosition = currentPosition;
}

double Drivetrain::getRobotPosition_x()
{
	return pos_x;
}
double Drivetrain::getRobotPosition_y()
{
	return pos_y;
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

bool Drivetrain::GetLineSenseR_L()
{
	return (lineTracker_rl->GetVoltage() < DRIVETRAIN_LINE_RR_THRESHOLD && lineTracker_rl->GetVoltage() > 1.0);
}


bool Drivetrain::GetLineSenseR_R()
{
	return (lineTracker_rr->GetVoltage() < DRIVETRAIN_LINE_RR_THRESHOLD && lineTracker_rr->GetVoltage() > 1.0);
}

bool Drivetrain::GetLineSenseF_L()
{
	return (lineTracker_fl->GetVoltage() < DRIVETRAIN_LINE_RR_THRESHOLD && lineTracker_fl->GetVoltage() > 1.0);
}


bool Drivetrain::GetLineSenseF_R()
{
	return (lineTracker_fr->GetVoltage() < DRIVETRAIN_LINE_RR_THRESHOLD && lineTracker_fr->GetVoltage() > 1.0);
}

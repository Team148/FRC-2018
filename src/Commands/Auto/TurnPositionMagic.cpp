#include "TurnPositionMagic.h"
#include "../../Subsystems/Drivetrain.h"
#include "Constants.h"
#include <iostream>



TurnPositionMagic::TurnPositionMagic(double heading, double timeOut, double cruiseVelocity, double acceleration)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	m_heading = heading;
	m_time_out = timeOut;
	m_cruiseVelocity = cruiseVelocity;
	m_acceleration = acceleration;
}

// Called just before this Command runs the first time
void TurnPositionMagic::Initialize()
{
//	m_end_angle = Drivetrain::GetInstance()->getGyroYaw() + m_given_angle;
	m_isFinished = false;
	m_cur_heading = Drivetrain::GetInstance()->getRobotPathHeading();

	m_l_init_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_l_cur_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_r_init_pos = Drivetrain::GetInstance()->getRightDrivePosition();
	m_r_cur_pos = Drivetrain::GetInstance()->getRightDrivePosition();


//	if(m_is_clockwise) m_heading = -1*(360 - m_heading);

	Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::MOTION_MAGIC_CONFIG, m_cruiseVelocity, m_acceleration);

	m_l_cur_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_r_cur_pos = Drivetrain::GetInstance()->getRightDrivePosition();

	m_cur_heading = Drivetrain::GetInstance()->getRobotPathHeading();

	m_heading_err = (m_heading - m_cur_heading);
	if(m_heading_err<-180)
		m_heading_err += 360;
	if(m_heading_err>180)
		m_heading_err -= 360;
	double rotationsNeeded = m_heading_err/360; // 45/360 26pi
	double inchesNeeded = rotationsNeeded*(DRIVETRAIN_BASE_DIAMETER*M_PI); // look into drivebase
	ticksNeeded = unit_master.GetTicks(inchesNeeded, tUnits::INCHES);

	m_l_pos_out = m_l_init_pos - ticksNeeded;
	m_r_pos_out =  m_r_init_pos + ticksNeeded;

	SetTimeout(m_time_out);




}

// Called repeatedly when this Command is scheduled to run
void TurnPositionMagic::Execute()
{

	m_cur_heading = Drivetrain::GetInstance()->getRobotPathHeading();

	m_heading_err = (m_heading - m_cur_heading);
	if(m_heading_err<-180)
		m_heading_err += 360;
	if(m_heading_err>180)
		m_heading_err -= 360;
	double rotationsNeeded = m_heading_err/360; // 45/360 26pi
	double inchesNeeded = rotationsNeeded*(DRIVETRAIN_BASE_DIAMETER*M_PI); // look into drivebase
	ticksNeeded = unit_master.GetTicks(inchesNeeded, tUnits::INCHES);

	m_l_cur_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_r_cur_pos = Drivetrain::GetInstance()->getRightDrivePosition();

	double m_pos_err_l = (init_ticksNeeded - ticksNeeded + m_l_cur_pos - m_l_init_pos);
	double m_pos_err_r = (init_ticksNeeded + ticksNeeded + m_r_cur_pos - m_r_init_pos);

//	double m_pos_traveled_l = (m_l_cur_pos - m_l_init_pos);
//	double m_pos_traveled_r = (m_r_cur_pos - m_r_init_pos);

	//m_r_pos_out += (m_r_pos_out - m_pos_err_r);

//	m_l_pos_out -= m_pos_err_l;
//	m_r_pos_out += m_pos_err_r;

	Drivetrain::GetInstance()->SetDrivePositionMagic(m_l_pos_out, m_r_pos_out);

	frc::SmartDashboard::PutNumber("AngleError", m_heading_err);

	frc::SmartDashboard::PutNumber("m_l_pos_out", m_l_pos_out);
	frc::SmartDashboard::PutNumber("m_r_pos_out", m_r_pos_out);

	frc::SmartDashboard::PutNumber("m_pos_err_l", m_pos_err_l);
	frc::SmartDashboard::PutNumber("m_pos_err_r", m_pos_err_r);

	frc::SmartDashboard::PutNumber("InchesNeeded", inchesNeeded);


	//std::cout << "positionOutput_TICKS: "<< m_output << "positionOutput_INCHES" << inchesNeeded << std::endl;

//	if(abs(m_heading_err) < DRIVE_ANGLE_TOLERANCE) m_isFinished = true;

//	if(abs(m_heading_err) < DRIVE_ANGLE_TOLERANCE) m_isFinished = true; figure out


}

// Make this return true when this Command no longer needs to run execute()
bool TurnPositionMagic::IsFinished() {
	return m_isFinished || IsTimedOut();

}

// Called once after isFinished returns true
void TurnPositionMagic::End() {
	std::cout << "FINISHED: TurnPosition" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnPositionMagic::Interrupted() {
	End();
}

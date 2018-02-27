#include "TurnPosition.h"
#include "../../Subsystems/Drivetrain.h"
#include "Constants.h"
#include <iostream>

TurnPosition::TurnPosition(double angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_given_angle = angle;
	Requires(Drivetrain::GetInstance());
}

// Called just before this Command runs the first time
void TurnPosition::Initialize()
{
	m_end_angle = Drivetrain::GetInstance()->getGyroYaw() + m_given_angle;
	m_cur_angle = Drivetrain::GetInstance()->getGyroYaw();

	m_l_init_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_l_cur_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_r_init_pos = Drivetrain::GetInstance()->getRightDrivePosition();
	m_r_cur_pos = Drivetrain::GetInstance()->getRightDrivePosition();

	Drivetrain::GetInstance()->configClosedLoopPosition();
	Drivetrain::GetInstance()->SetBrakeMode(true);

	SetTimeout(2.0);

}

// Called repeatedly when this Command is scheduled to run
void TurnPosition::Execute()
{
	m_cur_angle = Drivetrain::GetInstance()->getGyroYaw();
	m_angle_err = m_end_angle - m_cur_angle;
	double rotationsNeeded = m_angle_err/360; // 45/360 26pi
	double inchesNeeded = rotationsNeeded*(DRIVETRAIN_BASE_DIAMETER*M_PI); // look into drivebase
	double ticksNeeded = unit_master.GetTicks(inchesNeeded, tUnits::INCHES);


	m_l_cur_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_r_cur_pos = Drivetrain::GetInstance()->getRightDrivePosition();

//	m_l_pos_err = m_l_init_pos - m_l_cur_pos;
//	m_r_pos_err = m_r_init_pos - m_r_cur_pos; // NEED TO FEEDBACK POSITION CORRECT TIMEOUT

		m_l_cur_pos -= ticksNeeded/2.0;
		m_r_cur_pos += ticksNeeded/2.0;


	Drivetrain::GetInstance()->SetDrivePosition(m_l_cur_pos, m_r_cur_pos);
	std::cout << "PIGEON ERROR: " << m_angle_err << std::endl;
	//std::cout << "positionOutput_TICKS: "<< m_output << "positionOutput_INCHES" << inchesNeeded << std::endl;

	if(abs(m_angle_err) < DRIVE_ANGLE_TOLERANCE) m_isFinished = true;

}

// Make this return true when this Command no longer needs to run execute()
bool TurnPosition::IsFinished() {
	return m_isFinished || IsTimedOut();
}

// Called once after isFinished returns true
void TurnPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnPosition::Interrupted() {

}

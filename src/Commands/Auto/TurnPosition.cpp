#include "TurnPosition.h"
#include "../../Subsystems/Drivetrain.h"
#include "Constants.h"
#include <iostream>



TurnPosition::TurnPosition(double heading, double timeOut)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	m_heading = heading;
	m_time_out = timeOut;
}

// Called just before this Command runs the first time
void TurnPosition::Initialize()
{
//	m_end_angle = Drivetrain::GetInstance()->getGyroYaw() + m_given_angle;
	m_isFinished = false;
	m_cur_heading = Drivetrain::GetInstance()->getRobotPathHeading();

	m_l_init_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_l_cur_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_r_init_pos = Drivetrain::GetInstance()->getRightDrivePosition();
	m_r_cur_pos = Drivetrain::GetInstance()->getRightDrivePosition();


//	if(m_is_clockwise) m_heading = -1*(360 - m_heading);

	Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::POSITION_CONFIG);

	SetTimeout(m_time_out);

}

// Called repeatedly when this Command is scheduled to run
void TurnPosition::Execute()
{
	m_cur_heading = Drivetrain::GetInstance()->getRobotPathHeading();

	m_heading_err = (m_heading - m_cur_heading);
	if(m_heading_err<-180)
		m_heading_err += 360;
	if(m_heading_err>180)
		m_heading_err -= 360;
	double rotationsNeeded = m_heading_err/360; // 45/360 26pi
	double inchesNeeded = rotationsNeeded*(DRIVETRAIN_BASE_DIAMETER*M_PI); // look into drivebase
	double ticksNeeded = unit_master.GetTicks(inchesNeeded, tUnits::INCHES);


	m_l_cur_pos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_r_cur_pos = Drivetrain::GetInstance()->getRightDrivePosition();


	m_l_cur_pos -= ticksNeeded;
	m_r_cur_pos += ticksNeeded;

	Drivetrain::GetInstance()->SetDrivePosition(m_l_cur_pos, m_r_cur_pos);

	frc::SmartDashboard::PutNumber("AngleError", m_heading_err);

	frc::SmartDashboard::PutNumber("m_l_cur_pos", m_l_cur_pos);
	frc::SmartDashboard::PutNumber("m_r_cur_pos", m_r_cur_pos);


	//std::cout << "positionOutput_TICKS: "<< m_output << "positionOutput_INCHES" << inchesNeeded << std::endl;

//	if(abs(m_heading_err) < DRIVE_ANGLE_TOLERANCE) m_isFinished = true;

//	if(abs(m_heading_err) < DRIVE_ANGLE_TOLERANCE) m_isFinished = true; figure out


}

// Make this return true when this Command no longer needs to run execute()
bool TurnPosition::IsFinished() {
	return m_isFinished || IsTimedOut();

}

// Called once after isFinished returns true
void TurnPosition::End() {
	std::cout << "FINISHED: TurnPosition" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnPosition::Interrupted() {
	End();
}

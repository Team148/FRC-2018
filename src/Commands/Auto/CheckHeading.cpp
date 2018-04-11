/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CheckHeading.h"
#include "../../Subsystems/Drivetrain.h"
#include "constants.h"


CheckHeading::CheckHeading(double heading, double tolerance, double timeout) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_timeOut = timeout;
	m_heading = heading;
	m_tolerance = tolerance;
}

// Called just before this Command runs the first time
void CheckHeading::Initialize() {
	m_isFinished = false;
	SetTimeout(m_timeOut);


}

// Called repeatedly when this Command is scheduled to run
void CheckHeading::Execute() {
	double m_cur_heading = Drivetrain::GetInstance()->getRobotPathHeading();
	m_cur_heading = Drivetrain::GetInstance()->getRobotPathHeading();

	double m_heading_err = (m_heading - m_cur_heading);
	if(m_heading_err<-180)
		m_heading_err += 360;
	if(m_heading_err>180)
		m_heading_err -= 360;

	if(fabs(m_heading_err) <= m_tolerance)
	{
		m_isFinished = true;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool CheckHeading::IsFinished() {
	std::cout << "CheckHeading Finished" << std::endl;
	return m_isFinished || IsTimedOut();
}

// Called once after isFinished returns true
void CheckHeading::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CheckHeading::Interrupted() {

}

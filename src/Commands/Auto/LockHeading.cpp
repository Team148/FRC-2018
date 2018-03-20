#include "LockHeading.h"
#include "../../Subsystems/Drivetrain.h"
#include "Constants.h"
#include <iostream>

LockHeading::LockHeading(double heading) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

}

// Called just before this Command runs the first time
void LockHeading::Initialize() {
	m_cur_heading = Drivetrain::GetInstance()->getRobotPathHeading();;
	Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::VELOCITY_CONFIG);


}

// Called repeatedly when this Command is scheduled to run
void LockHeading::Execute() {
	m_cur_heading = Drivetrain::GetInstance()->getRobotPathHeading();
	m_heading_err = m_heading - m_cur_heading;
	double rotationsNeeded = m_heading_err/360; // 45/360 26pi
	double inchesNeeded = rotationsNeeded*(DRIVETRAIN_BASE_DIAMETER*M_PI); // look into drivebase
	double ticksNeeded = unit_master.GetTicks(inchesNeeded, tUnits::INCHES);

	m_velocity_set = m_max_velocity*(m_heading_err/m_max_allowed_error);


	Drivetrain::GetInstance()->SetDriveVelocity(unit_master.GetTicksPer100ms(-m_velocity_set), unit_master.GetTicksPer100ms(m_velocity_set));

}

// Make this return true when this Command no longer needs to run execute()
bool LockHeading::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LockHeading::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LockHeading::Interrupted() {

}

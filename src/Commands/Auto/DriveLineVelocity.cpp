#include <Commands/Auto/DriveLineVelocity.h>
#include <Util/UnitMaster.h>
#include <iostream>

UnitMaster unit_master_conv1;



DriveLineVelocity::DriveLineVelocity(double cruise_velocity, double final_velocity, double heading, double positionTimeout) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	std::cout << "is constructing DriveLineVelocity" <<  cruise_velocity << final_velocity <<  std::endl;
	m_cruiseVelocity = cruise_velocity;
	m_finalVelocity = final_velocity;
	m_positionTimeout = unit_master_conv1.GetTicks(positionTimeout, tUnits::INCHES);
	//check is we're going backwards


	//check if the requested velocity is too high
	if(m_cruiseVelocity > m_maxdrivevelocity) {
		m_cruiseVelocity = m_maxdrivevelocity;
	}
	m_heading = heading;
}



// Called just before this Command runs the first time
void DriveLineVelocity::Initialize() {

	std::cout << "is initializing" << std::endl;
	std::cout << "posTimeout: " << m_positionTimeout << std::endl;

	Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::PATH_CONFIG);

	m_leftStartPos = Drivetrain::GetInstance()->getLeftDrivePosition();
	m_rightStartPos = Drivetrain::GetInstance()->getRightDrivePosition();

//	m_distanceTicks = (m_travelDistance*TICKS_PER_ROTATIONS)/WHEEL_CIRC_INCHES;

	//reset isFinished
	m_isFinished=0;


}

// Called repeatedly when this Command is scheduled to run
void DriveLineVelocity::Execute() {

	double m_leftPos = Drivetrain::GetInstance()->getLeftDrivePosition();
	double m_rightPos = Drivetrain::GetInstance()->getRightDrivePosition();

	double distanceTravelled =  ((m_leftPos+m_rightPos)/2) - ((m_leftStartPos+m_rightStartPos)/2);


	Drivetrain::GetInstance()->SetPathDriveVelocity(0, m_cruiseVelocity, 0, 0, m_cruiseVelocity, 0, m_heading, false, true, false);

	if(Drivetrain::GetInstance()->GetLineSenseF_L() || Drivetrain::GetInstance()->GetLineSenseF_R())
	{
		std::cout << "Hit Line Sensor" << std::endl;
		m_isFinished = true;
	}
	if(distanceTravelled >= m_positionTimeout)
	{
		std::cout << "Position Timeout" << std::endl;
		m_isFinished = true;
	}
}




// Make this return true when this Command no longer needs to run execute()
bool DriveLineVelocity::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void DriveLineVelocity::End() {
	Drivetrain::GetInstance()->SetDriveVelocity(m_finalVelocity, m_finalVelocity);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLineVelocity::Interrupted() {
	End();
}

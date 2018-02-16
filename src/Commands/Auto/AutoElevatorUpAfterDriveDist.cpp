#include <Commands/Auto/AutoElevatorUpAfterDriveDist.h>

ElevatorUpAfterDriveDist::ElevatorUpAfterDriveDist(bool on,int position, double inchesToDrive) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	Requires(Elevator::GetInstance());

	m_on = on;
	m_position = position;
	m_inchesToDrive = inchesToDrive;
}

// Called just before this Command runs the first time
void ElevatorUpAfterDriveDist::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ElevatorUpAfterDriveDist::Execute() {
	double m_posAvg;
	m_posAvg = (Drivetrain::GetInstance()->getLeftDrivePosition() + Drivetrain::GetInstance()->getRightDrivePosition()) * (WHEEL_CIRC_INCHES/TICKS_PER_ROTATIONS);
	if(m_posAvg >= m_inchesToDrive )
	{
		if (m_on)
			{
				Elevator::GetInstance()->SetElevatorPosition(m_position);
			}
			else
			{
				Elevator::GetInstance()->SetElevatorPosition(0.0);
			}
	}


}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorUpAfterDriveDist::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ElevatorUpAfterDriveDist::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorUpAfterDriveDist::Interrupted() {

}

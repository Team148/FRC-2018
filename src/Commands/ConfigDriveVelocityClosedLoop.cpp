#include "ConfigDriveVelocityClosedLoop.h"
#include "../Subsystems/Drivetrain.h"

ConfigDriveVelocityClosedLoop::ConfigDriveVelocityClosedLoop(bool closedloop) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());

	m_closedloop = closedloop;
}

// Called once when the command executes
void ConfigDriveVelocityClosedLoop::Initialize()
{
	if(m_closedloop)
	{
		Drivetrain::GetInstance()->configClosedLoop();
	}
	else
	{
		Drivetrain::GetInstance()->SetBrakeMode(false);
		Drivetrain::GetInstance()->configOpenLoop();
	}
}

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
		Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::VELOCITY_CONFIG);


	}
	else
	{
		Drivetrain::GetInstance()->SetBrakeMode(false);
		Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::OPEN_LOOP);

	}
}

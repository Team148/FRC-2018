#include "SetDrivetrainVelocity.h"
#include "OI.h"
#include <iostream>


SetDrivetrainVelocity::SetDrivetrainVelocity(double velocity) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	m_velocity = unit_master.GetTicksPer100ms(velocity);
}

// Called just before this Command runs the first time
void SetDrivetrainVelocity::Initialize()
{


	Drivetrain::GetInstance()->SetDriveVelocity(m_velocity, m_velocity);
	std::cout << "velocity set" << std::endl;
//	m_isFinished = true;
}

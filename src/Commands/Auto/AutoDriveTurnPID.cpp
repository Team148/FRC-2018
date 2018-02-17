/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoDriveTurnPID.h"
#include <iostream>


AutoDriveTurnPID::AutoDriveTurnPID(double degrees) {
	Requires(Drivetrain::GetInstance());
	m_degreesToTurn = degrees;

}

// Called just before this Command runs the first time
void AutoDriveTurnPID::Initialize() {
	Drivetrain::GetInstance()->configOpenLoop();

	m_intailAngle = Drivetrain::GetInstance()->getGyroYaw();
	Drivetrain::GetInstance()->SetBrakeMode(true);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveTurnPID::Execute() {
	 float currentError = (Drivetrain::GetInstance()->getGyroYaw() + m_degreesToTurn)  - m_intailAngle;
	 m_cumlativeError += currentError * TIME_STEP;

	 output = P_VALUE * currentError + I_VALUE*m_cumlativeError;

	 Drivetrain::GetInstance()->Arcade(output, 0);

	 std::cout << "Output: " << output << std::endl;
	 std::cout << "current Error: " << currentError << std::endl;

	 //std::cout << "current Angle: " << ((Drivetrain::GetInstance()->getGyroYaw() + m_degreesToTurn)  - m_intailAngle)  << std::endl;


	 if(abs(currentError) <= TURN_TOLERENCE   )
	 {
		 std::cout << "Done " << currentError << std::endl;
		 //Drivetrain::GetInstance()->Arcade(-output, 0);
		 Drivetrain::GetInstance()->Arcade(0, 0);
		 m_isFinished = true;
	 }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTurnPID::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void AutoDriveTurnPID::End() {
	m_isFinished = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveTurnPID::Interrupted() {
	m_isFinished = false;
}

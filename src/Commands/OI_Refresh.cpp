#include "OI_Refresh.h"
#include "OI.h"
#include <iostream>
#include "Subsystems/Elevator.h"

OI_Refresh::OI_Refresh() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void OI_Refresh::Initialize() {
	//Elevator::GetInstance()->SetElevatorPosition(ELEVATOR_ZERO);

}

// Called repeatedly when this Command is scheduled to run
void OI_Refresh::Execute() {
	if(fabs(OI::GetInstance()->opStick->GetRawAxis(1)) > ELEVATOR_MANUAL_DEADBAND)
	{

		double rawAxis1 =  -OI::GetInstance()->opStick->GetRawAxis(1);
		if(rawAxis1 > 1)
			rawAxis1 = 1;
		if(rawAxis1 < -1)
			rawAxis1 = -1;
		double elevatorIncrement = rawAxis1 * ELEVATOR_MANUAL_DPOS_SCALAR * TELE_PERIODIC_DT;
		if(elevatorIncrement)
		Elevator::GetInstance()->IncrementElevatorPosition(elevatorIncrement);
	//	std::cout << "running" << std::endl;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool OI_Refresh::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OI_Refresh::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OI_Refresh::Interrupted() {

}

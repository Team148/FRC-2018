#ifndef TankDriveJoystick_H
#define TankDriveJoystick_H

#include "Subsystems/Drivetrain.h"
#include "Commands/Command.h"

class TankDriveJoystick : public frc::Command {
public:
	TankDriveJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TankDriveJoystick_H

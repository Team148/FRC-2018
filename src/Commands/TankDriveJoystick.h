#ifndef TankDriveJoystick_H
#define TankDriveJoystick_H

#include "Commands/Command.h"
#include "Subsystems/Drivetrain.h"

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

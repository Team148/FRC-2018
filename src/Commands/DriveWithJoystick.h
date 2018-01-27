#ifndef DriveWithJoystick_H
#define DriveWithJoystick_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Command.h"


class DriveWithJoystick : public frc::Command {
public:
	DriveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveWithJoystick_H

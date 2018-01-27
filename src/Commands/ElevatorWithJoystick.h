#ifndef ElevatorWithJoystick_H
#define ElevatorWithJoystick_H

#include <Subsystems/Elevator.h>
#include "Commands/Command.h"


class ElevatorWithJoystick : public frc::Command {
public:
	ElevatorWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveWithJoystick_H

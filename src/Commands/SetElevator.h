#ifndef SetElevator_H
#define SetElevator_H

#include "Subsystems/Elevator.h"
#include "Commands/InstantCommand.h"

class SetElevator : public InstantCommand {
public:
	SetElevator(bool on, double position);
	void Initialize();

private:
	bool m_on = false;
	double m_position;
};

#endif  // SetElevator_H

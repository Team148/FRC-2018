#ifndef SetElevator_H
#define SetElevator_H

#include "Subsystems/Elevator.h"
#include "Commands/InstantCommand.h"

class SetElevator : public InstantCommand {
public:
	SetElevator(double position);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool m_isFinished = false;
	double m_startTime;
	double m_timeToWait;
	double m_position;
	double m_inches;

};

#endif  // SetElevator_H

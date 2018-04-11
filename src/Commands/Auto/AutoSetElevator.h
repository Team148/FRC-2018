#ifndef AutoSetElevator_H
#define AutoSetElevator_H

#include "Commands/Command.h"
#include "CommandBase.h"
#include "constants.h"

class AutoSetElevator : public CommandBase {
public:

	AutoSetElevator(int position, double timeToWait, double tolerance);
	AutoSetElevator(int position, double timeToWait);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double m_position;
	double m_timeToWait;
	bool m_IsFinished = false;
	double m_startTime = 0;
	double m_tolerance = ELEVATOR_ERROR_TOLERANCE;

};

#endif  // AutoSetElevator_H

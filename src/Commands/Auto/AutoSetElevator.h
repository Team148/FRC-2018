#ifndef AutoSetElevator_H
#define AutoSetElevator_H

#include "Commands/Command.h"
#include "CommandBase.h"
#include "constants.h"

class AutoSetElevator : public CommandBase {
public:

	AutoSetElevator(bool on,int position, double timeToWait = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool m_on = false;
	double m_position;
	double m_timeToWait;
	bool m_IsFinished = false;
	double m_startTime = 0;

};

#endif  // AutoSetElevator_H

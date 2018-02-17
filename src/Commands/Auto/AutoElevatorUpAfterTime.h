#ifndef ElevatorUpAfterDriveDist_H
#define ElevatorUpAfterDriveDist_H

#include "Commands/Command.h"
#include "CommandBase.h"
#include "constants.h"

class ElevatorUpAfterTime : public CommandBase {
public:

	ElevatorUpAfterTime(bool on,int position, double inchesToDrive);
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

#endif  // ElevatorUpAfterDriveDist_H

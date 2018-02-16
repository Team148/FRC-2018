#ifndef ElevatorUpAfterDriveDist_H
#define ElevatorUpAfterDriveDist_H

#include "Commands/Command.h"
#include "CommandBase.h"
#include "constants.h"

class ElevatorUpAfterDriveDist : public CommandBase {
public:

	ElevatorUpAfterDriveDist(bool on,int position, double inchesToDrive);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool m_on = false;
	double m_position;
	double m_inchesToDrive;
	bool m_IsFinished = false;

};

#endif  // ElevatorUpAfterDriveDist_H

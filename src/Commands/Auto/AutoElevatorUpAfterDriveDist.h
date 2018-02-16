#ifndef ElevatorUpAfterDriveDist_H
#define ElevatorUpAfterDriveDist_H

#include "../../CommandBase.h"

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
};

#endif  // ElevatorUpAfterDriveDist_H

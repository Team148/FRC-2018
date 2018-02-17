#ifndef ConfigDriveVelocityClosedLoop_H
#define ConfigDriveVelocityClosedLoop_H

#include "Commands/InstantCommand.h"

class ConfigDriveVelocityClosedLoop : public InstantCommand {
public:
	ConfigDriveVelocityClosedLoop(bool closedloop);
	void Initialize();
private:
	bool m_closedloop = false;
};

#endif  // ConfigDrivetVelocityClosedLoop_H

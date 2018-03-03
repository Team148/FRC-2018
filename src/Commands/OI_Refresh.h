#ifndef OI_Refresh_H
#define OI_Refresh_H

#include "Commands/Command.h"
#include <cmath>
#include <TimedRobot.h>


class OI_Refresh : public frc::Command {
public:
	OI_Refresh();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OI_Refresh_H

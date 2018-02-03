#ifndef PathFind_H
#define PathFind_H

#include "pathfinder.h"
#include "Commands/Command.h"
#include "Timer.h"
#include "../Util/Path.h"
#include "../Subsystems/Drivetrain.h"

class PathFind : public frc::Command {
public:

	PathFind();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int index;
	Path *PathPlanner;
	Drivetrain *m_tempDrivetrain;
	int m_lastTime;
};

#endif  // PathFind_H

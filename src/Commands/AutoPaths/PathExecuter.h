#ifndef PathExecuter_H
#define PathExecuter_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Command.h"
#include <./Paths/TrajectoryPath.h>

#include "Util/UnitMaster.h"


class PathExecuter : public frc::Command {
public:
	PathExecuter(TrajectoryPath* trajectory, bool IsReversed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	UnitMaster unit_master;
	TrajectoryPath *m_trajectory;
	double m_initTime;
	double m_pathDT = 0.010;
	bool m_isFinished = false;
	bool m_IsReversed = false;


};

#endif  // GoStraightPath_H

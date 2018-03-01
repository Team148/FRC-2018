#ifndef FromRightFirstCube_ToSecondCube_H
#define FromRightFirstCube_ToSecondCube_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Command.h"

#include "Util/UnitMaster.h"


class FromRightFirstCube_ToSecondCube : public frc::Command {
public:
	FromRightFirstCube_ToSecondCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	UnitMaster unit_master;
	double m_initTime;
	double m_pathDT = 0.010;
	bool m_isFinished = false;

#include <./Paths/FromRightFirstCube_ToSecondCubePath.h>


};

#endif  // GoStraightPath_H

#ifndef FromRightScale_ToRightFirstCube_H
#define FromRightScale_ToRightFirstCube_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Command.h"

#include "Util/UnitMaster.h"


class FromRightScale_ToRightFirstCube : public frc::Command {
public:
	FromRightScale_ToRightFirstCube();
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

#include <./Paths/FromRightScale_ToRightFirstCubePath.h>

};

#endif  // GoStraightPath_H

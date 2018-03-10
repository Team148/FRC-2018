#ifndef FromMiddlePos_ToRightScale_H
#define FromMiddlePos_ToRightScale_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Command.h"

#include "Util/UnitMaster.h"


class FromMiddlePos_ToRightScale : public frc::Command {
public:
	FromMiddlePos_ToRightScale();
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

	#include <./Paths/FromMiddlePos_ToRightScalePath.h>

};

#endif  // GoStraightPath_H

#ifndef FromMiddlePos_ToLeftSwitch_H
#define FromMiddlePos_ToLeftSwitch_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Command.h"

#include "Util/UnitMaster.h"


class FromMiddlePos_ToLeftSwitch : public frc::Command {
public:
	FromMiddlePos_ToLeftSwitch();
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

	#include <./Paths/FromMiddlePos_ToLeftSwitchPath.h>

};

#endif  // GoStraightPath_H

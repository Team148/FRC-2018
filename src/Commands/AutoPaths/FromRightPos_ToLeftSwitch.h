#ifndef FromRightPos_ToLeftSwitch_H
#define FromRightPos_ToLeftSwitch_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Command.h"

#include "Util/UnitMaster.h"


class FromRightPos_ToLeftSwitch : public frc::Command {
public:
	FromRightPos_ToLeftSwitch();
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

	#include <./Paths/FromRightPos_ToLeftSwitchPath.h>

};

#endif  // GoStraightPath_H

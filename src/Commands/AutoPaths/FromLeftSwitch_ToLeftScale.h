#ifndef FromLeftSwitch_ToLeftScale_H
#define FromLeftSwitch_ToLeftScale_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Command.h"

#include "Util/UnitMaster.h"


class FromLeftSwitch_ToLeftScale : public frc::Command {
public:
	FromLeftSwitch_ToLeftScale();
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

	#include <./Paths/FromLeftSwitch_ToLeftScalePath.h>

};

#endif

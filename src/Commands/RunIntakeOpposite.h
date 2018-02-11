#ifndef RunIntakeOpposite_H
#define RunIntakeOpposite_H

#include <Subsystems/Intake.h>
#include "Commands/Command.h"

class RunIntakeOpposite : public frc::InstantCommand {
public:
	RunIntakeOpposite(bool on);
	void Initialize();
private:
	bool m_on = false;
};

#endif  // RunIntake_H

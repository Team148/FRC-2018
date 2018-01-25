#ifndef RunIntake_H
#define RunIntake_H

#include "Commands/Command.h"
#include <Subsystems/Intake.h>

class RunIntake : public frc::InstantCommand {
public:
	RunIntake(bool on, bool reversed);
	void Initialize();
private:
	bool m_on = false;
	bool m_reversed = false;
};

#endif  // RunIntake_H

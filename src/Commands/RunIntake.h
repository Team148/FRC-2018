#ifndef RunIntake_H
#define RunIntake_H

#include <Subsystems/Intake.h>
#include "Commands/Command.h"

class RunIntake : public frc::InstantCommand {
public:
	RunIntake(bool on, bool reversed, bool reversedFull);
	void Initialize();
private:
	bool m_on = false;
	bool m_reversed = false;
	bool m_reversedFull = false;
};

#endif  // RunIntake_H

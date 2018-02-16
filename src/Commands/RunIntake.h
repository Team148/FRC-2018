#ifndef RunIntake_H
#define RunIntake_H

#include <Subsystems/Intake.h>
#include "Commands/Command.h"

class RunIntake : public frc::InstantCommand {
public:
	RunIntake(double percent);
	void Initialize();
private:
	double m_percent;
};

#endif  // RunIntake_H

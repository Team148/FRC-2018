#ifndef RunClimber_H
#define RunClimber_H

#include <Subsystems/Climber.h>
#include "Commands/Command.h"

class RunClimber : public frc::InstantCommand  {
public:
	RunClimber(bool on);
	void Initialize();

private:
	bool m_on = false;
};

#endif  // RunClimber_H

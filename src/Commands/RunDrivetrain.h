#ifndef RunDrivetrain_H
#define RunDrivetrain_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Command.h"

class RunDrivetrain : public frc::InstantCommand {
public:
	RunDrivetrain();
	void Initialize();
private:
//	bool m_on = false;
//	bool m_reversed = false;
};

#endif  // RunIntake_H

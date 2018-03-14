#ifndef RunWrist_H
#define RunWrist_H

#include "Subsystems/Wrist.h"
#include "Commands/Command.h"

class RunWrist : public frc::InstantCommand{
public:
	RunWrist(double percent);
	void Initialize();
private:
	double m_percent;
};

#endif

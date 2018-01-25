#ifndef GrabPartner_H
#define GrabPartner_H

#include <Subsystems/Forklift.h>
#include "Commands/Command.h"

class GrabPartner : public frc::InstantCommand  {
public:
	GrabPartner(bool on);
	void Initialize();

private:
	bool m_on = false;
};

#endif  // RunClimber_H

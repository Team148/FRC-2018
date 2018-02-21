#ifndef GrabPartner_H
#define GrabPartner_H

#include <Subsystems/Wrangler.h>
#include "Commands/Command.h"

class GrabPartner : public frc::InstantCommand  {
public:
	GrabPartner(double percent);
	void Initialize();

private:
	bool m_on = false;
	double m_percent = 0.0;
};

#endif  // RunClimber_H

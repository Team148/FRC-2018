#ifndef Wrangler_H
#define Wrangler_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "Constants.h"

class Wrangler : public Subsystem {
private:
	WPI_VictorSPX* m_WranglerMotor1;

	Wrangler();
	static Wrangler *m_instance;
public:
	static Wrangler* GetInstance();
	void InitDefaultCommand();
	void SetWranglerMotor(float percent);
};

#endif

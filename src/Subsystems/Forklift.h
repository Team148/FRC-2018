#ifndef Forklift_H
#define Forklift_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "Constants.h"

class Forklift : public Subsystem {
private:
	WPI_TalonSRX* m_ForkliftMotor1;

	Forklift();
	static Forklift *m_instance;
public:
	static Forklift* GetInstance();
	void InitDefaultCommand();
	void SetForkliftMotor(float percent);
};

#endif

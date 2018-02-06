#ifndef Intake_H
#define Intake_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "Constants.h"

class Intake : public Subsystem {
private:
	WPI_TalonSRX* m_IntakeMotor1;
	WPI_TalonSRX* m_IntakeMotor2;

	Intake();
	static Intake *m_instance;
public:
	static Intake* GetInstance();
	void InitDefaultCommand();
	void SetIntakeMotor(float percent);
};

#endif

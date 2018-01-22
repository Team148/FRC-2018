#ifndef Intake_H
#define Intake_H

#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "WPILib.h"
#include "Constants.h"

class Intake : public Subsystem {
private:
	WPI_TalonSRX* m_IntakeMotor1;
	//WPI_TalonSRX* m_intakeMotor2;

	Intake();
	static Intake *m_instance;
public:
	static Intake* GetInstance();
	void InitDefaultCommand();
};

#endif

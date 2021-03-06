#ifndef Climber_H
#define Climber_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "Constants.h"

class Climber : public Subsystem {
private:
	WPI_TalonSRX* m_ClimbMotor1;
	WPI_TalonSRX* m_ClimbMotor2;
	WPI_TalonSRX* m_ClimbMotor3;

	Climber();
	static Climber *m_instance;
public:
	static Climber* GetInstance();

	void InitDefaultCommand();
	void SetClimberMotor(float percent);
};

#endif

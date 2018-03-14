#ifndef Wrist_H
#define Wrist_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "Constants.h"

class Wrist : public Subsystem {

private:
	WPI_TalonSRX* m_wristMotor1;

	Wrist();
	static Wrist *m_instance;
public:
	static Wrist* GetInstance();
	void InitDefaultCommand();
	void SetWristMotor(float percent);
};

#endif

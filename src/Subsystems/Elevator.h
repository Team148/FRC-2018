#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "Constants.h"

class Elevator : public Subsystem {
private:
	WPI_TalonSRX* m_ElevatorMotor1;
	WPI_TalonSRX* m_ElevatorMotor2;
	//WPI_TalonSRX* m_ElevatorMotor3;

	Elevator();
	static Elevator *m_instance;

	//m_upLimit
	//m_downLimit

	bool m_isClosedLoop = 0;

public:
	static Elevator* GetInstance();
	void InitDefaultCommand();

	void JoystickControl(float ystick);
	void ConfigureOpenLoop();
	void ConfigureClosedLoop();
	bool IsClosedLoop();

	bool IsElevatorDown();
	bool IsElevatorUp();
};

#endif

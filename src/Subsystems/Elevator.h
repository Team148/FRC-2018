#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "Constants.h"

class Elevator : public Subsystem {
private:
	TalonSRX* m_ElevatorMotor1;
	TalonSRX* m_ElevatorMotor2;
	//WPI_TalonSRX* m_ElevatorMotor3;

	Elevator();
	static Elevator *m_instance;

	//m_upLimit
	//m_downLimit

	bool m_isClosedLoop = 0;
	double m_position = 1;

public:
	static Elevator* GetInstance();
	void InitDefaultCommand();

	void JoystickControl(float ystick);
	void ConfigOpenLoop();
	void ConfigClosedLoop();
	void ConfigClosedLoopMagic(double cruiseVelocity, double acceleration);
	void ConfigNeutralClosedLoop();
	bool IsClosedLoop();

	bool IsElevatorDown();
	bool IsElevatorUp();
	int GetElevatorPosition();
	int GetElevatorVelocity();

//	void SetElevatorJoystickPosition(double triggerValue);
	void SetElevatorPosition(double position, double arb_ff);
	void SetElevatorPositionMagic(double position, double arb_ff);
	void SetElevatorEncoderZero();
	void IncrementElevatorPosition(double dPosition);
};

#endif

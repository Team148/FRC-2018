#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "WPILib.h"
#include "Constants.h"

class Drivetrain : public Subsystem {
private:
	WPI_TalonSRX* m_leftMotor1;
	WPI_VictorSPX* m_leftMotor2;
	WPI_VictorSPX* m_leftMotor3;

	WPI_TalonSRX* m_rightMotor1;
	WPI_VictorSPX* m_rightMotor2;
	WPI_VictorSPX* m_rightMotor3;

	DifferentialDrive *m_drive;

	Drivetrain();
	static Drivetrain *m_instance;

	bool m_closedLoop = 0;

public:
	PowerDistributionPanel* m_pdp;
	static Drivetrain* GetInstance();
	void InitDefaultCommand();
	void Arcade(double ystick, double xstick);
	void Tank(double leftstick, double rightstick);
	void SetBrakeMode(bool on);
	void configClosedLoop();
	bool isClosedLoop();
};

#endif  // Drivetrain_H

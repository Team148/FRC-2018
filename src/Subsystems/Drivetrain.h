#ifndef Drivetrain_H
#define Drivetrain_H

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
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


public:
	static Drivetrain* GetInstance();
	void InitDefaultCommand();
	void Arcade(double ystick, double xstick);
	void Tank(double leftstick, double rightstick);
	void SetBrakeMode(bool on);


};

#endif  // Drivetrain_H

#ifndef Drivetrain_H
#define Drivetrain_H

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "Constants.h"

class Drivetrain : public Subsystem {
private:
	WPI_TalonSRX* m_leftMotor1;
	WPI_TalonSRX* m_leftMotor2;
	WPI_TalonSRX* m_leftMotor3;

	WPI_TalonSRX* m_rightMotor1;
	WPI_TalonSRX* m_rightMotor2;
	WPI_TalonSRX* m_rightMotor3;



	PigeonIMU* pigeon;
	double* yawPitchRoll = new double [3];

	DifferentialDrive *m_drive;

	Drivetrain();
	static Drivetrain *m_instance;

	bool m_closedLoop = 0;

public:
//	PowerDistributionPanel* m_pdp;
	static Drivetrain* GetInstance();
	void InitDefaultCommand();
	void Arcade(double ystick, double xstick);
	void Tank(double leftstick, double rightstick);
	void SetDriveVelocity(double left_velocity, double right_velocity);
	void SetBrakeMode(bool on);
	void configClosedLoop();
	void configOpenLoop();
	bool isClosedLoop();

	int getLeftDrivePosition();
	int getRightDrivePosition();
	double getLeftDriveVelocity();
	double getRightDriveVelocity();

	double updateGyroYaw();
	double updateGyroPitch();
	double updateGyroRoll();
	double updatePigey();
	double updatePigeon();

	void getPigeonStatus();

	void unitConversionTest();

};

#endif  // Drivetrain_H

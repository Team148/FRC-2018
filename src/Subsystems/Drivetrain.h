#ifndef Drivetrain_H
#define Drivetrain_H

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include "pathfinder.h"
#include "Constants.h"

class Drivetrain : public Subsystem {
private:
	WPI_TalonSRX* m_leftMotor1;
	WPI_VictorSPX* m_leftMotor2;
	WPI_VictorSPX* m_leftMotor3;

	WPI_TalonSRX* m_rightMotor1;
	WPI_VictorSPX* m_rightMotor2;
	WPI_VictorSPX* m_rightMotor3;

	double pos_x = 0;
	double pos_y = 0;

	PigeonIMU* pigeon;
	double* yawPitchRoll = new double [3];

	DifferentialDrive *m_drive;

	Drivetrain();
	static Drivetrain *m_instance;

	bool m_closedLoopVelocity = 0;
	bool m_closedLoopPosition = 0;


public:
//	PowerDistributionPanel* m_pdp;
	static Drivetrain* GetInstance();
	void InitDefaultCommand();
	void Arcade(double ystick, double xstick);
	void Tank(double leftstick, double rightstick);
	void SetLeftRight(double left, double right);
	void SetDriveVelocity(double left_velocity, double right_velocity);
	void SetDrivePosition(double left_position, double right_position);
	double *GetCorrectedVelocitySetPoint(double left_velocity, double right_velocity, Segment *leftTrajectory, Segment *rightTrajectory, int index);
	void SetBrakeMode(bool on);
	void configClosedLoopPositionKF(double kF);
	void configClosedLoopVelocity();
	void configClosedLoopPosition();
	void InitPathDrive();
	void SetPathDriveVelocity(double l_pos, double l_velo, double l_accel, double r_pos, double r_velo, double r_accel, double heading);
	void configPathLoop();
	void configOpenLoop();
	bool isClosedLoopVelocity();
	bool isClosedLoopPosition();



	int getLeftDrivePosition();
	int getRightDrivePosition();
	double getLeftDriveVelocity();
	double getRightDriveVelocity();

	double getLeftDriveVelocityError();
	double getRightDriveVelocityError();

	double getGyroYaw();
	double getGyroPitch();
	double getGyroRoll();
	int initLeftDrivePos;
	int initRightDrivePos;


	double updatePigeon();

	void getPigeonStatus();

	void accumRobotPosition();
	double getRobotPosition_x();
	double getRobotPosition_y();

	double getLeftThrottle();



	void unitConversionTest();

};

#endif  // Drivetrain_H

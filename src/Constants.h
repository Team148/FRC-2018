/*
 * Constants.h
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <math.h>

//Drivetrain constants.
constexpr double DRIVETRAIN_F_VEL = 0.175;// 0.0575
constexpr double DRIVETRAIN_P_VEL = 0.7;//0.025 // 1.5 .06
constexpr double DRIVETRAIN_I_VEL = 0.00; // 0.001
constexpr double DRIVETRAIN_D_VEL = 4.0;

constexpr double DRIVETRAIN_F_POS = 0.0;// 0.0575
constexpr double DRIVETRAIN_P_POS = 0.13;//0.025 // 1.5 .06
constexpr double DRIVETRAIN_I_POS = 0.00; // 0.001
constexpr double DRIVETRAIN_D_POS = 0.0;


constexpr float DRIVE_VELOCITY_P = 0;
constexpr float DRIVE_GYRO_COMP_P = 0;

//Auto/TurnPID
constexpr float DRIVE_TURN_P = .006;
constexpr float DRIVE_TURN_I = 0;
constexpr float DRIVE_TURN_TOLERANCE = 0.05;

//Auto Arcade Turn
constexpr float ARCADE_TURN_P = 0.006;
constexpr float ARCADE_TURN_I = 0;
constexpr float ARCADE_TURN_TOLERANCE = 0;

//Auto/TurnTMP
constexpr float TURN_DIST_P = 0.05;

constexpr float DRIVETRAIN_BASE_DIAMETER = 24;

constexpr double DRIVETRAIN_THROTTLE_FILTER = 0.75;
constexpr double DRIVETRAIN_TURBO_THROTTLE_FILTER = 1.0;

constexpr double DRIVETRAIN_TURN_FILTER = 0.65;
constexpr double DRIVETRAIN_TURBO_TURN_FILTER = 0.85;


constexpr double WHEEL_DIAMETER_INCHES = 6.125; // avg between 6 and 6.25
constexpr double WHEEL_CIRC_INCHES = WHEEL_DIAMETER_INCHES*M_PI;

constexpr int TICKS_PER_ROTATIONS = 5000; //1250 * 4
constexpr double ENCODER_GEAR_UPDUCTION = 1/1;

//PATHFINDER
constexpr double DRIVE_TRAIN_BASE_INCHES = 26.0;
constexpr double PATH_MAX_VELOCITY = 150.0;
constexpr double PATH_MAX_ACCEL = 100.0;
constexpr double PATH_MAX_JERK = 600.0;
constexpr double PATH_TIME_STEP = 0.02;

constexpr float DRIVE_GYRO_P = 15.0;


//constexpr float DRIVE_TURN_

//Elevator constants
constexpr double ELEVATOR_F = 150.00;
constexpr double ELEVATOR_P = 0.05;
constexpr double ELEVATOR_I = 0.00;
constexpr double ELEVATOR_D = 0.50;

constexpr int EE_TICKS_PER_ROTATION = 4096;

constexpr double ELEVATOR_ZERO = 1.0;
constexpr double ELEVATOR_SWITCH = 10100.0;
constexpr double ELEVATOR_SCALE_LOW = 21500.0;
constexpr double ELEVATOR_SCALE_HIGH = 30000.0;
constexpr double ELEVATOR_DOUBLE_STACK = 32000.0;
constexpr double ELEVATOR_HANG = 27500.0;

constexpr float MOTOR_FORWARD_FULL_OUTPUT = 1.0;
constexpr float MOTOR_REVERSE_FULL_OUTPUT = 1.0;

constexpr float INTAKE_PERCENT = 0.8;
constexpr float OUTTAKE_PERCENT = -0.30;
constexpr float OUTTAKE_FULL_PERCENT = -1.0;
constexpr float CLIMBER_OUTPUT_PERCENT = 1.0;
constexpr float WRANGLER_OUTPUT_PERCENT = -1.0;
constexpr float ELEVATOR_OUTPUT_PERCENT = 1.0;
constexpr int LEFT_VALUE = -1;
constexpr int RIGHT_VALUE = 1;

enum tUnits
{
	TICKS = 0,
	INCHES,
	ROTATIONS,
	TICKS_PER_SEC,
	INCHES_PER_SEC,
	ROTATIONS_PER_SEC,
	TICKS_PER_100MS,
};



#endif //CONSTANTS_H

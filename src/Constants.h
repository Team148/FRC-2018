/*
 * Constants.h
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

//Drivetrain constants.
constexpr double DRIVETRAIN_F = 0.28;// 0.0575
constexpr double DRIVETRAIN_P = 0.005; // 1.5 .06
constexpr double DRIVETRAIN_I = 0.00; // 0.001
constexpr double DRIVETRAIN_D = 0.0;

constexpr double DRIVETRAIN_THROTTLE_FILTER = 0.75;
constexpr double DRIVETRAIN_TURBO_THROTTLE_FILTER = 1.0;

constexpr double DRIVETRAIN_TURN_FILTER = 0.65;
constexpr double DRIVETRAIN_TURBO_TURN_FILTER = 0.85;


constexpr double WHEEL_DIAMETER_INCHES = 6.0;
constexpr double WHEEL_CIRC_INCHES = 18.8495559215;
constexpr int TICKS_PER_ROTATIONS = 16384;
constexpr double ENCODER_GEAR_UPDUCTION = 1/1;

//PATHFINDER
constexpr double DRIVE_TRAIN_BASE_INCHES = 26.0;
constexpr double PATH_MAX_VELOCITY = 150.0;
constexpr double PATH_MAX_ACCEL = 100.0;
constexpr double PATH_MAX_JERK = 600.0;
constexpr double PATH_TIME_STEP = 0.02;

//Elevator constants
constexpr double ELEVATOR_F = 0.00;
constexpr double ELEVATOR_P = 0.05;
constexpr double ELEVATOR_I = 0.00;
constexpr double ELEVATOR_D = 0.50;

constexpr int EE_TICKS_PER_ROTATION = 4096;

constexpr double ELEVATOR_ZERO = 0;
constexpr double ELEVATOR_SWITCH = 8500.0;
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




#endif //CONSTANTS_H

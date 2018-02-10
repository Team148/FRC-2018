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


constexpr float MOTOR_FORWARD_FULL_OUTPUT = 1.0;
constexpr float MOTOR_REVERSE_FULL_OUTPUT = 1.0;

constexpr float INTAKE_PERCENT = 1.0;
constexpr float OUTTAKE_PERCENT = -0.50;
constexpr float CLIMBER_OUTPUT_PERCENT = 1.0;
constexpr float ELEVATOR_OUTPUT_PERCENT = 1.0;



#endif //CONSTANTS_H

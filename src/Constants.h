/*
 * Constants.h
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <math.h>
#include <string>

constexpr float DRIVETRAIN_BASE_DIAMETER = 24.9;

constexpr double DRIVETRAIN_THROTTLE_FILTER = 0.65;
constexpr double DRIVETRAIN_TURBO_THROTTLE_FILTER = 1.00;

constexpr double DRIVETRAIN_TURN_FILTER = 0.75;
constexpr double DRIVETRAIN_TURBO_TURN_FILTER = 1.00;

constexpr double WHEEL_DIAMETER_INCHES = 5.878; // avg between 6 and 6.25
constexpr double WHEEL_CIRC_INCHES = WHEEL_DIAMETER_INCHES*M_PI;

constexpr int TICKS_PER_ROTATIONS = 5000; //1250 * 4

constexpr double ENCODER_GEAR_UPDUCTION = 1/1;

constexpr float MOTOR_FORWARD_FULL_OUTPUT = 1.0;
constexpr float MOTOR_REVERSE_FULL_OUTPUT = 1.0;

constexpr float WRIST_PERCENT = 0.33;
constexpr float INTAKE_FAST_PERCENT = 0.8;
constexpr float INTAKE_SLOW_PERCENT = 0.15;
constexpr float OUTTAKE_AUTOSCORE_PERCENT = -0.15;
constexpr float OUTTAKE_PERCENT = -0.20;
constexpr float OUTTAKE_PERCENT_AUTO = -0.25;
constexpr float OUTTAKE_FULL_PERCENT = -0.60;
constexpr int LEFT_VALUE = -1;
constexpr int RIGHT_VALUE = 1;

#endif //CONSTANTS_H

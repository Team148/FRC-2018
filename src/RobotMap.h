#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//CANBus PIDs	NAME				PID
constexpr int DRIVE_LEFTMOTOR_1 	= 1;
constexpr int DRIVE_LEFTMOTOR_2 	= 3;
constexpr int DRIVE_LEFTMOTOR_3 	= 5;

constexpr int DRIVE_RIGHTMOTOR_1 	= 2;
constexpr int DRIVE_RIGHTMOTOR_2 	= 4;
constexpr int DRIVE_RIGHTMOTOR_3 	= 6;

constexpr int INTAKE_MOTOR_1		= 12;
constexpr int INTAKE_MOTOR_2		= 14;

constexpr int ELEVATOR_MOTOR_1		= 10;
constexpr int ELEVATOR_MOTOR_2		= 11;

constexpr int CLIMBER_MOTOR_1		= 7;
constexpr int CLIMBER_MOTOR_2		= 8;
constexpr int CLIMBER_MOTOR_3		= 9;

constexpr int WRANGLER_MOTOR_1		= 13;

constexpr int PIGEON_GYRO 			= 0;

constexpr int LINETRACKER_FRONT_L	= 0;
constexpr int LINETRACKER_REAR_L	= 1;
constexpr int LINETRACKER_FRONT_R	= 2;
constexpr int LINETRACKER_REAR_R	= 3;


#endif  // ROBOTMAP_H

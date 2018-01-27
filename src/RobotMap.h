#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//CANBus PIDs	NAME				PID
constexpr int DRIVE_LEFTMOTOR_1 	= 1;
constexpr int DRIVE_LEFTMOTOR_2 	= 2;
constexpr int DRIVE_LEFTMOTOR_3 	= 3;


constexpr int DRIVE_RIGHTMOTOR_1 	= 6;
constexpr int DRIVE_RIGHTMOTOR_2 	= 7;
constexpr int DRIVE_RIGHTMOTOR_3 	= 8;

constexpr int PIGEON_GYRO 			= 7;


constexpr int INTAKE_MOTOR_1		= 8;
constexpr int INTAKE_MOTOR_2		= 9;

constexpr int ELEVATOR_MOTOR_1		= 99;
constexpr int ELEVATOR_MOTOR_2		= 99;
//constexpr int ELEVATOR_MOTOR_3	  = 11;

constexpr int CLIMBER_MOTOR_1		= 0;
constexpr int CLIMBER_MOTOR_2		= 4;
//constexpr int CLIMBER_MOTOR_3		  =13;

constexpr int FORKLIFT_MOTOR_1		= 5;

#endif  // ROBOTMAP_H

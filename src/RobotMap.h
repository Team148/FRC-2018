#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//CANBus PIDs	NAME				PID		//PDP
constexpr int DRIVE_LEFTMOTOR_1 	= 1;	//0
constexpr int DRIVE_LEFTMOTOR_2 	= 3;	//1
constexpr int DRIVE_LEFTMOTOR_3 	= 5;	//2

constexpr int DRIVE_RIGHTMOTOR_1 	= 2;	//15
constexpr int DRIVE_RIGHTMOTOR_2 	= 4;	//14
constexpr int DRIVE_RIGHTMOTOR_3 	= 6;	//13

constexpr int INTAKE_MOTOR_1		= 12;	//10
constexpr int INTAKE_MOTOR_2		= 14;	//9

constexpr int ELEVATOR_MOTOR_1		= 10;	//11
constexpr int ELEVATOR_MOTOR_2		= 11;	//5

constexpr int CLIMBER_MOTOR_1		= 7;	//4
constexpr int CLIMBER_MOTOR_2		= 8;	//12
constexpr int CLIMBER_MOTOR_3		= 9;	//3

constexpr int WRANGLER_MOTOR_1		= 13;	//6

constexpr int PIGEON_GYRO 			= 0;

#endif  // ROBOTMAP_H

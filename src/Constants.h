/*
 * Constants.h
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <math.h>
#include <string>

//Drivetrain constants.
constexpr double DRIVETRAIN_F_VEL = 0.19;//0.175// 0.0575
constexpr double DRIVETRAIN_P_VEL = 0.7;// 0.7;// 0.7
constexpr double DRIVETRAIN_I_VEL = 0.00; // 0.001
constexpr double DRIVETRAIN_D_VEL = 4.0;//4.0; // 4.0

//Drivetrain constants.
constexpr double DRIVETRAIN_F_MAJ = 0.19;//0.175// 0.0575
constexpr double DRIVETRAIN_P_MAJ = 0.75;// 0.7;// 0.7
constexpr double DRIVETRAIN_I_MAJ = 0.00; // 0.001
constexpr double DRIVETRAIN_D_MAJ = 5.0;//4.0; // 4.0

constexpr double DRIVETRAIN_F_POS = 0.0;// 0.0575
constexpr double DRIVETRAIN_P_POS = 0.27; // .18
constexpr double DRIVETRAIN_I_POS = 0.000; // 0.001
constexpr double DRIVETRAIN_D_POS = 0.9;

constexpr float DRIVE_ANGLE_TOLERANCE = 3.0;

constexpr double DRIVETRAIN_PATH_FV = 1.0;
constexpr double DRIVETRAIN_PATH_FA = 0.10;// 0.012;
constexpr double DRIVETRAIN_PATH_KP = 30.0;//30.0 //1.0;
constexpr double DRIVETRAIN_PATH_KP_REVERSE =30.0;// 3.0;
constexpr double DRIVETRAIN_PATH_KI = 0.0;
constexpr double DRIVETRAIN_PATH_KD = 0.0;
constexpr double DRIVETRAIN_PATH_KP_HEADING = 5.0;//4.0// 3.0;
constexpr double DRIVETRAIN_PATH_KP_HEADING_REVERSE = 2.0;//2.0;
constexpr double DRIVETRAIN_PATH_NOMINALOUT = 0.000;
constexpr double DRIVETRAIN_PATH_POS_LIMIT = 0.15; //percent

constexpr double DRIVETRAIN_LINE_RL_THRESHOLD = 4.5;
constexpr double DRIVETRAIN_LINE_RR_THRESHOLD = 4.5;

constexpr double DRIVETRAIN_MAX_VEL = 180.0; // inches/second

//Intake
constexpr float CUBE_IN_CURRENT_CURRENT = 500;
constexpr float TIME_TO_RUN_INTAKE = 0.3;

constexpr float DRIVE_VELOCITY_P = 0;
constexpr float DRIVE_GYRO_COMP_P = 0;

//Auto/TurnPID
constexpr float DRIVE_TURN_KF = 0.0;
constexpr float DRIVE_TURN_P = .006;
constexpr float DRIVE_TURN_I = 0;
constexpr float DRIVE_TURN_TOLERANCE = 0.05;

//Auto Arcade Turn
constexpr float ARCADE_TURN_P = 0.006;
constexpr float ARCADE_TURN_I = 0;
constexpr float ARCADE_TURN_TOLERANCE = 0;

//Auto/TurnTMP
constexpr float TURN_DIST_P = 0.05;

constexpr float DRIVETRAIN_BASE_DIAMETER = 24.9;
constexpr double DRIVETRAIN_SCRUB_FACTOR = 0.9;

constexpr double DRIVETRAIN_THROTTLE_FILTER = 0.65;
constexpr double DRIVETRAIN_TURBO_THROTTLE_FILTER = 1.00;

constexpr double DRIVETRAIN_TURN_FILTER = 0.75;
constexpr double DRIVETRAIN_TURBO_TURN_FILTER = 1.00;


constexpr double WHEEL_DIAMETER_INCHES = 5.878; // avg between 6 and 6.25
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
constexpr double ELEVATOR_F = 0.1367;
constexpr double ELEVATOR_F_DOWN = ELEVATOR_F + 0.03;
constexpr double ELEVATOR_P = 0.05;
constexpr double ELEVATOR_I = 0.00;
constexpr double ELEVATOR_D = 0.50;
constexpr double ELEVATOR_ZERO_F = -0.0732;

constexpr double ELEVATOR_F_VEL =  0.26;
constexpr double ELEVATOR_P_VEL = 0.7;
constexpr double ELEVATOR_I_VEL = 0.00;
constexpr double ELEVATOR_D_VEL = 4.0;
constexpr double ELEVATOR_AUX_F_VEL = 0.1367;


constexpr double ELEVATOR_ZERO = 1.0;	//1.0
constexpr double ELEVATOR_SWITCH = 14000.0; //15000.0;
constexpr double ELEVATOR_SWITCH_AUTO = 10000.0; //15000.0;
constexpr double ELEVATOR_SCALE_LOW = 27500.0; //26000.0;
constexpr double ELEVATOR_SCALE_HIGH = 34000.0;
constexpr double ELEVATOR_DOUBLE_STACK = 34000.0;
constexpr double ELEVATOR_HANG = 30000.0;
constexpr double ELEVATOR_MAX_HEIGHT = 34150.0;

constexpr double ELEVATOR_ZERO_NEUTRAL_POSITION = 3000.0;
constexpr double ELEVATOR_ZERO_NEUTRAL_POSITION_DEADBAND = 1000.0;



constexpr double ELEVATOR_ERROR_TOLERANCE = 2000;
constexpr double ELEVATOR_MANUAL_DEADBAND = 0.2;
constexpr double ELEVATOR_MANUAL_DPOS_SCALAR = 12000; // Ticks/second
constexpr int ELEVATOR_SOFT_LIMIT = 36500;

constexpr float MOTOR_FORWARD_FULL_OUTPUT = 1.0;
constexpr float MOTOR_REVERSE_FULL_OUTPUT = 1.0;

constexpr float INTAKE_FAST_PERCENT = 0.8;
constexpr float INTAKE_SLOW_PERCENT = 0.15;
constexpr float INTAKE_HOLD_AUTO_PERCENT = 0.10;
constexpr float INTAKE_SLOW_AUTO_PERCENT = 0.3;
constexpr float OUTTAKE_AUTOSCORE_PERCENT = -0.15;
constexpr float OUTTAKE_PERCENT = -0.20;
constexpr float OUTTAKE_PERCENT_AUTO = -0.25;
constexpr float OUTTAKE_FULL_PERCENT = -0.60;
constexpr float OUTTAKE_MAX_PERCENT = -1.00;
//constexpr float OUTTAKE_SUPER_SLOW_PERCENT = -0.12;
constexpr float CLIMBER_OUTPUT_PERCENT = 1.0;
constexpr float WRANGLER_FAST_PERCENT = -1.0;
constexpr float WRANGLER_SLOW_PERCENT = -0.5;
constexpr float ELEVATOR_OUTPUT_PERCENT = 1.0;
constexpr int LEFT_VALUE = -1;
constexpr int RIGHT_VALUE = 1;

enum tDriveConfigs
{
	OPEN_LOOP = 0,
	VELOCITY_CONFIG,
	POSITION_CONFIG,
	PATH_CONFIG,
	MOTION_MAGIC_CONFIG
};
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


enum tCubeAmount
{
	ONE_CUBE = 0,
	TWO_CUBE,
	THREE_CUBE,
	FOUR_CUBE
};
enum tStartingPosition
{
	RIGHT_POS = 1,
	LEFT_POS = 2,
	MIDDLE_POS = 3
};

typedef struct
{
	std::string R_R = "RR";
	std::string R_L = "RL";
	std::string L_R = "LR";
	std::string L_L = "LL";
} autoStringData;

//autoStringData autoConstData;

//autoConstData.R_R = {'R', 'R'};

constexpr double TELE_PERIODIC_DT = 0.020;
constexpr double AUTO_PERIODIC_DT = 0.010;




#endif //CONSTANTS_H

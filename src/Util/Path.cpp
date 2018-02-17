#include <Util/Path.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <./Subsystems/Drivetrain.h>
//#include "stdio.h"
#include "SmartDashboard/SmartDashboard.h"


Path::Path()
{
	POINT_LENGTH = 3;

	points = (Waypoint*)malloc(sizeof(Waypoint) * POINT_LENGTH);

	//Waypoint p1 = { 0,0,0 };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
	//Waypoint p2 = { .7, 0, 0 };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians

	Waypoint p1 = { 0, 0, 0};      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
	Waypoint p2 = { 200, 6, 0};           // Waypoint @ x=-1, y= 2, exit angle= 0 radians
//		Waypoint p2 = { 180, 0, 0 };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians


	Waypoint p3 = { 240, -24, 0};  // Waypoint @ x= 2, y= 4, exit angle= 0 radians
//	Waypoint p4 = { 210, 70, d2r(90)};
//	Waypoint p5 = { 170, 50, d2r(90)};


	//TRY*** Don't set an exit angle to 0 exactly in the Waypoints,
	//it causes a divide by zero error and crashes Java. I fixed it by setting the exit angle to 0.001.

	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
//	points[3] = p4;
//	points[4] = p5;

//	Waypoint p1 = { 0, 0, 0};      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
//	Waypoint p2 = { 212, 0, d2r(45)};           // Waypoint @ x=-1, y= 2, exit angle= 0 radians
//
//
//	Waypoint p3 = { 180, -180, d2r(90) };  // Waypoint @ x= 2, y= 4, exit angle= 0 radians

	TrajectoryCandidate candidate;
	pathfinder_prepare(points, POINT_LENGTH, FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_FAST, TIME_STEP, MAX_VELOCITY, MAX_ACCEL, MAX_JERK, &candidate);

	length = candidate.length;
	trajectory = (Segment*)malloc(length * sizeof(Segment)); // The (Segment*) is not in examples, investigate

	pathfinder_generate(&candidate, trajectory);

	leftTrajectory = (Segment*)malloc(sizeof(Segment) * length);
	rightTrajectory = (Segment*)malloc(sizeof(Segment) * length);

	pathfinder_modify_tank(trajectory, length, leftTrajectory, rightTrajectory, DRIVE_TRAIN_BASE);




	//FILE *fp = fopen("halensFPfile.csv", "w");
	////pathfinder_serialize_csv(fp, trajectory, length * sizeof(trajectory));
	//fclose(fp);
}

void Path::EncoderFollowerSetup(){

	leftEncoderFollower = (EncoderFollower*) malloc(sizeof(EncoderFollower));
	leftEncoderFollower->last_error = 0; leftEncoderFollower->segment = 0; leftEncoderFollower->finished = 0;

	rightEncoderFollower = (EncoderFollower*)malloc(sizeof(EncoderFollower));
	rightEncoderFollower->last_error = 0; rightEncoderFollower->segment = 0; rightEncoderFollower->finished = 0;

//	configLeftEncoder = {Drivetrain::GetInstance()->getLeftDrivePosition() , TICKS_PER_REV, WHEEL_CIRC,      // Position, Ticks per Rev, Wheel Circumference
//				                         DRIVETRAIN_P_VEL, DRIVETRAIN_I_VEL, DRIVETRAIN_D_VEL, 1.0 / MAX_VELOCITY, 0.0};
//
//	configRightEncoder = {Drivetrain::GetInstance()->getRightDrivePosition(), TICKS_PER_REV, WHEEL_CIRC,      // Position, Ticks per Rev, Wheel Circumference
//											 DRIVETRAIN_P, DRIVETRAIN_I, DRIVETRAIN_D, 1.0 / MAX_VELOCITY, 0.0};         // Kp, Ki, Kd and Kv, Ka



}

double Path::GetLeftValue(int index){
	//std::cout << "Left Side" << endl;
	//std::cout << "Left Drive" << std::endl;
	//std::cout << index << std::endl;
	//std::cout << -(leftTrajectory[index].velocity) << std::endl;

	if(index < length)
	{
//			return (leftTrajectory[index].velocity/MAX_VELOCITY);

		return (leftTrajectory[index].velocity);

	}
	else
	{
			return 0;
	}




}


double Path::GetRightValue(int index){
	//std::cout << "Right Drive" << std::endl;
	//std::cout << index << std::endl;
	//std::cout << leftTrajectory[index].velocity/MAX_VELOCITY <<  std::endl;

	if(index < length)
	{
//			return -(rightTrajectory[index].velocity/MAX_VELOCITY);
//		std::cout << "R_X: " << trajectory[index].x << " R_Y: " << trajectory[index].y << std::endl;

		return (rightTrajectory[index].velocity);

	}
	else
	{
		    return 0;
	}


}

Segment Path::GetLeftSegment(int index)
{
	if(index < length)
	{
		return leftTrajectory[index];
	}
	else if(index == length)
	{
		leftTrajectory[length - 1].velocity = 0;
		leftTrajectory[length - 1].acceleration = 0;
		return leftTrajectory[length - 1];
	}
	else
	{
		return leftTrajectory[length];
	}

	return leftTrajectory[index];
}

Segment Path::GetRightSegment(int index)
{
	if(index < length)
		{
			return rightTrajectory[index];
		}
		else if(index == length)
		{
			rightTrajectory[length - 1].velocity = 0;
			rightTrajectory[length - 1].acceleration = 0;
			return rightTrajectory[length - 1];
		}
		else
		{
			return rightTrajectory[length - 1];
		}
}

double Path::LeftENCCorrectionValue(int index)
{
	double l = 0;
	if(index < length)
	{
		l = pathfinder_follow_encoder(configLeftEncoder, leftEncoderFollower, &leftTrajectory[index], length,Drivetrain::GetInstance()->getLeftDrivePosition());
		return l;
	}
	else
	{
		return 0;
	}

}

double Path::RightENCCorrectionValue(int index)
{
	double r = 0;
	if(index < length)
	{

		r = pathfinder_follow_encoder(configRightEncoder, rightEncoderFollower, &rightTrajectory[index], length, Drivetrain::GetInstance()->getRightDrivePosition());

		std::cout << "R_Correction: " << r << std::endl;

		return r;
	}
	else
	{
		return 0;
	}

}

void Path::End(){
	free(trajectory);
}







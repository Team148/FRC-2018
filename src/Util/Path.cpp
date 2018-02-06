#include <Util/Path.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <./Subsystems/Drivetrain.h>
//#include "stdio.h"

Path::Path(){

		TICKS_PER_REV = 4096;
		WHEEL_CIRC = 6 * PI;


		POINT_LENGTH = 2;
		DRIVE_TRAIN_BASE = 26;
		MAX_VELOCITY = 150;
		MAX_ACCEL = 100;
		MAX_JERK = 700;
		TIME_STEP = .01;



	    Waypoint *points = (Waypoint*)malloc(sizeof(Waypoint) * POINT_LENGTH);

	    //Waypoint p1 = { 0,0,0 };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
	    //Waypoint p2 = { .7, 0, 0 };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians

	    Waypoint p1 = { 0,0,0 };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
		Waypoint p2 = { 24, 0, 0 };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians
//		Waypoint p2 = { 1, 1, 0 };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians


	    //Waypoint p3 = {  10, 0, 0 };  // Waypoint @ x= 2, y= 4, exit angle= 0 radians
	    //Waypoint p4 = {15,0,0};
	    //Waypoint p5 = {20,0,0};

	    points[0] = p1;
	    points[1] = p2;
	    //points[2] = p3;
	    //points[3] = p4;
	    //points[4] = p5;


	    pathfinder_prepare(points, POINT_LENGTH, FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_FAST, TIME_STEP, MAX_VELOCITY, MAX_ACCEL, MAX_JERK, &candidate);
	    length = candidate.length;
		Segment *trajectory = (Segment*)malloc(length * sizeof(Segment));

		pathfinder_generate(&candidate, trajectory);

		leftTrajectory = (Segment*)malloc(sizeof(Segment) * length);
		rightTrajectory = (Segment*)malloc(sizeof(Segment) * length);

		pathfinder_modify_tank(trajectory, length, leftTrajectory, rightTrajectory, DRIVE_TRAIN_BASE);




		//FILE *fp = fopen("halensFPfile.csv", "w");
		////pathfinder_serialize_csv(fp, trajectory, length * sizeof(trajectory));
		//fclose(fp);
}

void Path::EncoderFollowerSetup(){
	Drivetrain *tempDrive  = Drivetrain::GetInstance();

	leftFollower = (EncoderFollower*) malloc(sizeof(EncoderFollower));
	leftFollower->last_error = 0; leftFollower->segment = 0; leftFollower->finished = 0;

	rightFollower = (EncoderFollower*)malloc(sizeof(EncoderFollower));
	rightFollower->last_error = 0; rightFollower->segment = 0; rightFollower->finished = 0;

	configLeft = {tempDrive->updateLeftEncoder() , TICKS_PER_REV, WHEEL_CIRC,      // Position, Ticks per Rev, Wheel Circumference
				                         DRIVETRAIN_P, DRIVETRAIN_I, DRIVETRAIN_D, 1.0 / MAX_VELOCITY, 0.0};

	configRight = {tempDrive->updateRightEncoder(), TICKS_PER_REV, WHEEL_CIRC,      // Position, Ticks per Rev, Wheel Circumference
											 DRIVETRAIN_P, DRIVETRAIN_I, DRIVETRAIN_D, 1.0 / MAX_VELOCITY, 0.0};         // Kp, Ki, Kd and Kv, Ka



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

		return (rightTrajectory[index].velocity);

	}
	else
	{
		    return 0;
	}


}

Segment Path::GetLeftSegment(int index)
{
	return leftTrajectory[index];
}

Segment Path::GetRightSegment(int index)
{
	return rightTrajectory[index];
}

double Path::LeftENCCorrectionValue(int index)
{
	Drivetrain *tempDrive  = Drivetrain::GetInstance();
	double l;
	if(index < length)
	{
		l = pathfinder_follow_encoder(configLeft, leftFollower, &leftTrajectory[index], length,tempDrive->updateLeftEncoder() );
		return l;
	}
	else
	{
		return 0;
	}

}

double Path::RightENCCorrectionValue(int index)
{
	Drivetrain *tempDrive  = Drivetrain::GetInstance();
	double r;
	if(index < length)
	{

		r = pathfinder_follow_encoder(configRight, rightFollower, &rightTrajectory[index], length, tempDrive->updateRightEncoder());
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







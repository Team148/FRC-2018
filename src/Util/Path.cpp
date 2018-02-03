#include <Util/Path.h>
#include <iostream>
#include <fstream>
#include <iomanip>
//#include "stdio.h"

Path::Path(){

		POINT_LENGTH = 2;
		DRIVE_TRAIN_BASE = .5;
		MAX_VELOCITY = 1;
		MAX_ACCEL = 3;
		MAX_JERK = 20;
		TIME_STEP = .01;

	    Waypoint *points = (Waypoint*)malloc(sizeof(Waypoint) * POINT_LENGTH);

	    Waypoint p1 = { 0,0,0 };      // Waypoint @ x=-4, y=-1, exit angle=45 degrees
	    Waypoint p2 = { 2, 0, 0 };             // Waypoint @ x=-1, y= 2, exit angle= 0 radians
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

void Path::CreatePath(){


}

double Path::GetLeftValue(int index){
	//std::cout << "Left Side" << endl;
	//std::cout << "Left Drive" << std::endl;
	//std::cout << index << std::endl;
	//std::cout << -(leftTrajectory[index].velocity) << std::endl;

	if(index < length)
	{
			return -(leftTrajectory[index].velocity/MAX_VELOCITY);
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
			return -(rightTrajectory[index].velocity/MAX_VELOCITY);
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

Segment Path::GetRightSegment(int index){
	return rightTrajectory[index];

}

void Path::End(){
	free(trajectory);
}







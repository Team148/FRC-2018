#ifndef SRC_PATH_H_
#define SRC_PATH_H_

#include "pathfinder.h"


class Path {
private:
	Waypoint* points;

	double DRIVE_TRAIN_BASE;
	double MAX_VELOCITY;
	double MAX_ACCEL;
	double MAX_JERK;
	double TIME_STEP;
	int POINT_LENGTH;

	Segment* leftTrajectory;
	Segment* rightTrajectory;
	Segment* trajectory;
	int length;
	TrajectoryCandidate candidate;



public:
	Path();
	void CreatePath();
	double GetLeftValue(int index);
	double GetRightValue(int index);
	Segment GetLeftSegment(int index);
	Segment GetRightSegment(int index);
	void End();

};

#endif

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
	int TICKS_PER_REV;
	double WHEEL_CIRC;

	EncoderFollower* leftFollower;
	EncoderFollower* rightFollower;
	EncoderConfig configLeft;
	EncoderConfig configRight;


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
	double LeftENCCorrectionValue(int index);
	double RightENCCorrectionValue(int index);
	Segment GetLeftSegment(int index);
	Segment GetRightSegment(int index);

	void EncoderFollowerSetup();
	void End();

};

#endif

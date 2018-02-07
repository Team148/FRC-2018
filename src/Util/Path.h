#ifndef SRC_PATH_H_
#define SRC_PATH_H_

#include "pathfinder.h"
#include "../constants.h"



class Path {
private:
	Waypoint* points = 0;

	double DRIVE_TRAIN_BASE = DRIVE_TRAIN_BASE_INCHES;
	double MAX_VELOCITY = PATH_MAX_VELOCITY;
	double MAX_ACCEL = PATH_MAX_ACCEL;
	double MAX_JERK = PATH_MAX_JERK;
	double TIME_STEP = PATH_TIME_STEP;
	int POINT_LENGTH = 0;
	int TICKS_PER_REV = TICKS_PER_ROTATIONS;
	double WHEEL_CIRC = WHEEL_CIRC_INCHES;


	EncoderFollower* leftEncoderFollower = 0;
	EncoderFollower* rightEncoderFollower = 0;
	EncoderConfig configLeftEncoder;
	EncoderConfig configRightEncoder;


	Segment* leftTrajectory = 0;
	Segment* rightTrajectory = 0;
	Segment* trajectory = 0;
	int length = 0;

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

#include "TrajectoryPath.h"

	TrajectoryPath::TrajectoryPath() {}
	TrajectoryPath* TrajectoryPath::GetInstance() {}

	int TrajectoryPath::GetIndexLength() {}
	double TrajectoryPath::GetStartHeading() {}
	double TrajectoryPath::GetEndHeading() {}
	double TrajectoryPath::GetTimeLength() {}
	double TrajectoryPath::GetDT() {}
	double TrajectoryPath::GetLeftPosition(int index) {}
	double TrajectoryPath::GetLeftVelocity(int index) {}
	double TrajectoryPath::GetLeftAcceleration(int index) {}
	double TrajectoryPath::GetRightPosition(int index) {}
	double TrajectoryPath::GetRightVelocity(int index) {}
	double TrajectoryPath::GetRightAcceleration(int index) {}
	double TrajectoryPath::GetX(int index){}
	double TrajectoryPath::GetY(int index){}
	double TrajectoryPath::GetHeading(int index) {}
	double* TrajectoryPath::GetLeftTrajectoryArray(int index) {}
	double* TrajectoryPath::GetRightTrajectoryArray(int index) {}

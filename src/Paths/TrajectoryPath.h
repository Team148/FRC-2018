#ifndef TrajectoryPath_H
#define TrajectoryPath_H


class TrajectoryPath {

public:
	TrajectoryPath();
	static TrajectoryPath* GetInstance();
	int GetIndexLength();
	double GetTimeLength();
	double GetEndHeading();
	double* GetLeftTrajectoryArray(int index);
	double* GetRightTrajectoryArray(int index);
	double GetLeftPosition(int index);
	double GetLeftVelocity(int index);
	double GetLeftAcceleration(int index);
	double GetRightPosition(int index);
	double GetRightVelocity(int index);
	double GetRightAcceleration(int index);
	double GetHeading(int index);
};

#endif  // Drivetrain_H

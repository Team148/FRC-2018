//#ifndef TrajectoryPath_H
//#define TrajectoryPath_H

#pragma once

class TrajectoryPath {

public:
	TrajectoryPath();
	static TrajectoryPath* GetInstance();
//protected:
	virtual int GetIndexLength();
	virtual double GetTimeLength();
	virtual double GetStartHeading();
	virtual double GetEndHeading();
	virtual double* GetLeftTrajectoryArray(int index);
	virtual double* GetRightTrajectoryArray(int index);
	virtual double GetLeftPosition(int index);
	virtual double GetLeftVelocity(int index);
	virtual double GetLeftAcceleration(int index);
	virtual double GetRightPosition(int index);
	virtual double GetRightVelocity(int index);
	virtual double GetRightAcceleration(int index);
	virtual double GetHeading(int index);
};

//#endif  // Drivetrain_H

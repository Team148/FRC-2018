#include "FromLeftSwitchFront_ToLeftScaleBackReversePath.h"
#include <iostream>

FromLeftSwitchFront_ToLeftScaleBackReversePath *FromLeftSwitchFront_ToLeftScaleBackReversePath::m_instance = 0;

FromLeftSwitchFront_ToLeftScaleBackReversePath::FromLeftSwitchFront_ToLeftScaleBackReversePath()
{
}
TrajectoryPath* FromLeftSwitchFront_ToLeftScaleBackReversePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromLeftSwitchFront_ToLeftScaleBackReversePath Class" << std::endl;
	m_instance = new FromLeftSwitchFront_ToLeftScaleBackReversePath();
	}
	return m_instance;
}
int FromLeftSwitchFront_ToLeftScaleBackReversePath::GetIndexLength()
{
	return num_index;
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetDT()
{
	return left_wheel[0][5];
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromLeftSwitchFront_ToLeftScaleBackReversePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromLeftSwitchFront_ToLeftScaleBackReversePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromLeftSwitchFront_ToLeftScaleBackReversePath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

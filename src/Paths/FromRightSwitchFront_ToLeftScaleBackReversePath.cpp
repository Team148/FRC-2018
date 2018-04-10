#include "FromRightSwitchFront_ToLeftScaleBackReversePath.h"
#include <iostream>

FromRightSwitchFront_ToLeftScaleBackReversePath *FromRightSwitchFront_ToLeftScaleBackReversePath::m_instance = 0;

FromRightSwitchFront_ToLeftScaleBackReversePath::FromRightSwitchFront_ToLeftScaleBackReversePath()
{
}
TrajectoryPath* FromRightSwitchFront_ToLeftScaleBackReversePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightSwitchFront_ToLeftScaleBackReversePath Class" << std::endl;
	m_instance = new FromRightSwitchFront_ToLeftScaleBackReversePath();
	}
	return m_instance;
}
int FromRightSwitchFront_ToLeftScaleBackReversePath::GetIndexLength()
{
	return num_index;
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightSwitchFront_ToLeftScaleBackReversePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightSwitchFront_ToLeftScaleBackReversePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightSwitchFront_ToLeftScaleBackReversePath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

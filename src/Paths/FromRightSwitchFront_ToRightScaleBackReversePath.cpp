#include "FromRightSwitchFront_ToRightScaleBackReversePath.h"
#include <iostream>

FromRightSwitchFront_ToRightScaleBackReversePath *FromRightSwitchFront_ToRightScaleBackReversePath::m_instance = 0;

FromRightSwitchFront_ToRightScaleBackReversePath::FromRightSwitchFront_ToRightScaleBackReversePath()
{
}
TrajectoryPath* FromRightSwitchFront_ToRightScaleBackReversePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightSwitchFront_ToRightScaleBackReversePath Class" << std::endl;
	m_instance = new FromRightSwitchFront_ToRightScaleBackReversePath();
	}
	return m_instance;
}
int FromRightSwitchFront_ToRightScaleBackReversePath::GetIndexLength()
{
	return num_index;
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightSwitchFront_ToRightScaleBackReversePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightSwitchFront_ToRightScaleBackReversePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightSwitchFront_ToRightScaleBackReversePath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

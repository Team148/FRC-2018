#include "FromLeftSwitch_ToRightScalePath.h"
#include <iostream>

FromLeftSwitch_ToRightScalePath *FromLeftSwitch_ToRightScalePath::m_instance = 0;

FromLeftSwitch_ToRightScalePath::FromLeftSwitch_ToRightScalePath()
{
}
TrajectoryPath* FromLeftSwitch_ToRightScalePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromLeftSwitch_ToRightScalePath Class" << std::endl;
	m_instance = new FromLeftSwitch_ToRightScalePath();
	}
	return m_instance;
}
int FromLeftSwitch_ToRightScalePath::GetIndexLength()
{
	return num_index;
}
double FromLeftSwitch_ToRightScalePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromLeftSwitch_ToRightScalePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromLeftSwitch_ToRightScalePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromLeftSwitch_ToRightScalePath::GetDT()
{
	return left_wheel[0][5];
}
double FromLeftSwitch_ToRightScalePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromLeftSwitch_ToRightScalePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromLeftSwitch_ToRightScalePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromLeftSwitch_ToRightScalePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromLeftSwitch_ToRightScalePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromLeftSwitch_ToRightScalePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromLeftSwitch_ToRightScalePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromLeftSwitch_ToRightScalePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromLeftSwitch_ToRightScalePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromLeftSwitch_ToRightScalePath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromLeftSwitch_ToRightScalePath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

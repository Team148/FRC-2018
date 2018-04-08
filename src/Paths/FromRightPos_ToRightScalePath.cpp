#include "FromRightPos_ToRightScalePath.h"
#include <iostream>

FromRightPos_ToRightScalePath *FromRightPos_ToRightScalePath::m_instance = 0;

FromRightPos_ToRightScalePath::FromRightPos_ToRightScalePath()
{
}
TrajectoryPath* FromRightPos_ToRightScalePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToRightScalePath Class" << std::endl;
	m_instance = new FromRightPos_ToRightScalePath();
	}
	return m_instance;
}
int FromRightPos_ToRightScalePath::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToRightScalePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToRightScalePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToRightScalePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToRightScalePath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToRightScalePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToRightScalePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToRightScalePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToRightScalePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToRightScalePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToRightScalePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToRightScalePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToRightScalePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToRightScalePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightPos_ToRightScalePath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightPos_ToRightScalePath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

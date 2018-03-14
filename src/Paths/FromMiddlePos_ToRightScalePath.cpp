#include "FromMiddlePos_ToRightScalePath.h"
#include <iostream>

FromMiddlePos_ToRightScalePath *FromMiddlePos_ToRightScalePath::m_instance = 0;

FromMiddlePos_ToRightScalePath::FromMiddlePos_ToRightScalePath()
{
}
TrajectoryPath* FromMiddlePos_ToRightScalePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToRightScalePath Class" << std::endl;
	m_instance = new FromMiddlePos_ToRightScalePath();
	}
	return m_instance;
}
int FromMiddlePos_ToRightScalePath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToRightScalePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToRightScalePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToRightScalePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromMiddlePos_ToRightScalePath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToRightScalePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToRightScalePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToRightScalePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToRightScalePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToRightScalePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToRightScalePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToRightScalePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToRightScalePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToRightScalePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

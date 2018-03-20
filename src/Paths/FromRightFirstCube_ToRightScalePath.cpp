#include "FromRightFirstCube_ToRightScalePath.h"
#include <iostream>

FromRightFirstCube_ToRightScalePath *FromRightFirstCube_ToRightScalePath::m_instance = 0;

FromRightFirstCube_ToRightScalePath::FromRightFirstCube_ToRightScalePath()
{
}
TrajectoryPath* FromRightFirstCube_ToRightScalePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightFirstCube_ToRightScalePath Class" << std::endl;
	m_instance = new FromRightFirstCube_ToRightScalePath();
	}
	return m_instance;
}
int FromRightFirstCube_ToRightScalePath::GetIndexLength()
{
	return num_index;
}
double FromRightFirstCube_ToRightScalePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightFirstCube_ToRightScalePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightFirstCube_ToRightScalePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightFirstCube_ToRightScalePath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightFirstCube_ToRightScalePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightFirstCube_ToRightScalePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightFirstCube_ToRightScalePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightFirstCube_ToRightScalePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightFirstCube_ToRightScalePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightFirstCube_ToRightScalePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightFirstCube_ToRightScalePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightFirstCube_ToRightScalePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightFirstCube_ToRightScalePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

#include "FromRightSecondCube_ToRightScalePath.h"
#include <iostream>

FromRightSecondCube_ToRightScalePath *FromRightSecondCube_ToRightScalePath::m_instance = 0;

FromRightSecondCube_ToRightScalePath::FromRightSecondCube_ToRightScalePath()
{
}
TrajectoryPath* FromRightSecondCube_ToRightScalePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightSecondCube_ToRightScalePath Class" << std::endl;
	m_instance = new FromRightSecondCube_ToRightScalePath();
	}
	return m_instance;
}
int FromRightSecondCube_ToRightScalePath::GetIndexLength()
{
	return num_index;
}
double FromRightSecondCube_ToRightScalePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightSecondCube_ToRightScalePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightSecondCube_ToRightScalePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightSecondCube_ToRightScalePath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightSecondCube_ToRightScalePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightSecondCube_ToRightScalePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightSecondCube_ToRightScalePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightSecondCube_ToRightScalePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightSecondCube_ToRightScalePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightSecondCube_ToRightScalePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightSecondCube_ToRightScalePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightSecondCube_ToRightScalePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightSecondCube_ToRightScalePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

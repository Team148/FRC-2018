#include "FromRightScale_ToRightSecondCubePath.h"
#include <iostream>

FromRightScale_ToRightSecondCubePath *FromRightScale_ToRightSecondCubePath::m_instance = 0;

FromRightScale_ToRightSecondCubePath::FromRightScale_ToRightSecondCubePath()
{
}
TrajectoryPath* FromRightScale_ToRightSecondCubePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightScale_ToRightSecondCubePath Class" << std::endl;
	m_instance = new FromRightScale_ToRightSecondCubePath();
	}
	return m_instance;
}
int FromRightScale_ToRightSecondCubePath::GetIndexLength()
{
	return num_index;
}
double FromRightScale_ToRightSecondCubePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightScale_ToRightSecondCubePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightScale_ToRightSecondCubePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightScale_ToRightSecondCubePath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightScale_ToRightSecondCubePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightScale_ToRightSecondCubePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightScale_ToRightSecondCubePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightScale_ToRightSecondCubePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightScale_ToRightSecondCubePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightScale_ToRightSecondCubePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightScale_ToRightSecondCubePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightScale_ToRightSecondCubePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightScale_ToRightSecondCubePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

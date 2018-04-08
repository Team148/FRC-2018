#include "FromRightScale_ToRightFirstCubePath.h"
#include <iostream>

FromRightScale_ToRightFirstCubePath *FromRightScale_ToRightFirstCubePath::m_instance = 0;

FromRightScale_ToRightFirstCubePath::FromRightScale_ToRightFirstCubePath()
{
}
TrajectoryPath* FromRightScale_ToRightFirstCubePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightScale_ToRightFirstCubePath Class" << std::endl;
	m_instance = new FromRightScale_ToRightFirstCubePath();
	}
	return m_instance;
}
int FromRightScale_ToRightFirstCubePath::GetIndexLength()
{
	return num_index;
}
double FromRightScale_ToRightFirstCubePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightScale_ToRightFirstCubePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightScale_ToRightFirstCubePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightScale_ToRightFirstCubePath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightScale_ToRightFirstCubePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightScale_ToRightFirstCubePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightScale_ToRightFirstCubePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightScale_ToRightFirstCubePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightScale_ToRightFirstCubePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightScale_ToRightFirstCubePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightScale_ToRightFirstCubePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightScale_ToRightFirstCubePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightScale_ToRightFirstCubePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightScale_ToRightFirstCubePath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightScale_ToRightFirstCubePath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

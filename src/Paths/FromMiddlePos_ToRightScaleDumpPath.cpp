#include "FromMiddlePos_ToRightScaleDumpPath.h"
#include <iostream>

FromMiddlePos_ToRightScaleDumpPath *FromMiddlePos_ToRightScaleDumpPath::m_instance = 0;

FromMiddlePos_ToRightScaleDumpPath::FromMiddlePos_ToRightScaleDumpPath()
{
}
TrajectoryPath* FromMiddlePos_ToRightScaleDumpPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToRightScaleDumpPath Class" << std::endl;
	m_instance = new FromMiddlePos_ToRightScaleDumpPath();
	}
	return m_instance;
}
int FromMiddlePos_ToRightScaleDumpPath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToRightScaleDumpPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToRightScaleDumpPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToRightScaleDumpPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromMiddlePos_ToRightScaleDumpPath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToRightScaleDumpPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToRightScaleDumpPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToRightScaleDumpPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToRightScaleDumpPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToRightScaleDumpPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToRightScaleDumpPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToRightScaleDumpPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToRightScaleDumpPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToRightScaleDumpPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromMiddlePos_ToRightScaleDumpPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromMiddlePos_ToRightScaleDumpPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

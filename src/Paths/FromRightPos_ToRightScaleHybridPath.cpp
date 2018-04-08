#include "FromRightPos_ToRightScaleHybridPath.h"
#include <iostream>

FromRightPos_ToRightScaleHybridPath *FromRightPos_ToRightScaleHybridPath::m_instance = 0;

FromRightPos_ToRightScaleHybridPath::FromRightPos_ToRightScaleHybridPath()
{
}
TrajectoryPath* FromRightPos_ToRightScaleHybridPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToRightScaleHybridPath Class" << std::endl;
	m_instance = new FromRightPos_ToRightScaleHybridPath();
	}
	return m_instance;
}
int FromRightPos_ToRightScaleHybridPath::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToRightScaleHybridPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToRightScaleHybridPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToRightScaleHybridPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToRightScaleHybridPath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToRightScaleHybridPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToRightScaleHybridPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToRightScaleHybridPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToRightScaleHybridPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToRightScaleHybridPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToRightScaleHybridPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToRightScaleHybridPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToRightScaleHybridPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToRightScaleHybridPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightPos_ToRightScaleHybridPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightPos_ToRightScaleHybridPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

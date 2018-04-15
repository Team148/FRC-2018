#include "FromMiddlePos_ToRightScaleSneakPath.h"
#include <iostream>

FromMiddlePos_ToRightScaleSneakPath *FromMiddlePos_ToRightScaleSneakPath::m_instance = 0;

FromMiddlePos_ToRightScaleSneakPath::FromMiddlePos_ToRightScaleSneakPath()
{
}
TrajectoryPath* FromMiddlePos_ToRightScaleSneakPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToRightScaleSneakPath Class" << std::endl;
	m_instance = new FromMiddlePos_ToRightScaleSneakPath();
	}
	return m_instance;
}
int FromMiddlePos_ToRightScaleSneakPath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToRightScaleSneakPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToRightScaleSneakPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToRightScaleSneakPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromMiddlePos_ToRightScaleSneakPath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToRightScaleSneakPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToRightScaleSneakPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToRightScaleSneakPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToRightScaleSneakPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToRightScaleSneakPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToRightScaleSneakPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToRightScaleSneakPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToRightScaleSneakPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToRightScaleSneakPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromMiddlePos_ToRightScaleSneakPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromMiddlePos_ToRightScaleSneakPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

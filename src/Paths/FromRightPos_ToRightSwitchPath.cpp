#include "FromRightPos_ToRightSwitchPath.h"
#include <iostream>

FromRightPos_ToRightSwitchPath *FromRightPos_ToRightSwitchPath::m_instance = 0;

FromRightPos_ToRightSwitchPath::FromRightPos_ToRightSwitchPath()
{
}
TrajectoryPath* FromRightPos_ToRightSwitchPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToRightSwitchPath Class" << std::endl;
	m_instance = new FromRightPos_ToRightSwitchPath();
	}
	return m_instance;
}
int FromRightPos_ToRightSwitchPath::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToRightSwitchPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToRightSwitchPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToRightSwitchPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToRightSwitchPath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToRightSwitchPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToRightSwitchPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToRightSwitchPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToRightSwitchPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToRightSwitchPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToRightSwitchPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToRightSwitchPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToRightSwitchPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToRightSwitchPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightPos_ToRightSwitchPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightPos_ToRightSwitchPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

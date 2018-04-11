#include "FromMiddlePos_ToRightSwitchBackPath.h"
#include <iostream>

FromMiddlePos_ToRightSwitchBackPath *FromMiddlePos_ToRightSwitchBackPath::m_instance = 0;

FromMiddlePos_ToRightSwitchBackPath::FromMiddlePos_ToRightSwitchBackPath()
{
}
TrajectoryPath* FromMiddlePos_ToRightSwitchBackPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToRightSwitchBackPath Class" << std::endl;
	m_instance = new FromMiddlePos_ToRightSwitchBackPath();
	}
	return m_instance;
}
int FromMiddlePos_ToRightSwitchBackPath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToRightSwitchBackPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToRightSwitchBackPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToRightSwitchBackPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromMiddlePos_ToRightSwitchBackPath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToRightSwitchBackPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToRightSwitchBackPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToRightSwitchBackPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToRightSwitchBackPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToRightSwitchBackPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToRightSwitchBackPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToRightSwitchBackPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToRightSwitchBackPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToRightSwitchBackPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromMiddlePos_ToRightSwitchBackPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromMiddlePos_ToRightSwitchBackPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

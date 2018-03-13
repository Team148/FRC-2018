#include "FromMiddlePos_ToRightSwitchPath.h"
#include <iostream>

FromMiddlePos_ToRightSwitchPath *FromMiddlePos_ToRightSwitchPath::m_instance = 0;

FromMiddlePos_ToRightSwitchPath::FromMiddlePos_ToRightSwitchPath()
{
}
TrajectoryPath* FromMiddlePos_ToRightSwitchPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToRightSwitchPath Class" << std::endl;
	m_instance = new FromMiddlePos_ToRightSwitchPath();
	}
	return m_instance;
}
int FromMiddlePos_ToRightSwitchPath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToRightSwitchPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToRightSwitchPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToRightSwitchPath::GetTimeLength()
{
	return left_wheel[0][6] * (num_index-1);
}
double FromMiddlePos_ToRightSwitchPath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToRightSwitchPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToRightSwitchPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToRightSwitchPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToRightSwitchPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToRightSwitchPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToRightSwitchPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToRightSwitchPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToRightSwitchPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToRightSwitchPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

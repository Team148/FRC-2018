#include "FromMiddlePos_ToRightSwitchSneakPath.h"
#include <iostream>

FromMiddlePos_ToRightSwitchSneakPath *FromMiddlePos_ToRightSwitchSneakPath::m_instance = 0;

FromMiddlePos_ToRightSwitchSneakPath::FromMiddlePos_ToRightSwitchSneakPath()
{
}
TrajectoryPath* FromMiddlePos_ToRightSwitchSneakPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToRightSwitchSneakPath Class" << std::endl;
	m_instance = new FromMiddlePos_ToRightSwitchSneakPath();
	}
	return m_instance;
}
int FromMiddlePos_ToRightSwitchSneakPath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToRightSwitchSneakPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToRightSwitchSneakPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToRightSwitchSneakPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromMiddlePos_ToRightSwitchSneakPath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToRightSwitchSneakPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToRightSwitchSneakPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToRightSwitchSneakPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToRightSwitchSneakPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToRightSwitchSneakPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToRightSwitchSneakPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToRightSwitchSneakPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToRightSwitchSneakPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToRightSwitchSneakPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromMiddlePos_ToRightSwitchSneakPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromMiddlePos_ToRightSwitchSneakPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

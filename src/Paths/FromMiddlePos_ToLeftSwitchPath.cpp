#include "FromMiddlePos_ToLeftSwitchPath.h"
#include <iostream>

FromMiddlePos_ToLeftSwitchPath *FromMiddlePos_ToLeftSwitchPath::m_instance = 0;

FromMiddlePos_ToLeftSwitchPath::FromMiddlePos_ToLeftSwitchPath()
{
}
TrajectoryPath* FromMiddlePos_ToLeftSwitchPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToLeftSwitchPath Class" << std::endl;
	m_instance = new FromMiddlePos_ToLeftSwitchPath();
	}
	return m_instance;
}
int FromMiddlePos_ToLeftSwitchPath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToLeftSwitchPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToLeftSwitchPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToLeftSwitchPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromMiddlePos_ToLeftSwitchPath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToLeftSwitchPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToLeftSwitchPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToLeftSwitchPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToLeftSwitchPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToLeftSwitchPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToLeftSwitchPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToLeftSwitchPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToLeftSwitchPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToLeftSwitchPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromMiddlePos_ToLeftSwitchPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromMiddlePos_ToLeftSwitchPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

#include "FromMiddlePos_ToLeftSwitchBackPath.h"
#include <iostream>

FromMiddlePos_ToLeftSwitchBackPath *FromMiddlePos_ToLeftSwitchBackPath::m_instance = 0;

FromMiddlePos_ToLeftSwitchBackPath::FromMiddlePos_ToLeftSwitchBackPath()
{
}
TrajectoryPath* FromMiddlePos_ToLeftSwitchBackPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToLeftSwitchBackPath Class" << std::endl;
	m_instance = new FromMiddlePos_ToLeftSwitchBackPath();
	}
	return m_instance;
}
int FromMiddlePos_ToLeftSwitchBackPath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToLeftSwitchBackPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToLeftSwitchBackPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToLeftSwitchBackPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromMiddlePos_ToLeftSwitchBackPath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToLeftSwitchBackPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToLeftSwitchBackPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToLeftSwitchBackPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToLeftSwitchBackPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToLeftSwitchBackPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToLeftSwitchBackPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToLeftSwitchBackPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToLeftSwitchBackPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToLeftSwitchBackPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromMiddlePos_ToLeftSwitchBackPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromMiddlePos_ToLeftSwitchBackPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

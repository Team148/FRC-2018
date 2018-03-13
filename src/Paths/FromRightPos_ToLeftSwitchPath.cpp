#include "FromRightPos_ToLeftSwitchPath.h"
#include <iostream>

FromRightPos_ToLeftSwitchPath *FromRightPos_ToLeftSwitchPath::m_instance = 0;

FromRightPos_ToLeftSwitchPath::FromRightPos_ToLeftSwitchPath()
{
}
TrajectoryPath* FromRightPos_ToLeftSwitchPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftSwitchPath Class" << std::endl;
	m_instance = new FromRightPos_ToLeftSwitchPath();
	}
	return m_instance;
}
int FromRightPos_ToLeftSwitchPath::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftSwitchPath::GetInitialHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftSwitchPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftSwitchPath::GetTimeLength()
{
	return left_wheel[0][6] * (num_index-1);
}
double FromRightPos_ToLeftSwitchPath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftSwitchPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftSwitchPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftSwitchPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftSwitchPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftSwitchPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftSwitchPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftSwitchPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftSwitchPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftSwitchPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

#include "FromRightFirstCube_ToLeftSwitchPathReversed.h"
#include <iostream>

FromRightFirstCube_ToLeftSwitchPathReversed *FromRightFirstCube_ToLeftSwitchPathReversed::m_instance = 0;

FromRightFirstCube_ToLeftSwitchPathReversed::FromRightFirstCube_ToLeftSwitchPathReversed()
{
}
TrajectoryPath* FromRightFirstCube_ToLeftSwitchPathReversed::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightFirstCube_ToLeftSwitchPathReversed Class" << std::endl;
	m_instance = new FromRightFirstCube_ToLeftSwitchPathReversed();
	}
	return m_instance;
}
int FromRightFirstCube_ToLeftSwitchPathReversed::GetIndexLength()
{
	return num_index;
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetDT()
{
	return left_wheel[0][5];
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightFirstCube_ToLeftSwitchPathReversed::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightFirstCube_ToLeftSwitchPathReversed::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightFirstCube_ToLeftSwitchPathReversed::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

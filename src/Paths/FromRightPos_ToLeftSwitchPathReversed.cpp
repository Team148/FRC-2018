#include "FromRightPos_ToLeftSwitchPathReversed.h"
#include <iostream>

FromRightPos_ToLeftSwitchPathReversed *FromRightPos_ToLeftSwitchPathReversed::m_instance = 0;

FromRightPos_ToLeftSwitchPathReversed::FromRightPos_ToLeftSwitchPathReversed()
{
}
TrajectoryPath* FromRightPos_ToLeftSwitchPathReversed::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftSwitchPathReversed Class" << std::endl;
	m_instance = new FromRightPos_ToLeftSwitchPathReversed();
	}
	return m_instance;
}
int FromRightPos_ToLeftSwitchPathReversed::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftSwitchPathReversed::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftSwitchPathReversed::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftSwitchPathReversed::GetTimeLength()
{
	return left_wheel[0][6] * (num_index-1);
}
double FromRightPos_ToLeftSwitchPathReversed::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftSwitchPathReversed::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftSwitchPathReversed::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftSwitchPathReversed::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftSwitchPathReversed::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftSwitchPathReversed::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftSwitchPathReversed::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftSwitchPathReversed::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftSwitchPathReversed::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftSwitchPathReversed::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

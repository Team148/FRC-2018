#include "FromLeftSwitch_ToLeftScalePathReversed.h"
#include <iostream>

FromLeftSwitch_ToLeftScalePathReversed *FromLeftSwitch_ToLeftScalePathReversed::m_instance = 0;

FromLeftSwitch_ToLeftScalePathReversed::FromLeftSwitch_ToLeftScalePathReversed()
{
}
TrajectoryPath* FromLeftSwitch_ToLeftScalePathReversed::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromLeftSwitch_ToLeftScalePathReversed Class" << std::endl;
	m_instance = new FromLeftSwitch_ToLeftScalePathReversed();
	}
	return m_instance;
}
int FromLeftSwitch_ToLeftScalePathReversed::GetIndexLength()
{
	return num_index;
}
double FromLeftSwitch_ToLeftScalePathReversed::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromLeftSwitch_ToLeftScalePathReversed::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromLeftSwitch_ToLeftScalePathReversed::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromLeftSwitch_ToLeftScalePathReversed::GetDT()
{
	return left_wheel[0][5];
}
double FromLeftSwitch_ToLeftScalePathReversed::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromLeftSwitch_ToLeftScalePathReversed::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromLeftSwitch_ToLeftScalePathReversed::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromLeftSwitch_ToLeftScalePathReversed::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromLeftSwitch_ToLeftScalePathReversed::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromLeftSwitch_ToLeftScalePathReversed::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromLeftSwitch_ToLeftScalePathReversed::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromLeftSwitch_ToLeftScalePathReversed::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromLeftSwitch_ToLeftScalePathReversed::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromLeftSwitch_ToLeftScalePathReversed::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromLeftSwitch_ToLeftScalePathReversed::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

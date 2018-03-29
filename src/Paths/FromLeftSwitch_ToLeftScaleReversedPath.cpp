#include "FromLeftSwitch_ToLeftScaleReversedPath.h"
#include <iostream>

FromLeftSwitch_ToLeftScaleReversedPath *FromLeftSwitch_ToLeftScaleReversedPath::m_instance = 0;

FromLeftSwitch_ToLeftScaleReversedPath::FromLeftSwitch_ToLeftScaleReversedPath()
{
}
TrajectoryPath* FromLeftSwitch_ToLeftScaleReversedPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromLeftSwitch_ToLeftScaleReversedPath Class" << std::endl;
	m_instance = new FromLeftSwitch_ToLeftScaleReversedPath();
	}
	return m_instance;
}
int FromLeftSwitch_ToLeftScaleReversedPath::GetIndexLength()
{
	return num_index;
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetDT()
{
	return left_wheel[0][5];
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromLeftSwitch_ToLeftScaleReversedPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromLeftSwitch_ToLeftScaleReversedPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromLeftSwitch_ToLeftScaleReversedPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

#include "FromLeftSwitch_ToLeftScalePath.h"
#include <iostream>

FromLeftSwitch_ToLeftScalePath *FromLeftSwitch_ToLeftScalePath::m_instance = 0;

FromLeftSwitch_ToLeftScalePath::FromLeftSwitch_ToLeftScalePath()
{
}
TrajectoryPath* FromLeftSwitch_ToLeftScalePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromLeftSwitch_ToLeftScalePath Class" << std::endl;
	m_instance = new FromLeftSwitch_ToLeftScalePath();
	}
	return m_instance;
}
int FromLeftSwitch_ToLeftScalePath::GetIndexLength()
{
	return num_index;
}
double FromLeftSwitch_ToLeftScalePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromLeftSwitch_ToLeftScalePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromLeftSwitch_ToLeftScalePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromLeftSwitch_ToLeftScalePath::GetDT()
{
	return left_wheel[0][5];
}
double FromLeftSwitch_ToLeftScalePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromLeftSwitch_ToLeftScalePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromLeftSwitch_ToLeftScalePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromLeftSwitch_ToLeftScalePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromLeftSwitch_ToLeftScalePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromLeftSwitch_ToLeftScalePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromLeftSwitch_ToLeftScalePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromLeftSwitch_ToLeftScalePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromLeftSwitch_ToLeftScalePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

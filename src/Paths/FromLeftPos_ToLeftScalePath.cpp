#include "FromLeftPos_ToLeftScalePath.h"
#include <iostream>

FromLeftPos_ToLeftScalePath *FromLeftPos_ToLeftScalePath::m_instance = 0;

FromLeftPos_ToLeftScalePath::FromLeftPos_ToLeftScalePath()
{
}
TrajectoryPath* FromLeftPos_ToLeftScalePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromLeftPos_ToLeftScalePath Class" << std::endl;
	m_instance = new FromLeftPos_ToLeftScalePath();
	}
	return m_instance;
}
int FromLeftPos_ToLeftScalePath::GetIndexLength()
{
	return num_index;
}
double FromLeftPos_ToLeftScalePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromLeftPos_ToLeftScalePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromLeftPos_ToLeftScalePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromLeftPos_ToLeftScalePath::GetDT()
{
	return left_wheel[0][5];
}
double FromLeftPos_ToLeftScalePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromLeftPos_ToLeftScalePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromLeftPos_ToLeftScalePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromLeftPos_ToLeftScalePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromLeftPos_ToLeftScalePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromLeftPos_ToLeftScalePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromLeftPos_ToLeftScalePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromLeftPos_ToLeftScalePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromLeftPos_ToLeftScalePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromLeftPos_ToLeftScalePath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromLeftPos_ToLeftScalePath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

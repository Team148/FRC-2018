#include "FromRightPos_ToLeftScalePath.h"
#include <iostream>

FromRightPos_ToLeftScalePath *FromRightPos_ToLeftScalePath::m_instance = 0;

FromRightPos_ToLeftScalePath::FromRightPos_ToLeftScalePath()
{
}
TrajectoryPath* FromRightPos_ToLeftScalePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftScalePath Class" << std::endl;
	m_instance = new FromRightPos_ToLeftScalePath();
	}
	return m_instance;
}
int FromRightPos_ToLeftScalePath::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftScalePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftScalePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftScalePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToLeftScalePath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftScalePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftScalePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftScalePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftScalePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftScalePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftScalePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftScalePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftScalePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftScalePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightPos_ToLeftScalePath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightPos_ToLeftScalePath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

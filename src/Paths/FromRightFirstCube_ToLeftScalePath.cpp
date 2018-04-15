#include "FromRightFirstCube_ToLeftScalePath.h"
#include <iostream>

FromRightFirstCube_ToLeftScalePath *FromRightFirstCube_ToLeftScalePath::m_instance = 0;

FromRightFirstCube_ToLeftScalePath::FromRightFirstCube_ToLeftScalePath()
{
}
TrajectoryPath* FromRightFirstCube_ToLeftScalePath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightFirstCube_ToLeftScalePath Class" << std::endl;
	m_instance = new FromRightFirstCube_ToLeftScalePath();
	}
	return m_instance;
}
int FromRightFirstCube_ToLeftScalePath::GetIndexLength()
{
	return num_index;
}
double FromRightFirstCube_ToLeftScalePath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightFirstCube_ToLeftScalePath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightFirstCube_ToLeftScalePath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightFirstCube_ToLeftScalePath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightFirstCube_ToLeftScalePath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightFirstCube_ToLeftScalePath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightFirstCube_ToLeftScalePath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightFirstCube_ToLeftScalePath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightFirstCube_ToLeftScalePath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightFirstCube_ToLeftScalePath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightFirstCube_ToLeftScalePath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightFirstCube_ToLeftScalePath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightFirstCube_ToLeftScalePath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightFirstCube_ToLeftScalePath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightFirstCube_ToLeftScalePath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

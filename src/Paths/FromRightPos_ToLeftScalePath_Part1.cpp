#include "FromRightPos_ToLeftScalePath_Part1.h"
#include <iostream>

FromRightPos_ToLeftScalePath_Part1 *FromRightPos_ToLeftScalePath_Part1::m_instance = 0;

FromRightPos_ToLeftScalePath_Part1::FromRightPos_ToLeftScalePath_Part1()
{
}
TrajectoryPath* FromRightPos_ToLeftScalePath_Part1::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftScalePath_Part1 Class" << std::endl;
	m_instance = new FromRightPos_ToLeftScalePath_Part1();
	}
	return m_instance;
}
int FromRightPos_ToLeftScalePath_Part1::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftScalePath_Part1::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftScalePath_Part1::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftScalePath_Part1::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToLeftScalePath_Part1::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftScalePath_Part1::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftScalePath_Part1::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftScalePath_Part1::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftScalePath_Part1::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftScalePath_Part1::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftScalePath_Part1::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftScalePath_Part1::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftScalePath_Part1::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftScalePath_Part1::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

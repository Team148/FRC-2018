#include "FromRightPos_ToLeftScalePath_Part2.h"
#include <iostream>

FromRightPos_ToLeftScalePath_Part2 *FromRightPos_ToLeftScalePath_Part2::m_instance = 0;

FromRightPos_ToLeftScalePath_Part2::FromRightPos_ToLeftScalePath_Part2()
{
}
TrajectoryPath* FromRightPos_ToLeftScalePath_Part2::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftScalePath_Part2 Class" << std::endl;
	m_instance = new FromRightPos_ToLeftScalePath_Part2();
	}
	return m_instance;
}
int FromRightPos_ToLeftScalePath_Part2::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftScalePath_Part2::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftScalePath_Part2::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftScalePath_Part2::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToLeftScalePath_Part2::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftScalePath_Part2::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftScalePath_Part2::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftScalePath_Part2::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftScalePath_Part2::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftScalePath_Part2::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftScalePath_Part2::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftScalePath_Part2::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftScalePath_Part2::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftScalePath_Part2::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

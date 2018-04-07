#include "FromRightPos_ToLeftScalePath_Part3.h"
#include <iostream>

FromRightPos_ToLeftScalePath_Part3 *FromRightPos_ToLeftScalePath_Part3::m_instance = 0;

FromRightPos_ToLeftScalePath_Part3::FromRightPos_ToLeftScalePath_Part3()
{
}
TrajectoryPath* FromRightPos_ToLeftScalePath_Part3::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftScalePath_Part3 Class" << std::endl;
	m_instance = new FromRightPos_ToLeftScalePath_Part3();
	}
	return m_instance;
}
int FromRightPos_ToLeftScalePath_Part3::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftScalePath_Part3::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftScalePath_Part3::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftScalePath_Part3::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToLeftScalePath_Part3::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftScalePath_Part3::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftScalePath_Part3::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftScalePath_Part3::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftScalePath_Part3::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftScalePath_Part3::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftScalePath_Part3::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftScalePath_Part3::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftScalePath_Part3::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftScalePath_Part3::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

#include "FromRightPos_ToLeftScalePathSpecial.h"
#include <iostream>

FromRightPos_ToLeftScalePathSpecial *FromRightPos_ToLeftScalePathSpecial::m_instance = 0;

FromRightPos_ToLeftScalePathSpecial::FromRightPos_ToLeftScalePathSpecial()
{
}
TrajectoryPath* FromRightPos_ToLeftScalePathSpecial::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftScalePathSpecial Class" << std::endl;
	m_instance = new FromRightPos_ToLeftScalePathSpecial();
	}
	return m_instance;
}
int FromRightPos_ToLeftScalePathSpecial::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftScalePathSpecial::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftScalePathSpecial::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftScalePathSpecial::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToLeftScalePathSpecial::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftScalePathSpecial::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftScalePathSpecial::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftScalePathSpecial::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftScalePathSpecial::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftScalePathSpecial::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftScalePathSpecial::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftScalePathSpecial::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftScalePathSpecial::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftScalePathSpecial::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightPos_ToLeftScalePathSpecial::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightPos_ToLeftScalePathSpecial::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

#include "FromMiddlePos_ToLeftScaleSneakPath.h"
#include <iostream>

FromMiddlePos_ToLeftScaleSneakPath *FromMiddlePos_ToLeftScaleSneakPath::m_instance = 0;

FromMiddlePos_ToLeftScaleSneakPath::FromMiddlePos_ToLeftScaleSneakPath()
{
}
TrajectoryPath* FromMiddlePos_ToLeftScaleSneakPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToLeftScaleSneakPath Class" << std::endl;
	m_instance = new FromMiddlePos_ToLeftScaleSneakPath();
	}
	return m_instance;
}
int FromMiddlePos_ToLeftScaleSneakPath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToLeftScaleSneakPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToLeftScaleSneakPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToLeftScaleSneakPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromMiddlePos_ToLeftScaleSneakPath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToLeftScaleSneakPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToLeftScaleSneakPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToLeftScaleSneakPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToLeftScaleSneakPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToLeftScaleSneakPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToLeftScaleSneakPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToLeftScaleSneakPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToLeftScaleSneakPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToLeftScaleSneakPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromMiddlePos_ToLeftScaleSneakPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromMiddlePos_ToLeftScaleSneakPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

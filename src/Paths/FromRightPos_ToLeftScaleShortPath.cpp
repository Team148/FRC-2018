#include "FromRightPos_ToLeftScaleShortPath.h"
#include <iostream>

FromRightPos_ToLeftScaleShortPath *FromRightPos_ToLeftScaleShortPath::m_instance = 0;

FromRightPos_ToLeftScaleShortPath::FromRightPos_ToLeftScaleShortPath()
{
}
TrajectoryPath* FromRightPos_ToLeftScaleShortPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftScaleShortPath Class" << std::endl;
	m_instance = new FromRightPos_ToLeftScaleShortPath();
	}
	return m_instance;
}
int FromRightPos_ToLeftScaleShortPath::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftScaleShortPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftScaleShortPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftScaleShortPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToLeftScaleShortPath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftScaleShortPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftScaleShortPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftScaleShortPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftScaleShortPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftScaleShortPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftScaleShortPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftScaleShortPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftScaleShortPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftScaleShortPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightPos_ToLeftScaleShortPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightPos_ToLeftScaleShortPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

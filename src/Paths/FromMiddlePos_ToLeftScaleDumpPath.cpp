#include "FromMiddlePos_ToLeftScaleDumpPath.h"
#include <iostream>

FromMiddlePos_ToLeftScaleDumpPath *FromMiddlePos_ToLeftScaleDumpPath::m_instance = 0;

FromMiddlePos_ToLeftScaleDumpPath::FromMiddlePos_ToLeftScaleDumpPath()
{
}
TrajectoryPath* FromMiddlePos_ToLeftScaleDumpPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToLeftScaleDumpPath Class" << std::endl;
	m_instance = new FromMiddlePos_ToLeftScaleDumpPath();
	}
	return m_instance;
}
int FromMiddlePos_ToLeftScaleDumpPath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToLeftScaleDumpPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToLeftScaleDumpPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToLeftScaleDumpPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromMiddlePos_ToLeftScaleDumpPath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToLeftScaleDumpPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToLeftScaleDumpPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToLeftScaleDumpPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToLeftScaleDumpPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToLeftScaleDumpPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToLeftScaleDumpPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToLeftScaleDumpPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToLeftScaleDumpPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToLeftScaleDumpPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromMiddlePos_ToLeftScaleDumpPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromMiddlePos_ToLeftScaleDumpPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

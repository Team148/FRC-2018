#include "FromRightPos_ToLeftScale118Path.h"
#include <iostream>

FromRightPos_ToLeftScale118Path *FromRightPos_ToLeftScale118Path::m_instance = 0;

FromRightPos_ToLeftScale118Path::FromRightPos_ToLeftScale118Path()
{
}
TrajectoryPath* FromRightPos_ToLeftScale118Path::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftScale118Path Class" << std::endl;
	m_instance = new FromRightPos_ToLeftScale118Path();
	}
	return m_instance;
}
int FromRightPos_ToLeftScale118Path::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftScale118Path::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftScale118Path::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftScale118Path::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToLeftScale118Path::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftScale118Path::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftScale118Path::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftScale118Path::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftScale118Path::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftScale118Path::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftScale118Path::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftScale118Path::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftScale118Path::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftScale118Path::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightPos_ToLeftScale118Path::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightPos_ToLeftScale118Path::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

#include "FromRightLS_ToRightShip2.h"
#include <iostream>

FromRightLS_ToRightShip2 *FromRightLS_ToRightShip2::m_instance = 0;

FromRightLS_ToRightShip2::FromRightLS_ToRightShip2()
{
}
TrajectoryPath* FromRightLS_ToRightShip2::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightLS_ToRightShip2 Class" << std::endl;
	m_instance = new FromRightLS_ToRightShip2();
	}
	return m_instance;
}
int FromRightLS_ToRightShip2::GetIndexLength()
{
	return num_index;
}
double FromRightLS_ToRightShip2::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightLS_ToRightShip2::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightLS_ToRightShip2::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightLS_ToRightShip2::GetDT()
{
	return left_wheel[0][5];
}
double FromRightLS_ToRightShip2::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightLS_ToRightShip2::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightLS_ToRightShip2::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightLS_ToRightShip2::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightLS_ToRightShip2::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightLS_ToRightShip2::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightLS_ToRightShip2::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightLS_ToRightShip2::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightLS_ToRightShip2::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightLS_ToRightShip2::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightLS_ToRightShip2::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

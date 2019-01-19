#include "FromRightPos_ToRightShip1.h"
#include <iostream>

FromRightPos_ToRightShip1 *FromRightPos_ToRightShip1::m_instance = 0;

FromRightPos_ToRightShip1::FromRightPos_ToRightShip1()
{
}
TrajectoryPath* FromRightPos_ToRightShip1::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToRightShip1 Class" << std::endl;
	m_instance = new FromRightPos_ToRightShip1();
	}
	return m_instance;
}
int FromRightPos_ToRightShip1::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToRightShip1::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToRightShip1::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToRightShip1::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToRightShip1::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToRightShip1::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToRightShip1::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToRightShip1::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToRightShip1::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToRightShip1::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToRightShip1::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToRightShip1::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToRightShip1::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToRightShip1::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightPos_ToRightShip1::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightPos_ToRightShip1::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

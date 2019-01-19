#include "FromRightShip1_ToRightLS.h"
#include <iostream>

FromRightShip1_ToRightLS *FromRightShip1_ToRightLS::m_instance = 0;

FromRightShip1_ToRightLS::FromRightShip1_ToRightLS()
{
}
TrajectoryPath* FromRightShip1_ToRightLS::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightShip1_ToRightLS Class" << std::endl;
	m_instance = new FromRightShip1_ToRightLS();
	}
	return m_instance;
}
int FromRightShip1_ToRightLS::GetIndexLength()
{
	return num_index;
}
double FromRightShip1_ToRightLS::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightShip1_ToRightLS::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightShip1_ToRightLS::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightShip1_ToRightLS::GetDT()
{
	return left_wheel[0][5];
}
double FromRightShip1_ToRightLS::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightShip1_ToRightLS::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightShip1_ToRightLS::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightShip1_ToRightLS::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightShip1_ToRightLS::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightShip1_ToRightLS::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightShip1_ToRightLS::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightShip1_ToRightLS::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightShip1_ToRightLS::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightShip1_ToRightLS::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightShip1_ToRightLS::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

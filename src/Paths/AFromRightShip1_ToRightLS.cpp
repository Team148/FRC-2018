#include "AFromRightShip1_ToRightLS.h"
#include <iostream>

AFromRightShip1_ToRightLS *AFromRightShip1_ToRightLS::m_instance = 0;

AFromRightShip1_ToRightLS::AFromRightShip1_ToRightLS()
{
}
TrajectoryPath* AFromRightShip1_ToRightLS::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating AFromRightShip1_ToRightLS Class" << std::endl;
	m_instance = new AFromRightShip1_ToRightLS();
	}
	return m_instance;
}
int AFromRightShip1_ToRightLS::GetIndexLength()
{
	return num_index;
}
double AFromRightShip1_ToRightLS::GetStartHeading()
{
	return left_wheel[0][4];
}
double AFromRightShip1_ToRightLS::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double AFromRightShip1_ToRightLS::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double AFromRightShip1_ToRightLS::GetDT()
{
	return left_wheel[0][5];
}
double AFromRightShip1_ToRightLS::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double AFromRightShip1_ToRightLS::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double AFromRightShip1_ToRightLS::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double AFromRightShip1_ToRightLS::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double AFromRightShip1_ToRightLS::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double AFromRightShip1_ToRightLS::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double AFromRightShip1_ToRightLS::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* AFromRightShip1_ToRightLS::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* AFromRightShip1_ToRightLS::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double AFromRightShip1_ToRightLS::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double AFromRightShip1_ToRightLS::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

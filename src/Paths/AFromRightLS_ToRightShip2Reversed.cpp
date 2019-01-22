#include "AFromRightLS_ToRightShip2Reversed.h"
#include <iostream>

AFromRightLS_ToRightShip2Reversed *AFromRightLS_ToRightShip2Reversed::m_instance = 0;

AFromRightLS_ToRightShip2Reversed::AFromRightLS_ToRightShip2Reversed()
{
}
TrajectoryPath* AFromRightLS_ToRightShip2Reversed::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating AFromRightLS_ToRightShip2Reversed Class" << std::endl;
	m_instance = new AFromRightLS_ToRightShip2Reversed();
	}
	return m_instance;
}
int AFromRightLS_ToRightShip2Reversed::GetIndexLength()
{
	return num_index;
}
double AFromRightLS_ToRightShip2Reversed::GetStartHeading()
{
	return left_wheel[0][4];
}
double AFromRightLS_ToRightShip2Reversed::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double AFromRightLS_ToRightShip2Reversed::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double AFromRightLS_ToRightShip2Reversed::GetDT()
{
	return left_wheel[0][5];
}
double AFromRightLS_ToRightShip2Reversed::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double AFromRightLS_ToRightShip2Reversed::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double AFromRightLS_ToRightShip2Reversed::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double AFromRightLS_ToRightShip2Reversed::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double AFromRightLS_ToRightShip2Reversed::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double AFromRightLS_ToRightShip2Reversed::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double AFromRightLS_ToRightShip2Reversed::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* AFromRightLS_ToRightShip2Reversed::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* AFromRightLS_ToRightShip2Reversed::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double AFromRightLS_ToRightShip2Reversed::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double AFromRightLS_ToRightShip2Reversed::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

#include "AFromRightPos_ToRightShip1Reversed.h"
#include <iostream>

AFromRightPos_ToRightShip1Reversed *AFromRightPos_ToRightShip1Reversed::m_instance = 0;

AFromRightPos_ToRightShip1Reversed::AFromRightPos_ToRightShip1Reversed()
{
}
TrajectoryPath* AFromRightPos_ToRightShip1Reversed::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating AFromRightPos_ToRightShip1Reversed Class" << std::endl;
	m_instance = new AFromRightPos_ToRightShip1Reversed();
	}
	return m_instance;
}
int AFromRightPos_ToRightShip1Reversed::GetIndexLength()
{
	return num_index;
}
double AFromRightPos_ToRightShip1Reversed::GetStartHeading()
{
	return left_wheel[0][4];
}
double AFromRightPos_ToRightShip1Reversed::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double AFromRightPos_ToRightShip1Reversed::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double AFromRightPos_ToRightShip1Reversed::GetDT()
{
	return left_wheel[0][5];
}
double AFromRightPos_ToRightShip1Reversed::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double AFromRightPos_ToRightShip1Reversed::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double AFromRightPos_ToRightShip1Reversed::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double AFromRightPos_ToRightShip1Reversed::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double AFromRightPos_ToRightShip1Reversed::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double AFromRightPos_ToRightShip1Reversed::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double AFromRightPos_ToRightShip1Reversed::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* AFromRightPos_ToRightShip1Reversed::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* AFromRightPos_ToRightShip1Reversed::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double AFromRightPos_ToRightShip1Reversed::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double AFromRightPos_ToRightShip1Reversed::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

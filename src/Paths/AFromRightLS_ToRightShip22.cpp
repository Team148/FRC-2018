#include "AFromRightLS_ToRightShip22.h"
#include <iostream>

AFromRightLS_ToRightShip22 *AFromRightLS_ToRightShip22::m_instance = 0;

AFromRightLS_ToRightShip22::AFromRightLS_ToRightShip22()
{
}
TrajectoryPath* AFromRightLS_ToRightShip22::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating AFromRightLS_ToRightShip22 Class" << std::endl;
	m_instance = new AFromRightLS_ToRightShip22();
	}
	return m_instance;
}
int AFromRightLS_ToRightShip22::GetIndexLength()
{
	return num_index;
}
double AFromRightLS_ToRightShip22::GetStartHeading()
{
	return left_wheel[0][4];
}
double AFromRightLS_ToRightShip22::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double AFromRightLS_ToRightShip22::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double AFromRightLS_ToRightShip22::GetDT()
{
	return left_wheel[0][5];
}
double AFromRightLS_ToRightShip22::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double AFromRightLS_ToRightShip22::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double AFromRightLS_ToRightShip22::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double AFromRightLS_ToRightShip22::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double AFromRightLS_ToRightShip22::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double AFromRightLS_ToRightShip22::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double AFromRightLS_ToRightShip22::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* AFromRightLS_ToRightShip22::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* AFromRightLS_ToRightShip22::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double AFromRightLS_ToRightShip22::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double AFromRightLS_ToRightShip22::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

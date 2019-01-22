#include "AFromRightPos_ToRightShip1Pt2.h"
#include <iostream>

AFromRightPos_ToRightShip1Pt2 *AFromRightPos_ToRightShip1Pt2::m_instance = 0;

AFromRightPos_ToRightShip1Pt2::AFromRightPos_ToRightShip1Pt2()
{
}
TrajectoryPath* AFromRightPos_ToRightShip1Pt2::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating AFromRightPos_ToRightShip1Pt2 Class" << std::endl;
	m_instance = new AFromRightPos_ToRightShip1Pt2();
	}
	return m_instance;
}
int AFromRightPos_ToRightShip1Pt2::GetIndexLength()
{
	return num_index;
}
double AFromRightPos_ToRightShip1Pt2::GetStartHeading()
{
	return left_wheel[0][4];
}
double AFromRightPos_ToRightShip1Pt2::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double AFromRightPos_ToRightShip1Pt2::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double AFromRightPos_ToRightShip1Pt2::GetDT()
{
	return left_wheel[0][5];
}
double AFromRightPos_ToRightShip1Pt2::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double AFromRightPos_ToRightShip1Pt2::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double AFromRightPos_ToRightShip1Pt2::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double AFromRightPos_ToRightShip1Pt2::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double AFromRightPos_ToRightShip1Pt2::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double AFromRightPos_ToRightShip1Pt2::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double AFromRightPos_ToRightShip1Pt2::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* AFromRightPos_ToRightShip1Pt2::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* AFromRightPos_ToRightShip1Pt2::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double AFromRightPos_ToRightShip1Pt2::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double AFromRightPos_ToRightShip1Pt2::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

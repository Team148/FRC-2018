#include "FromCenterPile_ToRightSwitchFront.h"
#include <iostream>

FromCenterPile_ToRightSwitchFront *FromCenterPile_ToRightSwitchFront::m_instance = 0;

FromCenterPile_ToRightSwitchFront::FromCenterPile_ToRightSwitchFront()
{
}
TrajectoryPath* FromCenterPile_ToRightSwitchFront::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromCenterPile_ToRightSwitchFront Class" << std::endl;
	m_instance = new FromCenterPile_ToRightSwitchFront();
	}
	return m_instance;
}
int FromCenterPile_ToRightSwitchFront::GetIndexLength()
{
	return num_index;
}
double FromCenterPile_ToRightSwitchFront::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromCenterPile_ToRightSwitchFront::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromCenterPile_ToRightSwitchFront::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromCenterPile_ToRightSwitchFront::GetDT()
{
	return left_wheel[0][5];
}
double FromCenterPile_ToRightSwitchFront::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromCenterPile_ToRightSwitchFront::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromCenterPile_ToRightSwitchFront::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromCenterPile_ToRightSwitchFront::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromCenterPile_ToRightSwitchFront::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromCenterPile_ToRightSwitchFront::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromCenterPile_ToRightSwitchFront::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromCenterPile_ToRightSwitchFront::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromCenterPile_ToRightSwitchFront::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromCenterPile_ToRightSwitchFront::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromCenterPile_ToRightSwitchFront::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

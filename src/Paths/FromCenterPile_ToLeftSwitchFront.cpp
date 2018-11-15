#include "FromCenterPile_ToLeftSwitchFront.h"
#include <iostream>

FromCenterPile_ToLeftSwitchFront *FromCenterPile_ToLeftSwitchFront::m_instance = 0;

FromCenterPile_ToLeftSwitchFront::FromCenterPile_ToLeftSwitchFront()
{
}
TrajectoryPath* FromCenterPile_ToLeftSwitchFront::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromCenterPile_ToLeftSwitchFront Class" << std::endl;
	m_instance = new FromCenterPile_ToLeftSwitchFront();
	}
	return m_instance;
}
int FromCenterPile_ToLeftSwitchFront::GetIndexLength()
{
	return num_index;
}
double FromCenterPile_ToLeftSwitchFront::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromCenterPile_ToLeftSwitchFront::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromCenterPile_ToLeftSwitchFront::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromCenterPile_ToLeftSwitchFront::GetDT()
{
	return left_wheel[0][5];
}
double FromCenterPile_ToLeftSwitchFront::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromCenterPile_ToLeftSwitchFront::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromCenterPile_ToLeftSwitchFront::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromCenterPile_ToLeftSwitchFront::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromCenterPile_ToLeftSwitchFront::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromCenterPile_ToLeftSwitchFront::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromCenterPile_ToLeftSwitchFront::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromCenterPile_ToLeftSwitchFront::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromCenterPile_ToLeftSwitchFront::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromCenterPile_ToLeftSwitchFront::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromCenterPile_ToLeftSwitchFront::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

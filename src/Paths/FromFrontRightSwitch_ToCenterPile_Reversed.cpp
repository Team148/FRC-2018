#include "FromFrontRightSwitch_ToCenterPile_Reversed.h"
#include <iostream>

FromFrontRightSwitch_ToCenterPile_Reversed *FromFrontRightSwitch_ToCenterPile_Reversed::m_instance = 0;

FromFrontRightSwitch_ToCenterPile_Reversed::FromFrontRightSwitch_ToCenterPile_Reversed()
{
}
TrajectoryPath* FromFrontRightSwitch_ToCenterPile_Reversed::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromFrontRightSwitch_ToCenterPile_Reversed Class" << std::endl;
	m_instance = new FromFrontRightSwitch_ToCenterPile_Reversed();
	}
	return m_instance;
}
int FromFrontRightSwitch_ToCenterPile_Reversed::GetIndexLength()
{
	return num_index;
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetDT()
{
	return left_wheel[0][5];
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromFrontRightSwitch_ToCenterPile_Reversed::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromFrontRightSwitch_ToCenterPile_Reversed::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromFrontRightSwitch_ToCenterPile_Reversed::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

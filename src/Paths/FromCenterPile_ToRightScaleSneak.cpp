#include "FromCenterPile_ToRightScaleSneak.h"
#include <iostream>

FromCenterPile_ToRightScaleSneak *FromCenterPile_ToRightScaleSneak::m_instance = 0;

FromCenterPile_ToRightScaleSneak::FromCenterPile_ToRightScaleSneak()
{
}
TrajectoryPath* FromCenterPile_ToRightScaleSneak::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromCenterPile_ToRightScaleSneak Class" << std::endl;
	m_instance = new FromCenterPile_ToRightScaleSneak();
	}
	return m_instance;
}
int FromCenterPile_ToRightScaleSneak::GetIndexLength()
{
	return num_index;
}
double FromCenterPile_ToRightScaleSneak::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromCenterPile_ToRightScaleSneak::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromCenterPile_ToRightScaleSneak::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromCenterPile_ToRightScaleSneak::GetDT()
{
	return left_wheel[0][5];
}
double FromCenterPile_ToRightScaleSneak::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromCenterPile_ToRightScaleSneak::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromCenterPile_ToRightScaleSneak::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromCenterPile_ToRightScaleSneak::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromCenterPile_ToRightScaleSneak::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromCenterPile_ToRightScaleSneak::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromCenterPile_ToRightScaleSneak::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromCenterPile_ToRightScaleSneak::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromCenterPile_ToRightScaleSneak::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromCenterPile_ToRightScaleSneak::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromCenterPile_ToRightScaleSneak::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

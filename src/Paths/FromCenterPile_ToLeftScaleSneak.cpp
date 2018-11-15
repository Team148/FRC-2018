#include "FromCenterPile_ToLeftScaleSneak.h"
#include <iostream>

FromCenterPile_ToLeftScaleSneak *FromCenterPile_ToLeftScaleSneak::m_instance = 0;

FromCenterPile_ToLeftScaleSneak::FromCenterPile_ToLeftScaleSneak()
{
}
TrajectoryPath* FromCenterPile_ToLeftScaleSneak::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromCenterPile_ToLeftScaleSneak Class" << std::endl;
	m_instance = new FromCenterPile_ToLeftScaleSneak();
	}
	return m_instance;
}
int FromCenterPile_ToLeftScaleSneak::GetIndexLength()
{
	return num_index;
}
double FromCenterPile_ToLeftScaleSneak::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromCenterPile_ToLeftScaleSneak::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromCenterPile_ToLeftScaleSneak::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromCenterPile_ToLeftScaleSneak::GetDT()
{
	return left_wheel[0][5];
}
double FromCenterPile_ToLeftScaleSneak::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromCenterPile_ToLeftScaleSneak::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromCenterPile_ToLeftScaleSneak::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromCenterPile_ToLeftScaleSneak::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromCenterPile_ToLeftScaleSneak::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromCenterPile_ToLeftScaleSneak::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromCenterPile_ToLeftScaleSneak::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromCenterPile_ToLeftScaleSneak::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromCenterPile_ToLeftScaleSneak::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromCenterPile_ToLeftScaleSneak::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromCenterPile_ToLeftScaleSneak::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

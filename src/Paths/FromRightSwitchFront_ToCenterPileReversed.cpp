#include "FromRightSwitchFront_ToCenterPileReversed.h"
#include <iostream>

FromRightSwitchFront_ToCenterPileReversed *FromRightSwitchFront_ToCenterPileReversed::m_instance = 0;

FromRightSwitchFront_ToCenterPileReversed::FromRightSwitchFront_ToCenterPileReversed()
{
}
TrajectoryPath* FromRightSwitchFront_ToCenterPileReversed::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightSwitchFront_ToCenterPileReversed Class" << std::endl;
	m_instance = new FromRightSwitchFront_ToCenterPileReversed();
	}
	return m_instance;
}
int FromRightSwitchFront_ToCenterPileReversed::GetIndexLength()
{
	return num_index;
}
double FromRightSwitchFront_ToCenterPileReversed::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightSwitchFront_ToCenterPileReversed::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightSwitchFront_ToCenterPileReversed::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightSwitchFront_ToCenterPileReversed::GetDT()
{
	return left_wheel[0][5];
}
double FromRightSwitchFront_ToCenterPileReversed::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightSwitchFront_ToCenterPileReversed::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightSwitchFront_ToCenterPileReversed::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightSwitchFront_ToCenterPileReversed::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightSwitchFront_ToCenterPileReversed::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightSwitchFront_ToCenterPileReversed::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightSwitchFront_ToCenterPileReversed::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightSwitchFront_ToCenterPileReversed::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightSwitchFront_ToCenterPileReversed::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightSwitchFront_ToCenterPileReversed::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightSwitchFront_ToCenterPileReversed::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

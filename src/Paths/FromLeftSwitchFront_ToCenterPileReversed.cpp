#include "FromLeftSwitchFront_ToCenterPileReversed.h"
#include <iostream>

FromLeftSwitchFront_ToCenterPileReversed *FromLeftSwitchFront_ToCenterPileReversed::m_instance = 0;

FromLeftSwitchFront_ToCenterPileReversed::FromLeftSwitchFront_ToCenterPileReversed()
{
}
TrajectoryPath* FromLeftSwitchFront_ToCenterPileReversed::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromLeftSwitchFront_ToCenterPileReversed Class" << std::endl;
	m_instance = new FromLeftSwitchFront_ToCenterPileReversed();
	}
	return m_instance;
}
int FromLeftSwitchFront_ToCenterPileReversed::GetIndexLength()
{
	return num_index;
}
double FromLeftSwitchFront_ToCenterPileReversed::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromLeftSwitchFront_ToCenterPileReversed::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromLeftSwitchFront_ToCenterPileReversed::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromLeftSwitchFront_ToCenterPileReversed::GetDT()
{
	return left_wheel[0][5];
}
double FromLeftSwitchFront_ToCenterPileReversed::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromLeftSwitchFront_ToCenterPileReversed::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromLeftSwitchFront_ToCenterPileReversed::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromLeftSwitchFront_ToCenterPileReversed::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromLeftSwitchFront_ToCenterPileReversed::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromLeftSwitchFront_ToCenterPileReversed::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromLeftSwitchFront_ToCenterPileReversed::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromLeftSwitchFront_ToCenterPileReversed::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromLeftSwitchFront_ToCenterPileReversed::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromLeftSwitchFront_ToCenterPileReversed::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromLeftSwitchFront_ToCenterPileReversed::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

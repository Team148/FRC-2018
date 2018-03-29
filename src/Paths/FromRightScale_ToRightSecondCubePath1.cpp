#include "FromRightScale_ToRightSecondCubePath1.h"
#include <iostream>

FromRightScale_ToRightSecondCubePath1 *FromRightScale_ToRightSecondCubePath1::m_instance = 0;

FromRightScale_ToRightSecondCubePath1::FromRightScale_ToRightSecondCubePath1()
{
}
TrajectoryPath* FromRightScale_ToRightSecondCubePath1::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightScale_ToRightSecondCubePath1 Class" << std::endl;
	m_instance = new FromRightScale_ToRightSecondCubePath1();
	}
	return m_instance;
}
int FromRightScale_ToRightSecondCubePath1::GetIndexLength()
{
	return num_index;
}
double FromRightScale_ToRightSecondCubePath1::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightScale_ToRightSecondCubePath1::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightScale_ToRightSecondCubePath1::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightScale_ToRightSecondCubePath1::GetDT()
{
	return left_wheel[0][5];
}
double FromRightScale_ToRightSecondCubePath1::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightScale_ToRightSecondCubePath1::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightScale_ToRightSecondCubePath1::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightScale_ToRightSecondCubePath1::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightScale_ToRightSecondCubePath1::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightScale_ToRightSecondCubePath1::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightScale_ToRightSecondCubePath1::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightScale_ToRightSecondCubePath1::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightScale_ToRightSecondCubePath1::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

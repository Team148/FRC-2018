#include "FromRightScale_ToRightSecondCubePath2.h"
#include <iostream>

FromRightScale_ToRightSecondCubePath2 *FromRightScale_ToRightSecondCubePath2::m_instance = 0;

FromRightScale_ToRightSecondCubePath2::FromRightScale_ToRightSecondCubePath2()
{
}
TrajectoryPath* FromRightScale_ToRightSecondCubePath2::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightScale_ToRightSecondCubePath2 Class" << std::endl;
	m_instance = new FromRightScale_ToRightSecondCubePath2();
	}
	return m_instance;
}
int FromRightScale_ToRightSecondCubePath2::GetIndexLength()
{
	return num_index;
}
double FromRightScale_ToRightSecondCubePath2::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightScale_ToRightSecondCubePath2::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightScale_ToRightSecondCubePath2::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightScale_ToRightSecondCubePath2::GetDT()
{
	return left_wheel[0][5];
}
double FromRightScale_ToRightSecondCubePath2::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightScale_ToRightSecondCubePath2::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightScale_ToRightSecondCubePath2::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightScale_ToRightSecondCubePath2::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightScale_ToRightSecondCubePath2::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightScale_ToRightSecondCubePath2::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightScale_ToRightSecondCubePath2::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightScale_ToRightSecondCubePath2::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightScale_ToRightSecondCubePath2::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

#include "FromRightFirstCube_ToLeftSwitchPath.h"
#include <iostream>

FromRightFirstCube_ToLeftSwitchPath *FromRightFirstCube_ToLeftSwitchPath::m_instance = 0;

FromRightFirstCube_ToLeftSwitchPath::FromRightFirstCube_ToLeftSwitchPath()
{
}
TrajectoryPath* FromRightFirstCube_ToLeftSwitchPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightFirstCube_ToLeftSwitchPath Class" << std::endl;
	m_instance = new FromRightFirstCube_ToLeftSwitchPath();
	}
	return m_instance;
}
int FromRightFirstCube_ToLeftSwitchPath::GetIndexLength()
{
	return num_index;
}
double FromRightFirstCube_ToLeftSwitchPath::GetInitialHeading()
{
	return left_wheel[0][4];
}
double FromRightFirstCube_ToLeftSwitchPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightFirstCube_ToLeftSwitchPath::GetTimeLength()
{
	return left_wheel[0][6] * (num_index-1);
}
double FromRightFirstCube_ToLeftSwitchPath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightFirstCube_ToLeftSwitchPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightFirstCube_ToLeftSwitchPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightFirstCube_ToLeftSwitchPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightFirstCube_ToLeftSwitchPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightFirstCube_ToLeftSwitchPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightFirstCube_ToLeftSwitchPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightFirstCube_ToLeftSwitchPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightFirstCube_ToLeftSwitchPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightFirstCube_ToLeftSwitchPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

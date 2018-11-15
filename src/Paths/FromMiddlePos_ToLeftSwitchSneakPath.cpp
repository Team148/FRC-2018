#include "FromMiddlePos_ToLeftSwitchSneakPath.h"
#include <iostream>

FromMiddlePos_ToLeftSwitchSneakPath *FromMiddlePos_ToLeftSwitchSneakPath::m_instance = 0;

FromMiddlePos_ToLeftSwitchSneakPath::FromMiddlePos_ToLeftSwitchSneakPath()
{
}
TrajectoryPath* FromMiddlePos_ToLeftSwitchSneakPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromMiddlePos_ToLeftSwitchSneakPath Class" << std::endl;
	m_instance = new FromMiddlePos_ToLeftSwitchSneakPath();
	}
	return m_instance;
}
int FromMiddlePos_ToLeftSwitchSneakPath::GetIndexLength()
{
	return num_index;
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetDT()
{
	return left_wheel[0][5];
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromMiddlePos_ToLeftSwitchSneakPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromMiddlePos_ToLeftSwitchSneakPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromMiddlePos_ToLeftSwitchSneakPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

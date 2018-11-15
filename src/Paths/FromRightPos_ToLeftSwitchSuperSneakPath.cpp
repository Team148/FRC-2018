#include "FromRightPos_ToLeftSwitchSuperSneakPath.h"
#include <iostream>

FromRightPos_ToLeftSwitchSuperSneakPath *FromRightPos_ToLeftSwitchSuperSneakPath::m_instance = 0;

FromRightPos_ToLeftSwitchSuperSneakPath::FromRightPos_ToLeftSwitchSuperSneakPath()
{
}
TrajectoryPath* FromRightPos_ToLeftSwitchSuperSneakPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftSwitchSuperSneakPath Class" << std::endl;
	m_instance = new FromRightPos_ToLeftSwitchSuperSneakPath();
	}
	return m_instance;
}
int FromRightPos_ToLeftSwitchSuperSneakPath::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftSwitchSuperSneakPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftSwitchSuperSneakPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightPos_ToLeftSwitchSuperSneakPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

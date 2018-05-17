#include "FromRightPos_ToLeftScaleSuperSneakPath.h"
#include <iostream>

FromRightPos_ToLeftScaleSuperSneakPath *FromRightPos_ToLeftScaleSuperSneakPath::m_instance = 0;

FromRightPos_ToLeftScaleSuperSneakPath::FromRightPos_ToLeftScaleSuperSneakPath()
{
}
TrajectoryPath* FromRightPos_ToLeftScaleSuperSneakPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating FromRightPos_ToLeftScaleSuperSneakPath Class" << std::endl;
	m_instance = new FromRightPos_ToLeftScaleSuperSneakPath();
	}
	return m_instance;
}
int FromRightPos_ToLeftScaleSuperSneakPath::GetIndexLength()
{
	return num_index;
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetDT()
{
	return left_wheel[0][5];
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* FromRightPos_ToLeftScaleSuperSneakPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FromRightPos_ToLeftScaleSuperSneakPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double FromRightPos_ToLeftScaleSuperSneakPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

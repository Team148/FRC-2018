#include "DriveStraight.h"
#include <iostream>

DriveStraight *DriveStraight::m_instance = 0;

DriveStraight::DriveStraight()
{
}
TrajectoryPath* DriveStraight::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating DriveStraight Class" << std::endl;
	m_instance = new DriveStraight();
	}
	return m_instance;
}
int DriveStraight::GetIndexLength()
{
	return num_index;
}
double DriveStraight::GetStartHeading()
{
	return left_wheel[0][4];
}
double DriveStraight::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double DriveStraight::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double DriveStraight::GetDT()
{
	return left_wheel[0][5];
}
double DriveStraight::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double DriveStraight::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double DriveStraight::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double DriveStraight::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double DriveStraight::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double DriveStraight::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double DriveStraight::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* DriveStraight::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* DriveStraight::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double DriveStraight::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double DriveStraight::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

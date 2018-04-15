#include "GoStraightPath.h"
#include <iostream>

GoStraightPath *GoStraightPath::m_instance = 0;

GoStraightPath::GoStraightPath()
{
}
TrajectoryPath* GoStraightPath::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating GoStraightPath Class" << std::endl;
	m_instance = new GoStraightPath();
	}
	return m_instance;
}
int GoStraightPath::GetIndexLength()
{
	return num_index;
}
double GoStraightPath::GetStartHeading()
{
	return left_wheel[0][4];
}
double GoStraightPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double GoStraightPath::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double GoStraightPath::GetDT()
{
	return left_wheel[0][5];
}
double GoStraightPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double GoStraightPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double GoStraightPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double GoStraightPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double GoStraightPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double GoStraightPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double GoStraightPath::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* GoStraightPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* GoStraightPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double GoStraightPath::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double GoStraightPath::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

#include "FakeStraightPath.h"
#include <iostream>

FakeStraightPath *FakeStraightPath::m_instance = 0;


FakeStraightPath::FakeStraightPath()
{

}
TrajectoryPath* FakeStraightPath::GetInstance()
{
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating FakeStraightPath Class" << std::endl;
		m_instance = new FakeStraightPath();
	}
	return m_instance;
}
int FakeStraightPath::GetIndexLength()
{
	return num_index;
}

double FakeStraightPath::GetInitialHeading()
{
	return left_wheel[0][4];
}

double FakeStraightPath::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}

double FakeStraightPath::GetTimeLength()
{
	return left_wheel[0][6] * num_index;
}

double FakeStraightPath::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double FakeStraightPath::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double FakeStraightPath::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double FakeStraightPath::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double FakeStraightPath::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double FakeStraightPath::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double FakeStraightPath::GetHeading(int index)
{
	return left_wheel[index][4];
}

double* FakeStraightPath::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* FakeStraightPath::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

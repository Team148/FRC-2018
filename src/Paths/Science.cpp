#include "Science.h"
#include <iostream>

Science *Science::m_instance = 0;

Science::Science()
{
}
TrajectoryPath* Science::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating Science Class" << std::endl;
	m_instance = new Science();
	}
	return m_instance;
}
int Science::GetIndexLength()
{
	return num_index;
}
double Science::GetStartHeading()
{
	return left_wheel[0][4];
}
double Science::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double Science::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double Science::GetDT()
{
	return left_wheel[0][5];
}
double Science::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double Science::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double Science::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double Science::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double Science::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double Science::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double Science::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* Science::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* Science::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}

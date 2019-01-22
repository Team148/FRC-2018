#include "ABackupJReversed.h"
#include <iostream>

ABackupJReversed *ABackupJReversed::m_instance = 0;

ABackupJReversed::ABackupJReversed()
{
}
TrajectoryPath* ABackupJReversed::GetInstance()
{
	if (m_instance ==  0) {
	std::cout << "info: GetInstance Creating ABackupJReversed Class" << std::endl;
	m_instance = new ABackupJReversed();
	}
	return m_instance;
}
int ABackupJReversed::GetIndexLength()
{
	return num_index;
}
double ABackupJReversed::GetStartHeading()
{
	return left_wheel[0][4];
}
double ABackupJReversed::GetEndHeading()
{
	return left_wheel[num_index-1][4];
}
double ABackupJReversed::GetTimeLength()
{
	return GetDT() * (num_index-1);
}
double ABackupJReversed::GetDT()
{
	return left_wheel[0][5];
}
double ABackupJReversed::GetLeftPosition(int index)
{
	return left_wheel[index][0];
}
double ABackupJReversed::GetLeftVelocity(int index)
{
	return left_wheel[index][1];
}
double ABackupJReversed::GetLeftAcceleration(int index)
{
	return left_wheel[index][2];
}
double ABackupJReversed::GetRightPosition(int index)
{
	return right_wheel[index][0];
}
double ABackupJReversed::GetRightVelocity(int index)
{
	return right_wheel[index][1];
}
double ABackupJReversed::GetRightAcceleration(int index)
{
	return right_wheel[index][2];
}
double ABackupJReversed::GetHeading(int index)
{
	return left_wheel[index][4];
}
double* ABackupJReversed::GetLeftTrajectoryArray(int index)
{
	return left_wheel[index];
}
double* ABackupJReversed::GetRightTrajectoryArray(int index)
{
	return right_wheel[index];
}
double ABackupJReversed::GetX(int index)
{
	return (left_wheel[index][6] + right_wheel[index][6])*0.5;
}
double ABackupJReversed::GetY(int index)
{
	return (left_wheel[index][7] + right_wheel[index][7])*0.5;
}

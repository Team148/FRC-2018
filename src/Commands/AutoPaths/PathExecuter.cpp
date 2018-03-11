#include "PathExecuter.h"
#include "OI.h"
#include <iostream>


PathExecuter::PathExecuter(TrajectoryPath* trajectory, bool IsReversed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	m_trajectory = trajectory;
	m_IsReversed = IsReversed;
}

// Called just before this Command runs the first time
void PathExecuter::Initialize() {
	Drivetrain::GetInstance()->configPathLoop();
	m_initTime = frc::Timer::GetFPGATimestamp();
	m_isFinished = false;
//	std::cout << "Init" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void PathExecuter::Execute() {

	double timeEnlapsed = frc::Timer::GetFPGATimestamp() - m_initTime;

	int time_index = (int)(timeEnlapsed / m_pathDT);

	std::cout << time_index << std::endl;

	if(!(time_index < m_trajectory->GetIndexLength())){
		m_isFinished = true;
		std::cout << "done" << std::endl;
		return;
	}
//	time_index-=1;

//	double* left_wheel = m_trajectory->GetLeftTrajectoryArray(time_index);
//	double* right_wheel = m_trajectory->GetRightTrajectoryArray(time_index);

	double l_pos = m_trajectory->GetLeftPosition(time_index);
	double l_vel = m_trajectory->GetLeftVelocity(time_index);
	double l_acc = m_trajectory->GetLeftAcceleration(time_index);

	double r_pos = m_trajectory->GetRightPosition(time_index);
	double r_vel = m_trajectory->GetRightVelocity(time_index);
	double r_acc = m_trajectory->GetRightAcceleration(time_index);

	double heading = m_trajectory->GetHeading(time_index);

	Drivetrain::GetInstance()->SetPathDriveVelocity(l_pos, l_vel, l_acc, r_pos, r_vel, r_acc, heading, m_IsReversed);

}

// Make this return true when this Command no longer needs to run execute()
bool PathExecuter::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void PathExecuter::End() {
//	Drivetrain::GetInstance()->configOpenLoop();
//	Drivetrain::GetInstance()->Arcade(0,0);
	std::cout << "PathExecuterPath Done" << std::endl;

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PathExecuter::Interrupted() {

}

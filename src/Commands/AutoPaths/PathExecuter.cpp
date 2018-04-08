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
	Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::PATH_CONFIG);
	m_initTime = frc::Timer::GetFPGATimestamp();
	m_isFinished = false;
//	std::cout << "Init" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void PathExecuter::Execute() {

	double timeEnlapsed = frc::Timer::GetFPGATimestamp() - m_initTime;

	int time_index = (int)(timeEnlapsed / m_pathDT);

	if(Drivetrain::GetInstance()->GetLineSenseF_L())
		std::cout << "F_L Triggered at " << time_index << std::endl;

	if(Drivetrain::GetInstance()->GetLineSenseF_R())
		std::cout << "F_R Triggered at " << time_index << std::endl;
//
//
//	if(Drivetrain::GetInstance()->GetLineSenseR_L())
//		std::cout << "R_L Triggered"<<std::endl;;
//
//
//	if(Drivetrain::GetInstance()->GetLineSenseR_R())
//		std::cout << "R_R Triggered"<<std::endl;;


//	std::cout << time_index << std::endl;

	if(!(time_index < m_trajectory->GetIndexLength())){
		m_isFinished = true;
	//	std::cout << m_trajectory->GetIndexLength() << std::endl;
		std::cout << "done" << std::endl;
		return;
	}
//	time_index-=1;

//	double* left_wheel = m_trajectory->GetLeftTrajectoryArray(time_index);
//	double* right_wheel = m_trajectory->GetRightTrajectoryArray(time_index);
	Drivetrain::GetInstance()->accumRobotPosition();

	double l_pos = m_trajectory->GetLeftPosition(time_index);
	double l_vel = m_trajectory->GetLeftVelocity(time_index);
	double l_acc = m_trajectory->GetLeftAcceleration(time_index);

	double r_pos = m_trajectory->GetRightPosition(time_index);
	double r_vel = m_trajectory->GetRightVelocity(time_index);
	double r_acc = m_trajectory->GetRightAcceleration(time_index);

	double heading = m_trajectory->GetHeading(time_index);

	frc::SmartDashboard::PutNumber("TimeIndex", time_index);
	frc::SmartDashboard::PutNumber("TrajectoryX", m_trajectory->GetX(time_index));
	frc::SmartDashboard::PutNumber("TrajectoryY", m_trajectory->GetY(time_index));
	frc::SmartDashboard::PutNumber("RobotX", Drivetrain::GetInstance()->getRobotPosition_x());
	frc::SmartDashboard::PutNumber("RobotY", Drivetrain::GetInstance()->getRobotPosition_y());

//	Drivetrain::GetInstance()->SetPathDriveVelocity(l_pos, l_vel, l_acc, r_pos, r_vel, r_acc, heading, m_IsReversed);
	Drivetrain::GetInstance()->SetPathDriveKinematics(l_pos, l_vel, l_acc, r_pos, r_vel, r_acc, heading, m_trajectory->GetDT(), m_IsReversed);

}

// Make this return true when this Command no longer needs to run execute()
bool PathExecuter::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void PathExecuter::End() {
	Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::OPEN_LOOP);
	Drivetrain::GetInstance()->Arcade(0,0);
	std::cout << "PathExecuterPath Done" << std::endl;

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PathExecuter::Interrupted() {

}

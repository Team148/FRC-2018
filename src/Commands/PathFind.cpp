#include "PathFind.h"
#include "../Paths/GoStraightTurnRight.h"
#include "Timer.h"
#include "iostream"
#include <./SmartDashboard/SendableChooser.h>
#include <./SmartDashboard/SmartDashboard.h>


PathFind::PathFind() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	//PathPlanner = new Path();

}

// Called just before this Command runs the first time
void PathFind::Initialize() {
	index = 0;
	m_lastTime = 0;
	m_startTime = frc::Timer::GetFPGATimestamp();

	Drivetrain::GetInstance()->configClosedLoop();




	double startTime;
	double finishTime;
	double totalTime;

	//startTime = frc::Timer::GetFPGATimestamp();
	//std::cout << "Creating Path Started" << std::endl;
	//std::cout << startTime  << std::endl;



	//finishTime = frc::Timer::GetFPGATimestamp();
	//totalTime = finishTime - startTime;

	//std::cout << "Creating Path Finished" << std::endl;
	//std::cout << finishTime << std::endl;



	//std::cout << "Total Time" << std::endl;
	//std::cout << totalTime << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void PathFind::Execute() {
    m_tempDrivetrain = Drivetrain::GetInstance();
	////double timeEnlapsed = frc::Timer::GetFPGATimestamp() - m_lastTime;
	//int index = (int)(timeEnlapsed);

    //std::cout << time_index;
//	std::cout << frc::Timer::GetFPGATimestamp() <<" ; "  << PathPlanner->GetLeftSegment(m_lastTime).x << " ; " << PathPlanner->GetRightSegment(m_lastTime).y << " ; "  << PathPlanner->GetLeftSegment(m_lastTime).velocity  << " ; " << PathPlanner->GetRightSegment(m_lastTime).velocity << " ; " << std::endl;
	double timeEnlapsed = frc::Timer::GetFPGATimestamp() - m_startTime;
    int timeIndex = (int)(timeEnlapsed/ 0.01);

	if(timeIndex > num_index){
		m_tempDrivetrain->SetLeftRight(0,0);
		m_finished = true;
		return;
	}
	double m_leftVel  = left_wheel[timeIndex][1];
	double m_rightVel = right_wheel[timeIndex][1];
	std::cout << "Time: " << timeEnlapsed << " Index: " << timeIndex << " Left Velocity: " << m_leftVel << " Right Velocity: " << m_rightVel << std::endl;
	//m_tempDrivetrain->SetLeftRight(unit_master.GetTicksPer100ms(m_leftVel), unit_master.GetTicksPer100ms(m_rightVel));
	m_tempDrivetrain->SetDriveVelocity(unit_master.GetTicksPer100ms(m_leftVel), unit_master.GetTicksPer100ms(m_rightVel));

//	std::cout << "DriveTicksPer100ms: " << unit_master.GetTicksPer100ms(PathPlanner->GetLeftValue(m_lastTime)) << std::endl;
//	m_tempDrivetrain->Tank(unit_master.GetTicksPer100ms(PathPlanner->GetLeftValue(m_lastTime)), unit_master.GetTicksPer100ms(PathPlanner->GetRightValue(m_lastTime)));
	//frc::SmartDashboard::PutNumber("RightVelocityBeforeConv", PathPlanner->GetRightValue(m_lastTime));
//	m_tempDrivetrain->SetDriveVelocity(unit_master.GetTicksPer100ms(PathPlanner->GetLeftValue(m_lastTime)),unit_master.GetTicksPer100ms(PathPlanner->GetRightValue(m_lastTime)));

//	m_tempDrivetrain->SetDriveVelocity(unit_master.GetTicksPer100ms(PathPlanner->LeftENCCorrectionValue(m_lastTime)),unit_master.GetTicksPer100ms(PathPlanner->RightENCCorrectionValue(m_lastTime)));

	//m_tempDrivetrain->SetLeft(PathPlanner->GetLeftValue(m_lastTime));
    //frc::SmartDashboard::PutNumber("X Position",PathPlanner->GetLeftSegment(index).x);
    //frc::SmartDashboard::PutNumber("Y Position",PathPlanner->GetLeftSegment(index).y);
	m_lastTime++;


}

// Make this return true when this Command no longer needs to run execute()
bool PathFind::IsFinished() {

	return m_finished;
}

// Called once after isFinished returns true
void PathFind::End() {
	//PathPlanner->End();
	index = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PathFind::Interrupted() {
//	PathPlanner->End();
	index = 0;
}

#include "PathFind.h"
#include "Timer.h"
#include "iostream"
#include <./SmartDashboard/SendableChooser.h>
#include <./SmartDashboard/SmartDashboard.h>



PathFind::PathFind() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	PathPlanner = new Path();

}

// Called just before this Command runs the first time
void PathFind::Initialize() {
	index = 0;
	m_lastTime = 0;





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
	std::cout << frc::Timer::GetFPGATimestamp() <<" ; "  << PathPlanner->GetLeftSegment(m_lastTime).x << " ; " << PathPlanner->GetRightSegment(m_lastTime).y << " ; "  << PathPlanner->GetLeftSegment(m_lastTime).velocity  << " ; " << PathPlanner->GetRightSegment(m_lastTime).velocity << " ; " << std::endl;

	m_tempDrivetrain->Tank(PathPlanner->GetLeftValue(m_lastTime),PathPlanner->GetRightValue(m_lastTime));
	//m_tempDrivetrain->SetLeft(PathPlanner->GetLeftValue(m_lastTime));
    //frc::SmartDashboard::PutNumber("X Position",PathPlanner->GetLeftSegment(index).x);
    //frc::SmartDashboard::PutNumber("Y Position",PathPlanner->GetLeftSegment(index).y);
	m_lastTime++;

}

// Make this return true when this Command no longer needs to run execute()
bool PathFind::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PathFind::End() {
	PathPlanner->End();
	index = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PathFind::Interrupted() {
	PathPlanner->End();
	index = 0;
}

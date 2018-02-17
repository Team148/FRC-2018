#include "PathFind.h"
//#include "../../Paths/GoStraightTurnRight.h"
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

}

// Called repeatedly when this Command is scheduled to run
void PathFind::Execute() {
    m_tempDrivetrain = Drivetrain::GetInstance();

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
	m_tempDrivetrain->SetDriveVelocity(unit_master.GetTicksPer100ms(m_leftVel), unit_master.GetTicksPer100ms(m_rightVel));


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

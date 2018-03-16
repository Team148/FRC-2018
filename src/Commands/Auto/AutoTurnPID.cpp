#include <Commands/Auto/AutoTurnPID.h>
#include <iostream>

AutoTurnPID::AutoTurnPID(float degrees) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Drivetrain::GetInstance());
	m_setpoint = degrees;
	//m_controller = new PIDController();

}

// Called just before this Command runs the first time
void AutoTurnPID::Initialize() {
	//reset isFinished
	m_isFinished = 0;

	//Set Drivetrain to OpenLoop
	Drivetrain::GetInstance()->configDrivetrain(tDriveConfigs::OPEN_LOOP);

	m_initalAngle = Drivetrain::GetInstance()->getGyroYaw();
	m_setpoint += m_initalAngle;
}

// Called repeatedly when this Command is scheduled to run
void AutoTurnPID::Execute() {
	//read current angle
	float current_angle = Drivetrain::GetInstance()->getGyroYaw();

	//calculate output
	float curr_err = m_setpoint - current_angle;
	m_i_err+=curr_err;
	float d_err = curr_err - prev_err;
	float output = m_Kp * curr_err + m_Ki*m_i_err;


    //frc::SmartDashboard::PutData( Drivetrain::GetInstance()->updateGyroYaw());

	//SetLeft and SetRight
	Drivetrain::GetInstance()->Tank(output, output);
	std::cout << "yaw " << Drivetrain::GetInstance()->getGyroYaw() << std::endl;
	std::cout << "output " << output << std::endl;

	prev_err = curr_err;

	//check if we're finished
	if(abs(curr_err)<=DRIVE_TURN_TOLERANCE)
		m_isFinished=true;
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurnPID::IsFinished() {
	return m_isFinished;
}

// Called once after isFinished returns true
void AutoTurnPID::End() {
	Drivetrain::GetInstance()->SetDriveVelocity(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurnPID::Interrupted() {
	End();
}

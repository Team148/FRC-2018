#include "ArcadeDriveTurn.h"

ArcadeDriveTurn::ArcadeDriveTurn(float angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drivetrain::GetInstance());
	m_input_angle = angle;
}

// Called just before this Command runs the first time
void ArcadeDriveTurn::Initialize() {
	m_isFinished=0;
	tolerance_delay=0;
	m_integral_err=0;
	SetTimeout(1.5);
	//Drivetrain::GetInstance()->ResetGyro();
	m_init_angle = 0;
	m_final_angle = 0;

	m_init_angle = Drivetrain::GetInstance()->getGyroYaw();
	m_final_angle = m_init_angle + m_input_angle;
	//std::cout <<"info: final_angle: " << m_final_angle << std::endl;

	Drivetrain::GetInstance()->configOpenLoop();
	Drivetrain::GetInstance()->SetBrakeMode(1);
}

// Called repeatedly when this Command is scheduled to run
void ArcadeDriveTurn::Execute() {
	float cur_angle = Drivetrain::GetInstance()->getGyroYaw();

	float cur_err = m_final_angle - cur_angle;

	float stick_input = cur_err*ARCADE_TURN_P + ARCADE_TURN_I*m_integral_err;

	//std::cout <<"info: cur_err " << cur_err << "FINAL ANGLE " << m_final_angle << std::endl;

	if(abs(cur_err) <= 4.5)
	{
		m_integral_err += cur_err*.02;
	}
	if(abs(cur_err)<=ARCADE_TURN_TOLERANCE) {

		tolerance_delay++;
		if(tolerance_delay > 7)
			m_isFinished = 1;
	}
	else
		tolerance_delay = 0;

	//bound input
	if(stick_input > .65)
		stick_input = .65;
	if(stick_input < -.65)
		stick_input = -.65;


	Drivetrain::GetInstance()->Arcade(0,stick_input);

	SmartDashboard::PutNumber("Final Angle: ", m_final_angle);
	SmartDashboard::PutNumber("init Angle: ", m_init_angle);
	SmartDashboard::PutNumber("input Angle: ", m_input_angle);
	SmartDashboard::PutNumber("Integral: ", m_integral_err);
	SmartDashboard::PutNumber("current error: ", cur_err);


}

// Make this return true when this Command no longer needs to run execute()
bool ArcadeDriveTurn::IsFinished() {
	return m_isFinished || 	IsTimedOut();
}

// Called once after isFinished returns true
void ArcadeDriveTurn::End() {
	Drivetrain::GetInstance()->Arcade(0,0);
	//std::cout <<"info: final angle reached: " << Drivetrain::GetInstance()->getGyroYaw() << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArcadeDriveTurn::Interrupted() {
	End();
}

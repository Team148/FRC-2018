#include "OI.h"
#include <WPILib.h>
#include <iostream>

#include <Commands/RunIntake.h>
#include <Commands/RunClimber.h>
#include <Commands/GrabPartner.h>
#include <Commands/SetElevator.h>

OI *OI::m_instance = 0;


OI::OI() {
	// Process operator interface input here.
	drvStick = new Joystick(0);
	m_drvButton1 = new JoystickButton(drvStick, 1);
	m_drvButton2 = new JoystickButton(drvStick, 2);
	m_drvButton3 = new JoystickButton(drvStick, 3);
	m_drvButton4 = new JoystickButton(drvStick, 4);
	m_drvButton5 = new JoystickButton(drvStick, 5);
	m_drvButton6 = new JoystickButton(drvStick, 6);
	m_drvButton7 = new JoystickButton(drvStick, 7);
	m_drvButton8 = new JoystickButton(drvStick, 8);
	m_drvButton9 = new JoystickButton(drvStick, 9);
	m_drvButton10 = new JoystickButton(drvStick, 10);


	opStick = new Joystick(1);
	m_opButton1 = new JoystickButton(opStick, 1);
	m_opButton2 = new JoystickButton(opStick, 2);
	m_opButton3 = new JoystickButton(opStick, 3);
	m_opButton4 = new JoystickButton(opStick, 4);
	m_opButton5 = new JoystickButton(opStick, 5);
	m_opButton6 = new JoystickButton(opStick, 6);
	m_opButton7 = new JoystickButton(opStick, 7);
	m_opButton8 = new JoystickButton(opStick, 8);
	m_opButton9 = new JoystickButton(opStick, 9);
	m_opButton10 = new JoystickButton(opStick, 10);

	//DriveJoystick Controls
	//100% Outtake
	m_drvButton5->WhenPressed(new RunIntake(OUTTAKE_FULL_PERCENT));
	m_drvButton5->WhenReleased(new RunIntake(0.0));

//	//Climber
//	if((drvStick->GetRawButtonPressed(7)) && (drvStick->GetRawButtonPressed(8))) {
//		RunClimber(true);
//	}

	//OperatorJoystick Controls

	//100% Outtake
	m_opButton6->WhenPressed(new RunIntake(OUTTAKE_FULL_PERCENT));
	m_opButton6->WhenReleased(new RunIntake(0.0));

	//100% Outtake
	m_opButton5->WhenPressed(new RunIntake(INTAKE_PERCENT));
	m_opButton5->WhenReleased(new RunIntake(0.0));

	//Elevator
	m_opButton1->WhenPressed(new SetElevator(true, ELEVATOR_ZERO));

	m_opButton2->WhenPressed(new SetElevator(true, ELEVATOR_SWITCH));

	m_opButton3->WhenPressed(new SetElevator(true, ELEVATOR_SCALE_LOW));

	m_opButton4->WhenPressed(new SetElevator(true, ELEVATOR_SCALE_HIGH));

//	if(opStick->GetPOV(0) == true) {
//		SetElevator(true, ELEVATOR_DOUBLE_STACK);
//	}
//
//	if(opStick->GetPOV(180 == true)) {
//		SetElevator(true, ELEVATOR_HANG);
//	}

//	//RobotWrangler
//	if((opStick->GetRawButtonPressed(7)) && (opStick->GetRawButtonPressed(8))) {
//		GrabPartner(true);
//	}
}

OI* OI::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating OperatorInterface Class" << std::endl;
		m_instance = new OI();
	}
	return m_instance;
}

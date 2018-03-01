#include "OI.h"
#include <WPILib.h>
#include <iostream>

#include <Commands/RunIntake.h>
#include <Commands/RunClimber.h>
#include <Commands/RunDrivetrain.h>
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


	//DSI Controls
		dsiBrickA = new Joystick(2);
		dsiBrickB = new Joystick(3);

		m_brickAselect1 = new JoystickButton(dsiBrickA, 1);
		m_brickAselect2 = new JoystickButton(dsiBrickA, 2);
		m_brickAselect3 = new JoystickButton(dsiBrickA, 3);
		m_brickAselect4 = new JoystickButton(dsiBrickA, 4);
		m_brickAselect5 = new JoystickButton(dsiBrickA, 5);
		m_brickAselect6 = new JoystickButton(dsiBrickA, 6);
		m_brickAselect7 = new JoystickButton(dsiBrickA, 7);
		m_brickAselect8 = new JoystickButton(dsiBrickA, 8);

		m_brickBselect1 = new JoystickButton(dsiBrickB, 1);
		m_brickBselect2 = new JoystickButton(dsiBrickB, 2);
		m_brickBselect3 = new JoystickButton(dsiBrickB, 3);
		m_brickBselect4 = new JoystickButton(dsiBrickB, 4);
		m_brickBselect5 = new JoystickButton(dsiBrickB, 5);
		m_brickBselect6 = new JoystickButton(dsiBrickB, 6);
		m_brickBselect7 = new JoystickButton(dsiBrickB, 7);
		m_brickBselect8 = new JoystickButton(dsiBrickB, 8);

		m_dsiSw1 = new JoystickButton(dsiBrickB, 9);
		m_dsiSw2 = new JoystickButton(dsiBrickB, 10);
		m_dsiSw3 = new JoystickButton(dsiBrickA, 9);
		m_dsiSw4 = new JoystickButton(dsiBrickA, 10);
		m_dsiSw5 = new JoystickButton(dsiBrickA, 11);






//	//DriveJoystick Controls
	m_drvButton1->WhenPressed(new GrabPartner(WRANGLER_SLOW_PERCENT));
	m_drvButton1->WhenReleased(new GrabPartner(0.0));

	m_drvButton2->WhenPressed(new GrabPartner(WRANGLER_FAST_PERCENT));
	m_drvButton2->WhenReleased(new GrabPartner(0.0));
////	//100% Outtake
//	m_drvButton5->WhenPressed(new RunIntake(OUTTAKE_FULL_PERCENT));
//	m_drvButton5->WhenReleased(new RunIntake(0.0));
////
////	//OperatorJoystick Controls
//	m_opButton6->WhenPressed(new RunIntake(OUTTAKE_PERCENT));
//	m_opButton6->WhenReleased(new RunIntake(0.0));
////
////	//Intake
//	m_opButton5->WhenPressed(new RunIntake(INTAKE_PERCENT));
//	m_opButton5->WhenReleased(new RunIntake(0.0));

	//Elevator
	m_opButton1->WhenPressed(new SetElevator(true, ELEVATOR_ZERO));

	m_opButton2->WhenPressed(new SetElevator(true, ELEVATOR_SWITCH));

	m_opButton3->WhenPressed(new SetElevator(true, ELEVATOR_SCALE_LOW));

	m_opButton4->WhenPressed(new SetElevator(true, ELEVATOR_SCALE_HIGH));

//	//Operator Controller POV commands
//	if(opStick->GetPOV(0)) {
//		new SetElevator(true, ELEVATOR_DOUBLE_STACK);
//	}
//
//	if(opStick->GetPOV(180)) {
//		new SetElevator(true, ELEVATOR_HANG);
//	}

//	//TWO BUTTON CLIMBER AND ROBOTWRANGLER FAILSAFES
//	//Driver call climber command
//	if (drvStick->GetRawButton(7) && drvStick->GetRawButton(8)) {
//		new RunClimber(true);
//	}
//	else
//		new RunClimber(false);
//
//	//Operator call grabpartner command
//	if (opStick->GetRawButton(7) && opStick->GetRawButton(8)) {
//		new GrabPartner(true);
//	}
//	else
//		new GrabPartner(false);
}

OI* OI::GetInstance() {
	if (m_instance ==  0) {
		std::cout << "info: GetInstance Creating OperatorInterface Class" << std::endl;
		m_instance = new OI();
	}
	return m_instance;
}

int OI::GetSelectorA() {
	if(m_brickAselect1->Get())
		return 0;
	if(m_brickAselect2->Get())
		return 1;
	if(m_brickAselect3->Get())
		return 2;
	if(m_brickAselect4->Get())
		return 3;
	if(m_brickAselect5->Get())
		return 4;
	if(m_brickAselect6->Get())
		return 5;
	if(m_brickAselect7->Get())
		return 6;
	if(m_brickAselect8->Get())
		return 7;

	return 0;
}


int OI::GetSelectorB() {
	if(m_brickBselect1->Get())
		return 1;
	if(m_brickBselect2->Get())
		return 2;
	if(m_brickBselect3->Get())
		return 3;
	if(m_brickBselect4->Get())
		return 4;
	if(m_brickBselect5->Get())
		return 5;
	if(m_brickBselect6->Get())
		return 6;
	if(m_brickBselect7->Get())
		return 7;
	if(m_brickBselect8->Get())
		return 8;

	return 0;
}


int OI::GetDSSwitches() {
	int switches = 0;
	int sw1 = m_dsiSw1->Get();
	switches = sw1;
	int sw2 = m_dsiSw2->Get();
	switches = switches + (sw2 << 1);
	int sw3 = m_dsiSw3->Get();
	switches = switches + (sw3 << 2);
	int sw4 = m_dsiSw4->Get();
	switches = switches + (sw4 << 3);
	int sw5 = m_dsiSw5->Get();
	switches = switches + (sw5 << 4);

	return switches;
}


bool OI::GetSw1() {
	return m_dsiSw1->Get();
}


bool OI::GetSw2() {
	return m_dsiSw2->Get();
}


bool OI::GetSw3() {
	return m_dsiSw3->Get();
}


bool OI::GetSw4() {
	return m_dsiSw4->Get();
}


bool OI::GetSw5() {
	return m_dsiSw5->Get();
}

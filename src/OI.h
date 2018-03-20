#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Constants.h"


class OI {
public:
	frc::Joystick* drvStick;
	frc::Joystick* opStick;
	Joystick* dsiBrickA;
	Joystick* dsiBrickB;
	Joystick* mspJoystick;

	int GetSelectorA();
	int GetSelectorB();
	int GetDSSwitches();

	bool GetSw1();
	bool GetSw2();
	bool GetSw3();
	bool GetSw4();
	bool GetSw5();

	static OI* GetInstance();
private:
	OI();
	static OI *m_instance;

	JoystickButton* m_drvButton1;
	JoystickButton* m_drvButton2;
	JoystickButton* m_drvButton3;
	JoystickButton* m_drvButton4;
	JoystickButton* m_drvButton5;
	JoystickButton* m_drvButton6;
	JoystickButton* m_drvButton7;
	JoystickButton* m_drvButton8;
	JoystickButton* m_drvButton9;
	JoystickButton* m_drvButton10;

	JoystickButton* m_opButton1;
	JoystickButton* m_opButton2;
	JoystickButton* m_opButton3;
	JoystickButton* m_opButton4;
	JoystickButton* m_opButton5;
	JoystickButton* m_opButton6;
	JoystickButton* m_opButton7;
	JoystickButton* m_opButton8;
	JoystickButton* m_opButton9;
	JoystickButton* m_opButton10;

//	JoystickButton* m_brickAselect1;
//	JoystickButton* m_brickAselect2;
//	JoystickButton* m_brickAselect3;
//	JoystickButton* m_brickAselect4;
//	JoystickButton* m_brickAselect5;
//	JoystickButton* m_brickAselect6;
//	JoystickButton* m_brickAselect7;
//	JoystickButton* m_brickAselect8;
//
//	JoystickButton* m_brickBselect1;
//	JoystickButton* m_brickBselect2;
//	JoystickButton* m_brickBselect3;
//	JoystickButton* m_brickBselect4;
//	JoystickButton* m_brickBselect5;
//	JoystickButton* m_brickBselect6;
//	JoystickButton* m_brickBselect7;
//	JoystickButton* m_brickBselect8;
//	JoystickButton* m_dsiSw1;
//	JoystickButton* m_dsiSw2;
//	JoystickButton* m_dsiSw3;
//	JoystickButton* m_dsiSw4;
//	JoystickButton* m_dsiSw5;
	JoystickButton* msp_s1;
	JoystickButton* msp_s2;
	JoystickButton* msp_s3;
	JoystickButton* msp_s4;
	JoystickButton* msp_s5;

};

#endif

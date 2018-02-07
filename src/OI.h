#include "WPILib.h"

class OI {
public:
	frc::Joystick* drvStick;
	frc::Joystick* opStick;

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

	JoystickButton* m_opButton1;
	JoystickButton* m_opButton2;
	JoystickButton* m_opButton3;
	JoystickButton* m_opButton4;
	JoystickButton* m_opButton5;
	JoystickButton* m_opButton6;
	JoystickButton* m_opButton7;

};

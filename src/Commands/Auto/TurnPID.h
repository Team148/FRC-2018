#ifndef TurnPID_H
#define TurnPID_H

#include "../../CommandBase.h"
#include "WPIlib.h"
#include "constants.h"

class TurnPID : public CommandBase {
public:
	TurnPID(float degrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float m_setpoint;
	bool m_isFinished = 0;
	float m_Kp = DRIVE_TURN_P;
	float m_Ki = DRIVE_TURN_I;
	float m_initalAngle = 0;
	float m_i_err=0;
	float prev_err=0;
};

#endif  // TurnPID_H

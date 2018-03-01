#ifndef ArcadeDriveTurn_H
#define ArcadeDriveTurn_H

#include "CommandBase.h"
#include "math.h"

class ArcadeDriveTurn : public CommandBase {
public:
	ArcadeDriveTurn(float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_isFinished = 0;
	float m_init_angle=0;
	float m_input_angle=0;
	float m_final_angle=0;
	bool m_left_turn = 0;
	float m_integral_err=0;
	int tolerance_delay=0;
};

#endif  // ArcadeDriveTurn_H

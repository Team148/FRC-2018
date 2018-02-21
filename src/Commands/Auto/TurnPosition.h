#ifndef TurnPosition_H
#define TurnPosition_H

#include "Commands/Command.h"
#include "../../Util/UnitMaster.h"

class TurnPosition : public Command {
public:
	TurnPosition(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	UnitMaster unit_master;
	double m_given_angle = 0.0;
	double m_end_angle = 0.0;
	double m_cur_angle = 0.0;
	double m_angle_err = 0.0;
	int m_l_cur_pos = 0.0;
	int m_l_init_pos = 0.0;
	int m_r_cur_pos = 0.0;
	int m_r_init_pos = 0.0;

	int m_l_pos_err = 0.0;
	int m_r_pos_err = 0.0;
	bool m_isFinished = false;

};

#endif  // TurnPosition_H

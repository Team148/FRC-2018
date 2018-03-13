#ifndef TurnPosition_H
#define TurnPosition_H

#include "Commands/Command.h"
#include "../../Util/UnitMaster.h"

class TurnPosition : public Command {
public:
	TurnPosition(double heading);
	TurnPosition(double heading, bool isClockwise, double timeOut);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	UnitMaster unit_master;
	bool m_is_clockwise = false;
	double m_time_out = 0.0;
	double m_heading = 0.0;
	double m_robot_heading = 0.0;
	double m_cur_heading = 0.0;
	double m_heading_err = 0.0;
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

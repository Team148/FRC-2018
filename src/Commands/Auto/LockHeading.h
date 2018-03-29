#ifndef LockHeading_H
#define LockHeading_H

#include <Commands/Command.h>
#include "../../Util/UnitMaster.h"


class LockHeading : public Command {
public:
	LockHeading(double heading);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	UnitMaster unit_master;

	double m_heading = 0.0;
	double m_robot_heading = 0.0;
	double m_cur_heading = 0.0;
	double m_heading_err = 0.0;
	double m_velocity_set = 0.0;

	double m_max_velocity = 120.0;
	double m_max_allowed_error = 120.0;

};

#endif

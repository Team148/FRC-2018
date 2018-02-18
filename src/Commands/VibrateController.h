#ifndef VibrateController_H
#define VibrateController_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Command.h"


class VibrateController : public frc::Command {
public:
	VibrateController(bool x);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_x = 0;
	bool m_finished = 0;
};

#endif  // VibrateController_H

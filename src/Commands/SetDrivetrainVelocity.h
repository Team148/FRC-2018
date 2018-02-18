#ifndef SetDrivetrainVelocity_H
#define SetDrivetrainVelocity_H

#include "Subsystems/Drivetrain.h"
#include "Commands/Command.h"
#include "Util/UnitMaster.h"

class SetDrivetrainVelocity : public frc::InstantCommand {
public:
	SetDrivetrainVelocity(double velocity);
	void Initialize();

private:
	UnitMaster unit_master;
	double m_velocity = 0.0;
	bool m_isFinished = 0.0;
	bool initConfig = false;
};

#endif  // TankDriveJoystick_H

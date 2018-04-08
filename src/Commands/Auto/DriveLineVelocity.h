  #ifndef DriveLineVelocity_H
#define DriveLineVelocity_H
#include "Util/UnitMaster.h"
#include <queue>
#include <math.h>
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/Drivetrain.h"
#include "Constants.h"

using namespace std;
class DriveLineVelocity : public CommandBase {
public:
	DriveLineVelocity(double cruise_velocity, double final_velocity, double heading, double positionTimeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float m_distanceTicks = 0.0;
	float m_rightStartPos = 0.0;
	float m_leftStartPos = 0.0;

	float m_cruiseVelocity;
	float m_finalVelocity;
	bool m_isFinished = 0;
	float m_initangle = 0.0;
	double m_heading  = 0;
	double m_positionTimeout = 0.0;

	//drivetrain constraints

	float m_maxdrivevelocity = 150; //Inches per se


};

#endif  // Drive_H

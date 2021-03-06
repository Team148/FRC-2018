  #ifndef AutoDrive_H
#define AutoDrive_H
#include "Util/UnitMaster.h"
#include <queue>
#include <math.h>
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/Drivetrain.h"
#include "Constants.h"

using namespace std;
class AutoDrive : public CommandBase {
public:
	AutoDrive(double inches, double cruise_velocity, double final_velocity);
	AutoDrive(double inches, double cruise_velocity, double final_velocity, double accelRate, double heading);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	UnitMaster unit_master_conv;
	float m_distanceTicks = 0.0;
	float m_rightStartPos = 0.0;
	float m_leftStartPos = 0.0;

	float m_travelDistance;
	float m_cruiseVelocity;
	float m_finalVelocity;
	bool m_isFinished = 0;
	float m_initangle = 0.0;
	bool m_isReverse = false;
	double m_heading  = 0;
	double m_accelRate = 0.0;

	//drivetrain constraints
//	float m_maxAccelRate = 100; 		//Inches per sec^2
//	float m_maxDecelRate= 90;		//Inches per sec^2
	float m_maxdrivevelocity = 150; //Inches per se
	float m_dt = AUTO_PERIODIC_DT;

	struct Trajectory_points {
		double t;			//time
		double v_left;		//left velocity
		double v_right;		//right velocity
		double d_left;		//left distance
		double d_right;		//right distance
		double a_left;		//left acceleration
		double a_right;		//right acceleration
	};

	queue <Trajectory_points> m_trajectory;
};

#endif  // AutoDrive_H

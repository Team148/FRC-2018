#ifndef Drive_H
#define Drive_H

#include <queue>
#include "math.h"
#include "Commands/Command.h"
#include "Subsystems/Drivetrain.h"
#include "Constants.h"

using namespace std;
class Drive : public Command {
public:
	Drive(double inches, double cruise_velocity, double final_velocity=0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float m_travelDistance;
	float m_cruiseVelocity;
	float m_finalVelocity;
	bool m_isFinished=0;
	float m_initangle = 0;
	bool m_isReverse = false;

	//drivetrain constraints
	float m_maxAccelRate = 100; 		//Inches per sec^2
	float m_maxDecelRate= 90;		//Inches per sec^2
	float m_maxdrivevelocity = 150; //Inches per se
	float m_dt = 0.02;				//time step set to 20ms(50Hz).

	struct Trajectory_points {
		double t;			//time
		double v_left;		//left velocity
		double v_right;		//right velocity
		double d_left;		//left distance
		double d_right;		//right distance
	};

	queue <Trajectory_points> m_trajectory;
};

#endif  // Drive_H

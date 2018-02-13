#ifndef TurnTMP_H
#define TurnTMP_H

#include "../../CommandBase.h"
#include "math.h"
#include "Constants.h"
#include <queue>

using namespace std;
class TurnTMP : public CommandBase {
public:
	TurnTMP(float degrees, float velocity);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float m_deg_input;
	float m_rad_distance=0;
	float m_initangle=0;
	float m_finalangle=0;
	float m_cruiseVelocity=0;

	//drivetrain constraints
	float m_maxAccelRate = 80; 		//Inches per sec^2
	float m_maxdrivevelocity = 100; //Inches per sec
	float m_dt = 0.02;				//time step set to 20ms(50Hz).

	queue <float> m_output;
	queue <float> m_dist;
	bool m_isFinished=false;
	bool m_isLeft=false;
};

#endif  // TurnTMP_H

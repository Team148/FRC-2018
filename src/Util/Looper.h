/*
 * Looper.h
 *
 */

#ifndef SRC_UTIL_LOOPER_H_
#define SRC_UTIL_LOOPER_H_

#include "Notifier.h"
#include "Timer.h"
#include <vector>
#include <iostream>


class Looper {
public:
	Looper();
	void StartLoop();
	void StopLoop();
	void RunLoop();
	double kPeriod=0.02;	//timer period in ms 0.02 = 20 ms

	virtual void OnStart(double timestamp) =0;
	virtual void OnLoop(double timestamp) =0;
	virtual void OnStop(double timestamp) =0;

private:
	bool m_isRunning;
	std::unique_ptr<Notifier> m_controlloop;
	//static constexpr double m_timestamp=0;
	//static double m_dt=0;

};

#endif /* SRC_UTIL_LOOPER_H_ */

/*
 * Looper.h
 *
 */

#ifndef SRC_UTIL_UNITMASTER_H_
#define SRC_UTIL_UNITMASTER_H_


#include <Constants.h>


class UnitMaster {
public:
	UnitMaster(double WheelDiameter, double EncoderUpDuction, double TicksPerRev);
	UnitMaster();

	void SetInches(double func_inches);
	void SetInchesPerSec(double func_inches_per_sec);

	void SetRotations(double func_rotations);
	void SetRotationsPerSec(double func_rotations_per_sec);

	void SetTicks(double func_ticks);
	void SetTicksPerSec(double func_ticks_per_sec);
	void SetTicksPer100ms(double func_ticks_per_100ms);


	double GetInches();
	double GetInchesPerSec(double func_ticks_per_100_ms);

	double GetRotations();
	double GetRotationsPerSec();

	double GetTicks();
	double GetTicksPerSec();
//	double GetTicksPer100ms();

	double GetTicksPer100ms(double func_inches_per_sec);







private:
	double m_WheelDiameter = WHEEL_DIAMETER_INCHES;
	double m_EncoderUpDuction = ENCODER_GEAR_UPDUCTION;
	double m_TicksPerRotations = TICKS_PER_ROTATIONS;

	double m_ticks = 0.0;
	double m_ticks_per_sec = 0.0;


};

#endif /* SRC_UTIL_UNITMASTER_H_ */

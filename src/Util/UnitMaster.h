/*
 * Looper.h
 *
 */

#ifndef SRC_UTIL_UNITMASTER_H_
#define SRC_UTIL_UNITMASTER_H_


#include <iostream>
#include <Constants.h>


class UnitMaster {
public:
	UnitMaster(double WheelDiameter, double EncoderGearReduction, double EncoderTicksPerRev);
	UnitMaster();

	double FeetToInches(double feet);
	double InchesToFeet(double inches);


	double InchesToTicks(double inches);
	double TicksToInches(double ticks);

	double TicksToTicksPer100Ms(double ticks);
	double TicksPer100MsToTicks(double ticks_per_100ms);




private:
	double m_WheelDiameter = WHEEL_DIAMETER_INCHES;
	double m_EncoderGearReduction = ENCODER_GEAR_REDUCTION;
	double m_EncoderTicksPerRev = ENCODER_TICKS_PER_REV;

};

#endif /* SRC_UTIL_UNITMASTER_H_ */

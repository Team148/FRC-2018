#include <Util/UnitMaster.h>

UnitMaster::UnitMaster(double WheelDiameter, double EncoderGearReduction, double EncoderTicksPerRev)
{
	m_WheelDiameter = WheelDiameter;
	m_EncoderGearReduction = EncoderGearReduction;
	m_EncoderTicksPerRev = EncoderTicksPerRev;
}
UnitMaster::UnitMaster()
{
	m_WheelDiameter = WHEEL_DIAMETER_INCHES;
	m_EncoderGearReduction = ENCODER_GEAR_REDUCTION;
	m_EncoderTicksPerRev = ENCODER_TICKS_PER_REV;
}
double UnitMaster::FeetToInches(double feet) {

}
double UnitMaster::InchesToFeet(double inches) {

}

double UnitMaster::InchesToTicks(double inches) {

}
double UnitMaster::TicksToInches(double ticks) {

}

double UnitMaster::TicksToTicksPer100Ms(double ticks) {

}
double UnitMaster::TicksPer100MsToTicks(double ticks_per_100ms) {

}




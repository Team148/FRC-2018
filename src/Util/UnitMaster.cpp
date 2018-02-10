#include <Util/UnitMaster.h>
#include <iostream>
#include <math.h>

//UnitMaster::UnitMaster(double WheelDiameter, double EncoderUpDuction, double TicksPerRotations)
//{
//	m_WheelDiameter = WheelDiameter;
//	m_EncoderUpDuction = EncoderUpDuction;
//	m_TicksPerRotations = TicksPerRotations;
//}

UnitMaster *UnitMaster::m_instance = 0;

UnitMaster::UnitMaster()
{
	m_WheelDiameter = WHEEL_DIAMETER_INCHES;
	m_EncoderUpDuction = ENCODER_GEAR_UPDUCTION;
	m_TicksPerRotations = TICKS_PER_ROTATIONS;
}

UnitMaster* UnitMaster::GetInstance() {
	if (m_instance ==  0) {
		//std::cout << "info: GetInstance Creating UnitMaster Class" << std::endl;
		m_instance = new UnitMaster();
	}
	return m_instance;
}

void UnitMaster::SetInches(double func_inches)
{
	//	double m_ticks = inches*m_TicksPerRev/(m_EncoderUpDuction*M_PI*m_WheelDiameter);

	m_ticks = func_inches*m_TicksPerRotations/(m_EncoderUpDuction*(M_PI*m_WheelDiameter));
}
void UnitMaster::SetInchesPerSec(double func_inches_per_sec)
{
	////	double return_ticks_per_sec = (inches_per_sec*m_TicksPerRec)/(m_EncoderUpDuction*(M_PI*m_WheelDiameter));
	m_ticks_per_sec = (func_inches_per_sec*m_TicksPerRotations)/(m_EncoderUpDuction*(M_PI*m_WheelDiameter));
}

void UnitMaster::SetRotations(double func_rotations)
{
	m_ticks = func_rotations*(m_TicksPerRotations/m_EncoderUpDuction);
}
void UnitMaster::SetRotationsPerSec(double func_rotations_per_sec)
{
	m_ticks_per_sec = func_rotations_per_sec*(m_TicksPerRotations/m_EncoderUpDuction);
}

void UnitMaster::SetTicks(double func_ticks)
{
	m_ticks = func_ticks;
}
void UnitMaster::SetTicksPerSec(double func_ticks_per_sec)
{
	m_ticks_per_sec = func_ticks_per_sec;
}
void UnitMaster::SetTicksPer100ms(double func_ticks_per_100ms)
{
	m_ticks_per_sec = (func_ticks_per_100ms*10);
}


double UnitMaster::GetInches()
{
	//	double m_ticks = inches*m_TicksPerRev/(m_EncoderUpDuction*M_PI*m_WheelDiameter);
	return m_ticks*((m_EncoderUpDuction*(M_PI*m_WheelDiameter))/m_TicksPerRotations);
}
//double UnitMaster::GetInchesPerSec()
//{
//	////	double return_ticks_per_sec = (inches_per_sec*m_TicksPerRec)/(m_EncoderUpDuction*(M_PI*m_WheelDiameter));
//	return m_ticks_per_sec*((m_EncoderUpDuction*(M_PI*m_WheelDiameter))/m_TicksPerRotations);
//}

double UnitMaster::GetRotations()
{
	return GetInches()*(1/(M_PI*m_WheelDiameter));
}
//double UnitMaster::GetRotationsPerSec()
//{
//	return GetInchesPerSec()*(1/(M_PI*m_WheelDiameter));
//}

double UnitMaster::GetTicks()
{
	return m_ticks;
}

double UnitMaster::GetTicksPerSec()
{
	return m_ticks_per_sec;

}
//double UnitMaster::GetTicksPer100ms()
//{
//	return (m_ticks_per_sec*0.10);
//}

double UnitMaster::GetTicksPer100ms(double func_inches_per_sec)
{
	return ((func_inches_per_sec*m_TicksPerRotations)/(m_EncoderUpDuction*(M_PI*m_WheelDiameter)))*0.10;
}
double UnitMaster::GetInchesPerSec(double func_ticks_per_100_ms)
{
	return (func_ticks_per_100_ms*10)*((m_EncoderUpDuction*(M_PI*m_WheelDiameter))/m_TicksPerRotations);

}

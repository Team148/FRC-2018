#ifndef SRC_UTIL_FEATHER_H_
#define SRC_UTIL_FEATHER_H_

#include "RobotMap.h"
#include "WPIlib.h"


class Feather {
public:

	enum Sensor {
		TFMini,

	};

	enum IOmode {
		Digital,
		Analog,
	};
	Feather(Feather::IOmode io, int pin);
	int Get();


private:
	AnalogInput *m_ai;
	DigitalInput *m_di;
	Counter *m_ci;

	IOmode m_mode;
	//Sensor m_sens;
};

#endif /* SRC_UTIL_FEATHER_H_ */

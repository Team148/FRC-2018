/*
 * Feather.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: justin
 */

#include <Util/Feather.h>
#include <iostream>

Feather::Feather(Feather::IOmode io, int pin) {

	if(io == Analog) {
		m_ai = new AnalogInput(pin);
		m_mode = Analog;
		std::cout <<"Feather set as Analog" << std::endl;
	}
	else {
		m_di = new DigitalInput(pin);
		m_mode = Digital;
		std::cout <<"Feather set as Digital" << std::endl;
	}

}

int Feather::Get() {
	if(m_mode == Analog) {
		std::cout <<"feather get: " << m_ai->GetValue() << std::endl;
		return m_ai->GetVoltage();
	}

	if(m_mode == Digital) {
		//std::cout <<"feather get" << std::endl;
		return (int)m_di->Get();
	}


}


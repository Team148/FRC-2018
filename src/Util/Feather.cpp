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
		m_ci = new Counter(Counter::Mode::kPulseLength);
		m_mode = Analog;
		std::cout <<"Feather set as Analog on pin " << pin << std::endl;
		//m_ai->SetAverageBits(8);
		//m_ai->SetOversampleBits(2);
		m_ci->SetUpSource(1);
		m_ci->SetPulseLengthMode(.002);
		m_ci->SetMaxPeriod(.002);

	}
	else {
		m_di = new DigitalInput(pin);
		m_mode = Digital;
		std::cout <<"Feather set as Digital on pin " << pin << std::endl;
	}

}

int Feather::Get() {
	if(m_mode == Analog) {
		//std::cout <<"feather get: " << m_ai->GetVoltage() << std::endl;
		//return m_ai->GetAverageValue();
		std::cout <<"feather get: " << m_ci->GetPeriod()*1000 << std::endl;
		return m_ci->GetPeriod()*1000;
	}

	if(m_mode == Digital) {
		//std::cout <<"feather get" << std::endl;
		return (int)m_di->Get();
	}


}


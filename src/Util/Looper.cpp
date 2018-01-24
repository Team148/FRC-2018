
#include <Util/Looper.h>

Looper::Looper() {
	m_isRunning = false;
	m_controlloop = std::make_unique<Notifier>(&Looper::RunLoop, this);

}

void Looper::RunLoop()
{
	double now = Timer::GetFPGATimestamp();

	OnLoop(now);
	std::cout << "RunLoop" << std::endl;

}

void Looper::StartLoop() {
	if(!m_isRunning) {
		std::cout << "Starting loops" << std::endl;
		double now = Timer::GetFPGATimestamp();
		OnStart(now);

		m_isRunning = true;
	}
	m_controlloop->StartPeriodic(kPeriod);
}

void Looper::StopLoop() {
	if(m_isRunning) {
		std::cout << "Stopping loops" << std::endl;
		double now = Timer::GetFPGATimestamp();
		m_controlloop->Stop();
		OnStop(now);

		m_isRunning = false;
	}
}

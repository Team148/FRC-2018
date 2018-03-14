#include "RunWrist.h"
#include "OI.h"
#include <iostream>

RunWrist::RunWrist(double percent) {
	Requires(Wrist::GetInstance());
	m_percent = percent;
}

void RunWrist::Initialize() {

	Wrist::GetInstance()->SetWristMotor(m_percent);

}

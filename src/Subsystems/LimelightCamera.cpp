#include "LimelightCamera.h"
//#include "../RobotMap.h"
#include <Joystick.h>
#include <SmartDashboard/SmartDashboard.h>

//#include "../Commands/GrabPostLimelightData.h"

LimelightCamera *LimelightCamera::m_instance = 0;

LimelightCamera::LimelightCamera() : frc::Subsystem("LimelightCamera") {
	 CameraData *cd;


}

LimelightCamera* LimelightCamera::GetInstance() {
	if (m_instance ==  0) {
		m_instance = new LimelightCamera();
	}
	return m_instance;
}

void LimelightCamera::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new GrabPostLimelightData());



}

// Put methods for controlling this subsystem
// here. Call these from Commands.

CameraData* LimelightCamera::GetCameraData()
{

	//targetOffsetAngle_Horizontal = table->GetNumber("tx",0);
	//targetOffsetAngle_Vertical = table->GetNumber("ty",0);
	//targetArea = table->GetNumber("ta",0);
	//targetSkew = table->GetNumber("ts",0);

	cd->xOffSet = table->GetNumber("tx",0);
	cd->yOffSet = table->GetNumber("ty",0);
	cd->targetArea = table->GetNumber("ta",0);
	cd->validObject = table->GetNumber("ts",0);
	cd->latency = table->GetNumber("tl",0);

	frc::SmartDashboard::PutNumber("HorizOffset", cd->xOffSet);
	frc::SmartDashboard::PutNumber("VertOffset", cd->yOffSet);
	frc::SmartDashboard::PutNumber("Area", cd->targetArea);
	frc::SmartDashboard::PutNumber("Skew", cd->Skew);

	return cd;
}


float LimelightCamera::GetDistanceFromObject()
{

}

void LimelightCamera::SetCameraLEDOn()
{
        table->PutNumber("ledMode", 0); //0,1,2 -> on,off,blink
}

void LimelightCamera::SetCameraLEDOff()
{
        table->PutNumber("ledMode", 1); //0,1,2 -> on,off,blink
}

void LimelightCamera::SetCameraLEDBlink()
{
        table->PutNumber("ledMode", 2); //0,1,2 -> on,off,blink
}

void LimelightCamera::SetCameraPipeline(int pipe)
{
        table->PutNumber("ledMode", pipe); //0->9 are valid pipelines
}


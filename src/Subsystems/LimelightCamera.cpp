#include "LimelightCamera.h"


LimelightCamera *LimelightCamera::m_instance = 0;


LimelightCamera::LimelightCamera() : frc::Subsystem("LimelightCamera") {
	std::cout <<"Creating Limelight" << std::endl;
	inst->GetDefault();
	table = NetworkTable::GetTable("limelight");

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
	SetDefaultCommand(new UpdateLimeLight());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LimelightCamera::GetCameraData()
{

	validObject = table->GetEntry("tv");
	xOffSet = table->GetEntry("tx");
	yOffSet = table->GetEntry("ty");
	targetArea = table->GetEntry("ta");
	latency = table->GetEntry("tl");
	skew = table->GetEntry("ts");
	ledMode = table->GetEntry("ledMode");

	if(ledMode.GetDouble(-1) == 0)
		SetCameraLEDOff();

	frc::SmartDashboard::PutNumber("validObject", validObject.GetDouble(-1));
	frc::SmartDashboard::PutNumber("HorizOffset", xOffSet.GetDouble(99.));
	frc::SmartDashboard::PutNumber("VertOffset", yOffSet.GetDouble(99.));
	frc::SmartDashboard::PutNumber("Area", targetArea.GetDouble(-1.));
	frc::SmartDashboard::PutNumber("Skew", skew.GetDouble(99.));


}

bool LimelightCamera::CheckConnection() {
	std::cout <<"CheckConn" << std::endl;
	//table->GetTable("limelight");
	//if(table->IsConnected()){
	m_connected=true;
	//}
	//return table->IsConnected();
	return true;
}

float LimelightCamera::GetDistanceFromObject()
{

}

void LimelightCamera::SetCameraLEDOn()
{
	ledMode.SetDouble(0.0); //0,1,2 -> on,off,blink
}

void LimelightCamera::SetCameraLEDOff()
{
	ledMode.SetDouble(1.0); //0,1,2 -> on,off,blink
}

void LimelightCamera::SetCameraLEDBlink()
{
	ledMode.SetDouble(2.0); //0,1,2 -> on,off,blink
}

void LimelightCamera::SetCameraPipeline(double pipe)
{
     pipeline.SetDouble(pipe); //0->9 are valid pipelines
}

double LimelightCamera::GetOffsetAngle() {
	return xOffSet.GetDouble(99);
}


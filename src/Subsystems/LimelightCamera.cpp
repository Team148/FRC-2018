#include "LimelightCamera.h"


LimelightCamera *LimelightCamera::m_instance = 0;


LimelightCamera::LimelightCamera() : frc::Subsystem("LimelightCamera") {
	std::cout <<"Creating Limelight" << std::endl;

	table = NetworkTable::GetTable("limelight");

	m_ledMode = 1.0;		//set LEDs to default to off
	m_pipeline = 0.0;

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
	SetDefaultCommand(new UpdateLimeLight());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LimelightCamera::GetCameraData()
{

	//read values from NetworkTables
	validObject = table->GetEntry("tv");
	xOffSet = table->GetEntry("tx");
	yOffSet = table->GetEntry("ty");
	//targetArea = table->GetEntry("ta");
	//latency = table->GetEntry("tl");
	//skew = table->GetEntry("ts");
	ledMode = table->GetEntry("ledMode");


	frc::SmartDashboard::PutNumber("validObject", validObject.GetDouble(-1));
	frc::SmartDashboard::PutNumber("HorizOffset", xOffSet.GetDouble(0));
	//frc::SmartDashboard::PutNumber("VertOffset", yOffSet.GetDouble(99.));
	//frc::SmartDashboard::PutNumber("Area", targetArea.GetDouble(-1.));
	//frc::SmartDashboard::PutNumber("Skew", skew.GetDouble(99.));

	//Write NetworkTables with desired values
	ledMode.SetDouble(m_ledMode);

}

bool LimelightCamera::CheckConnection() {
	if(validObject.GetDouble(-1) == -1) {
		std::cout << "Lost Connection to Limelight" << std::endl;
		table = NetworkTable::GetTable("limelight");
		return false;
	}
	else
		return true;
}

void LimelightCamera::SetCameraLEDOn()
{
	m_ledMode = 0.0; //0,1,2 -> on,off,blink
}

void LimelightCamera::SetCameraLEDOff()
{
	m_ledMode = 1.0; //0,1,2 -> on,off,blink
}

void LimelightCamera::SetCameraLEDBlink()
{
	m_ledMode = 2.0;; //0,1,2 -> on,off,blink
}

void LimelightCamera::SetCameraPipeline(double pipe)
{
     m_pipeline = pipe; //0->9 are valid pipelines
}

void LimelightCamera::SetEnableVision(bool on)
{
	if(on == true)
	{
		m_visionEnabled = true;
	}
	if(on == false)
	{
		m_visionEnabled = false;
	}
}
bool LimelightCamera::IsEnabled()
{
	return m_visionEnabled;
}


double LimelightCamera::GetOffsetAngle() {
	std::cout << xOffSet.GetDouble(0) << std::endl;
	return xOffSet.GetDouble(0);

}

bool LimelightCamera::IsTargeting() {
	if(validObject.GetDouble(-1) > 0)
		return true;
	else
		return false;
}

#include "LimelightCamera.h"
#include "Drivetrain.h"

LimelightCamera *LimelightCamera::m_instance = 0;


LimelightCamera::LimelightCamera() : frc::Subsystem("LimelightCamera") {
	std::cout <<"Creating Limelight" << std::endl;

	table = NetworkTable::GetTable("limelight");

	m_ledMode = 1.0;		//set LEDs to default to off
	m_pipeline = 0.0;
	m_camMode = 0.0;

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
	ledMode = table->GetEntry("ledMode");
	pipeline = table->GetEntry("pipeline");
	cammode = table->GetEntry("camMode");


	frc::SmartDashboard::PutNumber("validObject", validObject.GetDouble(-1));
	frc::SmartDashboard::PutNumber("HorizOffset", xOffSet.GetDouble(0));
	//frc::SmartDashboard::PutNumber("VertOffset", yOffSet.GetDouble(99.));
	//frc::SmartDashboard::PutNumber("Area", targetArea.GetDouble(-1.));
	//frc::SmartDashboard::PutNumber("Skew", skew.GetDouble(99.));

	//Write NetworkTables with desired values
	ledMode.SetDouble(m_ledMode);
	pipeline.SetDouble(m_pipeline);
	cammode.SetDouble(m_camMode);

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

void LimelightCamera::SetCameraLEDBlink() {
	m_ledMode = 2.0;; //0,1,2 -> on,off,blink
}

void LimelightCamera::SetPipeline(double pipe) {
     m_pipeline = pipe; //0->9 are valid pipelines 0 sorts for largest, 1 for right, 2 for left
}

bool LimelightCamera::IsEnabled() {
	return m_visionEnabled;
}


double LimelightCamera::GetOffsetAngle() {
	std::cout << xOffSet.GetDouble(0) << std::endl;
	return xOffSet.GetDouble(0);

}
double LimelightCamera::GetTargetHeading() {
	double m_target_heading = Drivetrain::GetInstance()->getRobotPathHeading();
	if(IsTargeting())
	{
		m_target_heading = Drivetrain::GetInstance()->getRobotPathHeading() + (-xOffSet.GetDouble(0));
	}
	return m_target_heading;
}

bool LimelightCamera::IsTargeting() {
	if(validObject.GetDouble(-1) > 0)
		return true;
	else
		return false;
}

void LimelightCamera::SetEnableVision(bool on) {
	if(on)
		m_camMode = 0.0;
	else
		m_camMode = 1.0;
}

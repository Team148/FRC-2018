#ifndef LimelightCamera_H
#define LimelightCamera_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "networktables/NetworkTableInstance.h"


struct CameraData {
	  bool validObject;
	  double xOffSet;
	  double yOffSet;
	  double targetArea;
	  double Skew;
	  double latency;
	} ;

class LimelightCamera : public frc::Subsystem {
public:


	LimelightCamera();
	void InitDefaultCommand();
	CameraData* GetCameraData();
	static LimelightCamera* GetInstance();
	void SetCameraLEDOn();
	void SetCameraLEDOff();
	void SetCameraLEDBlink();
	void SetCameraPipeline(int pipe);
	float GetDistanceFromObject();


private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	static LimelightCamera* m_instance;
	std::shared_ptr<NetworkTable> table =   NetworkTable::GetTable("limelight");




	CameraData *cd;


};

#endif  // LimelightCamera_H

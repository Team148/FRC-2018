#ifndef LimelightCamera_H
#define LimelightCamera_H

#include <Commands/Subsystem.h>
#include <iostream>
#include "WPILib.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include "Commands/UpdateLimeLight.h"



class LimelightCamera : public frc::Subsystem {
public:
	static LimelightCamera* GetInstance();
	void InitDefaultCommand();

	void GetCameraData();
	void SetCameraLEDOn();
	void SetCameraLEDOff();
	void SetCameraLEDBlink();
	void SetPipeline(double pipe);
	double GetOffsetAngle();
	bool CheckConnection();
	bool IsTargeting();


private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	static LimelightCamera* m_instance;
	LimelightCamera();

	bool m_connected=false;
	std::shared_ptr<nt::NetworkTableInstance> inst;
	std::shared_ptr<nt::NetworkTable> table;


	nt::NetworkTableEntry validObject;
	nt::NetworkTableEntry xOffSet;
	nt::NetworkTableEntry yOffSet;
	nt::NetworkTableEntry targetArea;
	nt::NetworkTableEntry skew;
	nt::NetworkTableEntry latency;
	nt::NetworkTableEntry ledMode;
	nt::NetworkTableEntry pipeline;

	double m_ledMode;
	double m_pipeline;


};

#endif  // LimelightCamera_H

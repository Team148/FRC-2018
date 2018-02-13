#include "CommandBase.h"

#include <Commands/Scheduler.h>


// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
//std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
//		std::make_unique<ExampleSubsystem>();

//std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
//std::unique_ptr<Conveyor> CommandBase::conveyor = std::make_unique<Conveyor>();
//std::unique_ptr<Drivetrain> CommandBase::drivetrain = std::make_unique<Drivetrain>();
//std::unique_ptr<Intake> CommandBase::intake = std::make_unique<Intake>();
//std::unique_ptr<Shooter> CommandBase::shooter = std::make_unique<Shooter>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {


}

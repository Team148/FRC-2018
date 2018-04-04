#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>
#include <Subsystems/Climber.h>
#include <Subsystems/Drivetrain.h>
#include <Subsystems/Elevator.h>
#include <Subsystems/Intake.h>
#include <Subsystems/Wrangler.h>
#include <Subsystems/LimelightCamera.h>




/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	// Create a single static instance of all of your subsystems

	//static std::unique_ptr<OI> oi;
	//static std::unique_ptr<Conveyor> conveyor;
	//static std::unique_ptr<Drivetrain> drivetrain;
	//static std::unique_ptr<Intake> intake;
	//static std::unique_ptr<Shooter> shooter;


};

#endif  // COMMAND_BASE_H

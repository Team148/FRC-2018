#ifndef DriveAndScore_H
#define DriveAndScore_H


#include <Commands/Auto/AutoSetElevatorAfterTime.h>
#include <Commands/CommandGroup.h>
#include "Commands/Auto/AutoDrive.h"
#include "Commands/Auto/AutoIntake.h"


class DriveAndScore : public frc::CommandGroup {
public:
	DriveAndScore();
};

#endif

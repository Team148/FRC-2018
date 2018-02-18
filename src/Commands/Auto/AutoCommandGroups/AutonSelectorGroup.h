#ifndef AutonSelectorGroup_H
#define AutonSelectorGroup_H

#include <Commands/CommandGroup.h>

#include "../../../Constants.h"

class AutonSelectorGroup : public frc::CommandGroup {
public:
	AutonSelectorGroup(tStartingPosition start_pos, char* FMS_Data, tCubeAmount cube_amount);
};

#endif  // AutonSelectorGroup_H

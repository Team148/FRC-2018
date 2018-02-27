#ifndef AutonSelectorGroup_H
#define AutonSelectorGroup_H

#include <Commands/CommandGroup.h>

#include "../../../Constants.h"
#include <string>


class AutonSelectorGroup : public frc::CommandGroup {
public:
	AutonSelectorGroup(int start_pos, std::string FMS_Data, int cube_amount);
};

#endif  // AutonSelectorGroup_H

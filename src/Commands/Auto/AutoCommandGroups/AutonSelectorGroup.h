#ifndef AutonSelectorGroup_H
#define AutonSelectorGroup_H

#include <Commands/CommandGroup.h>

#include "../../../Constants.h"


class AutonSelectorGroup : public frc::CommandGroup {
public:
	AutonSelectorGroup(int start_pos, char* FMS_Data, int cube_amount);

private:
	autoStringData autoConstData;

};

#endif  // AutonSelectorGroup_H

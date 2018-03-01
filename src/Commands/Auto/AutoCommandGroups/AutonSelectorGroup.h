#ifndef AutonSelectorGroup_H
#define AutonSelectorGroup_H

#include <Commands/CommandGroup.h>

#include "../../../Constants.h"
#include <string>



class AutonSelectorGroup : public frc::CommandGroup {
public:
	AutonSelectorGroup(int start_pos = tStartingPosition::RIGHT_POS,  std::string FMS_Data = "", int cube_amount = 1);

private:
	autoStringData autoConstData;

};

#endif  // AutonSelectorGroup_H

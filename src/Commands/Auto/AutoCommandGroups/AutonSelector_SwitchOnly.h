#ifndef AutonSelector_SwitchOnly_H
#define AutonSelector_SwitchOnly_H

#include <Commands/CommandGroup.h>

#include "../../../Constants.h"
#include <string>



class AutonSelector_SwitchOnly : public frc::CommandGroup {
public:
	AutonSelector_SwitchOnly(int start_pos = tStartingPosition::MIDDLE_POS,  std::string FMS_Data = "", int cube_amount = 1, bool backIncluded = false);

private:
	autoStringData autoConstData;

};

#endif  // AutonSelector_SwitchOnly_H

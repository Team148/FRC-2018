#ifndef AutonSelector_BackSwitchOnly_H
#define AutonSelector_BackSwitchOnly_H

#include <Commands/CommandGroup.h>

#include "../../../Constants.h"
#include <string>



class AutonSelector_BackSwitchOnly : public frc::CommandGroup {
public:
	AutonSelector_BackSwitchOnly(int start_pos = tStartingPosition::MIDDLE_POS,  std::string FMS_Data = "", int cube_amount = 1);

private:
	autoStringData autoConstData;

};

#endif  // AutonSelector_BackSwitchOnly_H

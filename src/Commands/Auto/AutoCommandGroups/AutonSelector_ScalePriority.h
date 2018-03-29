#ifndef AutonSelector_ScalePriority_H
#define AutonSelector_ScalePriority_H

#include <Commands/CommandGroup.h>

#include "../../../Constants.h"
#include <string>



class AutonSelector_ScalePriority : public frc::CommandGroup {
public:
	AutonSelector_ScalePriority(int start_pos = tStartingPosition::RIGHT_POS,  std::string FMS_Data = "", int cube_amount = 1);

private:
	autoStringData autoConstData;

};

#endif  // AutonSelector_ScalePriority_H

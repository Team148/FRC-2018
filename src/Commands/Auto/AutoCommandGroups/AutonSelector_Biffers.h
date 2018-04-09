#ifndef AutonSelector_Biffers_H
#define AutonSelector_Biffers_H

#include <Commands/CommandGroup.h>

#include "../../../Constants.h"
#include <string>



class AutonSelector_Biffers : public frc::CommandGroup {
public:
	AutonSelector_Biffers(int start_pos = tStartingPosition::RIGHT_POS,  std::string FMS_Data = "", int cube_amount = 1);

private:
	autoStringData autoConstData;

};

#endif  // AutonSelector_Biffers_H

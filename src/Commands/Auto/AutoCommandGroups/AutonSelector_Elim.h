#ifndef AutonSelector_Elim_H
#define AutonSelector_Elim_H

#include <Commands/CommandGroup.h>

#include "../../../Constants.h"
#include <string>



class AutonSelector_Elim : public frc::CommandGroup {
public:
	AutonSelector_Elim(int start_pos = tStartingPosition::RIGHT_POS,  std::string FMS_Data = "", int cube_amount = 1);

private:
	autoStringData autoConstData;

};

#endif  // AutonSelector_Elim_H

#ifndef AutonSelector_Hybrid_H
#define AutonSelector_Hybrid_H

#include <Commands/CommandGroup.h>

#include "../../../Constants.h"
#include <string>



class AutonSelector_Hybrid : public frc::CommandGroup {
public:
	AutonSelector_Hybrid(int start_pos = tStartingPosition::RIGHT_POS,  std::string FMS_Data = "", int cube_amount = 1);

private:
	autoStringData autoConstData;

};

#endif  // AutonSelector_Hybrid_H

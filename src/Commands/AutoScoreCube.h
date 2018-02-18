#ifndef AutoScoreCube_H
#define AutoScoreCube_H

#include <Commands/CommandGroup.h>
#include "../Util/UnitMaster.h"

class AutoScoreCube : public CommandGroup {
public:
	AutoScoreCube();
private:
	UnitMaster unit_master;
};

#endif  // AutoScoreCube_H

#include "../../AutoPaths/PathExecuter.h"


#include <Commands/Auto/AutoCommandGroups/AutonSelector_Elim.h>
#include "./Paths/FromRightPos_ToLeftSwitchPath.h"


#include "./Paths/FromRightPos_ToRightSwitchPath.h"
#include "./Paths/FromRightPos_ToLeftSwitchPathReversed.h"
#include "./Paths/FromLeftSwitch_ToLeftScalePathReversed.h"
#include "./Paths/FromRightFirstCube_ToLeftSwitchPathReversed.h"

#include "./Paths/FromRightPos_ToRightScalePath.h"
#include "./Paths/FromRightPos_ToLeftScalePath.h"
#include "./Paths/FromLeftPos_ToLeftScalePath.h"
#include "./Paths/FromCenterPile_ToRightScaleSneak.h"
#include "./Paths/FromCenterPile_ToLeftScaleSneak.h"



#include "./Paths/FromRightScale_ToRightFirstCubePath.h"
#include "./Paths/FromRightFirstCube_ToLeftScalePath.h"
#include "./Paths/FromRightScale_ToRightSecondCubePath.h"
#include "./Paths/FromRightSecondCube_ToRightScalePath.h"
#include "./Paths/FromRightFirstCube_ToLeftSwitchPath.h"


#include "./Paths/FromLeftSwitch_ToRightScalePath.h"
#include "./Paths/FromLeftSwitch_ToLeftScalePath.h"
#include "./Paths/FromRightPos_ToLeftSwitchPath.h"


#include "./Paths/FromRightPos_ToLeftScale118Path.h"
#include "./Paths/FromMiddlePos_ToLeftScaleDumpPath.h"
#include "./Paths/FromMiddlePos_ToRightScaleDumpPath.h"



#include "./Paths/FromMiddlePos_ToLeftSwitchPath.h"
#include "./Paths/FromMiddlePos_ToRightSwitchBackPath.h"
#include "./Paths/FromMiddlePos_ToLeftSwitchBackPath.h"
#include "./Paths/FromMiddlePos_ToRightSwitchPath.h"
#include "./Paths/FromRightSwitchFront_ToRightScaleBackReversePath.h"
#include "./Paths/FromRightSwitchFront_ToCenterPileReversed.h"
#include "./Paths/FromCenterPile_ToRightSwitchFront.h"

#include "./Paths/FromLeftSwitchFront_ToLeftScaleBackReversePath.h"
#include "./Paths/FromLeftSwitchFront_ToCenterPileReversed.h"
#include "./Paths/FromCenterPile_ToLeftSwitchFront.h"

#include "./Paths/FromRightFirstCube_ToRightScalePath.h"
#include "./Paths/FromMiddlePos_ToRightScaleSneakPath.h"
#include "./Paths/FromMiddlePos_ToLeftScaleSneakPath.h"


#include "../TurnPosition.h"
#include "../TurnPositionMagic.h"
#include "../AutoDrive.h"
#include "../CheckHeading.h"


#include "../ReleaseIntake.h"
#include "../AutoIntake.h"

#include "../AutoSetElevator.h"
#include "../../EnableVisionTracking.h"
#include "../DriveLineVelocity.h"


#include "FromRightPos_ToRightScaleGroup.h"
#include "FromRightPos_ToLeftScaleGroup.h"
#include "CenterPile_ToLeftScaleGroup.h"
#include "CenterPile_ToRightScaleGroup.h"

#include "FromRightPos_ToLeftSwitchGroup.h"
#include "FromRightPos_ToRightSwitchGroup.h"

#include "FrontLeftSwitchGroup.h"
#include "FrontRightSwitchGroup.h"





#include <iostream>
#include "math.h"

#define RadianToDegrees(angleRadians) ((angleRadians) * 180 / M_PI)

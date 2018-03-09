/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CheckFunction.h"

CheckFunction::CheckFunction() {
	// Use Requires() here to declare subsystem dependencies

}

// Called just before this Command runs the first time
void CheckFunction::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CheckFunction::Execute() {

	//Check Drive motor current
	if(OI::GetInstance()->drvStick->GetRawAxis(4) > 0.2  || OI::GetInstance()->drvStick->GetRawAxis(4) < -0.2 ) {
		double *cur = Drivetrain::GetInstance()->GetAllCurrents();
		for(int i = 0; i<=5;i++) {
			drivecurrent[i][drivecurrentcounter] = abs(*(cur + i));
		}

		//need to collect at least 10 samples before we start checking
		drivecurrentcounter++;
		if(drivecurrentcounter >= 9) {
			drivecurrentcounter = 0;
			readytocheck=true;
		}

		if(readytocheck) {
			//check l1
			for(int i = 0; i<9;i++) {
				if(drivecurrent[0][i] < drivelowerlimit)
					l1failflag=true;
			}

			//check l2
			for(int i = 0; i<9;i++) {
				if(drivecurrent[1][i] < drivelowerlimit)
					l2failflag=true;
			}

			//check l3
			for(int i = 0; i<9;i++) {
				if(drivecurrent[2][i] < drivelowerlimit)
					l3failflag=true;
			}

			if(!l1failflag)
				l1currentpass=true;
			if(!l2failflag)
				l2currentpass=true;
			if(!l3failflag)
				l3currentpass=true;
		}//endif
	}//endif



}

// Make this return true when this Command no longer needs to run execute()
bool CheckFunction::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CheckFunction::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CheckFunction::Interrupted() {

}

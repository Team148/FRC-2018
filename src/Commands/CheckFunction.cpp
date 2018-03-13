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

	drivereadytocheck=false;
	l1currentpass=false;
	l2currentpass=false;
	l3currentpass=false;
	r1currentpass=false;
	r2currentpass=false;
	r3currentpass=false;

	l1failflag=false;
	l2failflag=false;
	l3failflag=false;
	r1failflag=false;
	r2failflag=false;
	r3failflag=false;


	elev1failflag=false;
	elev2failflag=false;
	elev1currentpass=false;
	elev2currentpass=false;

	intake1failflag=false;
	intake2failflag=false;
	intake1currentpass=false;
	intake2currentpass=false;

	std::cout <<"starting Check" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void CheckFunction::Execute() {

	//check all currents
	for(int x=0;x<=15;x++)
		pdp_curr[x][currentcounter]=fabs(Drivetrain::GetInstance()->pdp->GetCurrent(x));

	currentcounter++;
	if(currentcounter > 9) {
		currentcounter = 0;
		limelightcheckready=true;
	}

	//Check Drive motor current
	SmartDashboard::PutNumber("Drive L1 Current", pdp_curr[0][currentcounter]);
	SmartDashboard::PutNumber("Drive L2 Current", pdp_curr[1][currentcounter]);
	SmartDashboard::PutNumber("Drive L3 Current", pdp_curr[2][currentcounter]);
	SmartDashboard::PutNumber("Drive R1 Current", pdp_curr[15][currentcounter]);
	SmartDashboard::PutNumber("Drive R2 Current", pdp_curr[14][currentcounter]);
	SmartDashboard::PutNumber("Drive R3 Current", pdp_curr[13][currentcounter]);


	//need to collect at least 10 samples before we start checking
	if(pdp_curr[0][currentcounter]!=0 && pdp_curr[15][currentcounter]!=0) {
		drivecounter++;
		if(drivecounter >= 9) {
			drivecounter = 0;
			drivereadytocheck=true;
		}
	}

	if(drivereadytocheck) {
		//check l1
		for(int i = 0; i<9;i++) {
			if(pdp_curr[0][i] < drivelowerlimit)
				l1failflag=true;
		}
		//check l2
		for(int i = 0; i<9;i++) {
			if(pdp_curr[1][i] < drivelowerlimit)
				l2failflag=true;
		}
		//check l3
		for(int i = 0; i<9;i++) {
			if(pdp_curr[2][i] < drivelowerlimit)
				l3failflag=true;
		}
		//check r1
		for(int i = 0; i<9;i++) {
			if(pdp_curr[15][i] < drivelowerlimit)
				r3failflag=true;
		}
		//check r2
		for(int i = 0; i<9;i++) {
			if(pdp_curr[14][i] < drivelowerlimit)
				r3failflag=true;
		}
		//check r3
		for(int i = 0; i<9;i++) {
			if(pdp_curr[13][i] < drivelowerlimit)
				r3failflag=true;
		}

		if(!l1failflag)
			l1currentpass=true;
		if(!l2failflag)
			l2currentpass=true;
		if(!l3failflag)
			l3currentpass=true;
		if(!r1failflag)
			r1currentpass=true;
		if(!r2failflag)
			r2currentpass=true;
		if(!r3failflag)
			r3currentpass=true;
	}//endif


	//check elevator current
	SmartDashboard::PutNumber("Elevator 1 Current", pdp_curr[11][currentcounter]);
	SmartDashboard::PutNumber("Elevator 2 Current", pdp_curr[5][currentcounter]);

	if(pdp_curr[11][currentcounter] != 0 ) {
		elevcounter++;
		if(elevcounter >= 9) {
			elevcounter = 0;
			elevreadytocheck=true;
		}

		if(elevreadytocheck) {
			for(int i = 0; i<9;i++) {
				if(pdp_curr[11][i] < elevlowerlimit)
					elev1failflag=true;
			}
			for(int i = 0; i<9;i++) {
				if(pdp_curr[5][i] < elevlowerlimit)
					elev2failflag=true;
			}

			if(!elev1failflag)
				elev1currentpass=true;
			if(!elev2failflag)
				elev2currentpass=true;
		}//endif
	}//endif


	//check intake current
	SmartDashboard::PutNumber("Intake 1 Current", pdp_curr[10][currentcounter]);
	SmartDashboard::PutNumber("Intake 2 Current", pdp_curr[9][currentcounter]);
	if(pdp_curr[10][currentcounter] != 0) {

		intakecounter++;
		if(intakecounter >= 9) {
			intakecounter = 0;
			intakereadytocheck=true;
		}

		if(intakereadytocheck) {
			for(int i = 0; i<9;i++) {
				if(pdp_curr[10][i] < intakelowerlimit)
					intake1failflag=true;
			}
			for(int i = 0; i<9;i++) {
				if(pdp_curr[9][i] < intakelowerlimit)
					intake2failflag=true;
			}

			if(!intake1failflag)
				intake1currentpass=true;
			if(!intake2failflag)
				intake2currentpass=true;
		}//endif
	}

	//checkLimelight Current
	if(limelightcheckready) {
		for(int i=0;i<9;i++) {
			if(pdp_curr[7][i]<0.01)
				limelightfailflag=true;
		}
		if(!limelightfailflag)
			limelightcurrentpass=true;
	}



	SmartDashboard::PutBoolean("Drive Left 1", l1currentpass);
	SmartDashboard::PutBoolean("Drive Left 2", l2currentpass);
	SmartDashboard::PutBoolean("Drive Left 3", l3currentpass);
	SmartDashboard::PutBoolean("Drive Right 1", r1currentpass);
	SmartDashboard::PutBoolean("Drive Right 2", r2currentpass);
	SmartDashboard::PutBoolean("Drive Right 3", r3currentpass);
	SmartDashboard::PutBoolean("Elevator 1", elev1currentpass);
	SmartDashboard::PutBoolean("Elevator 2", elev2currentpass);
	SmartDashboard::PutBoolean("Intake 1", intake1currentpass);
	SmartDashboard::PutBoolean("Intake 2", intake2currentpass);
	SmartDashboard::PutBoolean("LimeLight", limelightcurrentpass);


	//check drive encoders
	if(pdp_curr[0][currentcounter] > 0 && drivereadytocheck){
		if(Drivetrain::GetInstance()->getLeftDriveVelocity()>0)
			driveleftencoder=true;
	}
	SmartDashboard::PutBoolean("Drive Left Encoder", driveleftencoder);

	if(pdp_curr[15][currentcounter] > 0 && drivereadytocheck){
		if(Drivetrain::GetInstance()->getRightDriveVelocity()>0)
			driverightencoder=true;
	}
	SmartDashboard::PutBoolean("Drive Right Encoder", driverightencoder);

	//check elevator encoders
	if(pdp_curr[11][currentcounter] > 0 && elevreadytocheck){
		if(Elevator::GetInstance()->GetElevatorVelocity()>0)
			elevatorencoder=true;
	}
	SmartDashboard::PutBoolean("Elevator Encoder", elevatorencoder);
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

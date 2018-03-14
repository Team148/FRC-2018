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


	elev1currentpass=false;
	elev2currentpass=false;

	intake1failflag=false;
	intake2failflag=false;
	intake1currentpass=false;
	intake2currentpass=false;
	wranglercurrentpass=false;

	//table = NetworkTable::GetTable("LiveWindow/Ungrouped");
	std::cout <<"starting Check" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void CheckFunction::Execute() {

	//pdp_curr[16][currentcounter] = table->GetNumberArray("PowerDistributionPanel", llvm::ArrayRef<double>());
	//double pdp = table->GetNumberArray("PowerDistributionPanel", llvm::ArrayRef<double>());
	//check all currents
	for(int x=0;x<=15;x++) {
		pdp_curr[x][currentcounter]=Drivetrain::GetInstance()->pdp->GetCurrent(x);
		std::cout << x <<": "<< pdp_curr[x][currentcounter] << " ";
	}
	std::cout << std::endl;

	//Check Drive motor current
	SmartDashboard::PutNumber("Drive L1 Current", pdp_curr[0][currentcounter]);
	SmartDashboard::PutNumber("Drive L2 Current", pdp_curr[1][currentcounter]);
	SmartDashboard::PutNumber("Drive L3 Current", pdp_curr[2][currentcounter]);
	SmartDashboard::PutNumber("Drive R1 Current", pdp_curr[15][currentcounter]);
	SmartDashboard::PutNumber("Drive R2 Current", pdp_curr[14][currentcounter]);
	SmartDashboard::PutNumber("Drive R3 Current", pdp_curr[13][currentcounter]);

	//check l1
	if(!l1currentpass) {
		for(int i = 0; i<9;i++) {
			if(pdp_curr[0][i] > drivelowerlimit) {
				std::cout << "i:"<< i<< " cur:"<< pdp_curr[0][i];
				l1currentpass=true;
			}

		}
		std::cout<< std::endl;
	}

	//check l2
	if(!l2currentpass) {
		for(int i = 0; i<9;i++) {
			if(pdp_curr[1][i] > drivelowerlimit)
				l2currentpass=true;
		}
	}
	//check l3
	if(!l3currentpass) {
		for(int i = 0; i<9;i++) {
			if(pdp_curr[2][i] > drivelowerlimit)
				l3currentpass=true;
		}
	}
	//check r1
	if(!r1currentpass) {
		for(int i = 0; i<9;i++) {
			if(pdp_curr[15][i] > drivelowerlimit)
				r1currentpass=true;
		}
	}
	//check r2
	if(!r2currentpass) {
		for(int i = 0; i<9;i++) {
			if(pdp_curr[14][i] > drivelowerlimit)
				r2currentpass=true;
		}
	}

	//check r3
	if(!r3currentpass) {
		for(int i = 0; i<9;i++) {
			if(pdp_curr[13][i] > drivelowerlimit)
				r3currentpass=true;
		}
	}


	//check elevator current
	SmartDashboard::PutNumber("Elevator 1 Current", pdp_curr[11][currentcounter]);
	SmartDashboard::PutNumber("Elevator 2 Current", pdp_curr[5][currentcounter]);


	if(!elev1currentpass) {
		for(int i = 0; i<9;i++) {
			if(pdp_curr[11][i] > elevlowerlimit)
				elev1currentpass=true;
			}
	}

	if(!elev2currentpass) {
		for(int i = 0; i<9;i++) {
			if(pdp_curr[5][i] > elevlowerlimit)
				elev2currentpass=true;
		}
	}


	//check intake current
	SmartDashboard::PutNumber("Intake 1 Current", pdp_curr[10][currentcounter]);
	SmartDashboard::PutNumber("Intake 2 Current", pdp_curr[9][currentcounter]);


	if(!intake1currentpass) {
		for(int i = 0; i<9;i++) {
			if(pdp_curr[10][i] > intakelowerlimit)
				intake1currentpass=true;
		}
	}

	if(!intake2currentpass) {
		for(int i = 0; i<9;i++) {
			if(pdp_curr[9][i] > intakelowerlimit)
				intake2currentpass=true;
		}
	}

	//checkLimelight Current



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
	SmartDashboard::PutBoolean("Wrangler", wranglercurrentpass);



	//check drive encoders
	if(pdp_curr[0][currentcounter] > 0.0){
		if(Drivetrain::GetInstance()->getLeftDriveVelocity()>0)
			driveleftencoder=true;
	}
	SmartDashboard::PutBoolean("Drive Left Encoder", driveleftencoder);

	if(pdp_curr[15][currentcounter] > 0.0){
		if(Drivetrain::GetInstance()->getRightDriveVelocity()>0)
			driverightencoder=true;
	}
	SmartDashboard::PutBoolean("Drive Right Encoder", driverightencoder);

	//check elevator encoders
	if(pdp_curr[11][currentcounter] > 0.0){
		if(Elevator::GetInstance()->GetElevatorVelocity()>0)
			elevatorencoder=true;
	}
	SmartDashboard::PutBoolean("Elevator Encoder", elevatorencoder);

	//checkwrangler
	SmartDashboard::PutNumber("Wrangler Current", pdp_curr[6][currentcounter]);
	if(!wranglercurrentpass) {
			for(int i = 0; i<9;i++) {
				if(pdp_curr[6][i] < 0.1)
					wranglercurrentpass=true;
			}
		}


	currentcounter++;
	if(currentcounter >= 9) {
		currentcounter = 0;
	}
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

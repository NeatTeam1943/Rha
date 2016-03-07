#include "IntakeGet.h"

IntakeGet::IntakeGet(float p) {
	Requires(intake);
	this->power = p;
}

// Called just before this Command runs the first time
void IntakeGet::Initialize() {
	intake->SetPower(0);
}

// Called repeatedly when this Command is scheduled to run
void IntakeGet::Execute() {
	intake->SetPower(this->power);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeGet::IsFinished() {
	return intake->GetIsIn();
}

// Called once after isFinished returns true
void IntakeGet::End() {
	intake->SetPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeGet::Interrupted() {
	End();
}

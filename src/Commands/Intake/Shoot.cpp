#include "Shoot.h"
#include "Subsystems/Intake.h"

Shoot::Shoot(float p) {
	// Use Requires() here to declare subsystem dependencies
	Requires(intake);
	if (p < 0)
		this->p = p;
	else
		this->p = -p;
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
	intake->SetPower(0);
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	intake->SetPower(this->p);
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return !intake->GetIsIn();
}

// Called once after isFinished returns true
void Shoot::End() {
	intake->SetPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	End();
}

#include "IntakeJoystick.h"

IntakeJoystick::IntakeJoystick(Joystick *stick)
{
	Requires(intake);
	this->stick = stick;
}

// Called just before this Command runs the first time
void IntakeJoystick::Initialize()
{
	intake->SetPower(0);
}

// Called repeatedly when this Command is scheduled to run
void IntakeJoystick::Execute()
{
	intake->SetPower(this->stick->GetRawAxis(3) - this->stick->GetRawAxis(2));
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeJoystick::End()
{
	intake->SetPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeJoystick::Interrupted()
{
	End();
}

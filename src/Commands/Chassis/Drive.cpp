#include "Drive.h"

Drive::Drive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void Drive::Initialize()
{
	chassis->Drive(0,0);
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	chassis->Drive(0.3, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{
	End();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{

}

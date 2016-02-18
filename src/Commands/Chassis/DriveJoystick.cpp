#include "DriveJoystick.h"

DriveJoystick::DriveJoystick(Joystick *stick) {
	Requires(chassis);
	this->stick = stick;
}

// Called just before this Command runs the first time
void DriveJoystick::Initialize() {
	chassis->Drive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void DriveJoystick::Execute() {

	chassis->Drive(this->stick);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveJoystick::End() {
	chassis->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveJoystick::Interrupted() {
	End();
}

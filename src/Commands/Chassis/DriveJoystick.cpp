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
	if (this->stick->GetPOV(0) > -1) {
		switch (this->stick->GetPOV(0)) {
		case 0:
			chassis->Drive(0.5, 0);
			break;
		case 90:
			chassis->Drive(0, -0.5);
			break;
		case 180:
			chassis->Drive(-0.5, 0);
			break;
		case 270:
			chassis->Drive(0, 0.5);
			break;
		}
	} else {
		chassis->Drive(this->stick);
	}
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

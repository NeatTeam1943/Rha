#include <Commands/Trigo/TrigoJoystick.h>
#include <Joystick.h>
#include <Subsystems/Trigo.h>
#include <cstdbool>

TrigoJoystick::TrigoJoystick(Joystick *stick) {
	Requires(trigo);
	this->stick = stick;
}

// Called just before this Command runs the first time
void TrigoJoystick::Initialize() {
	trigo->SetPower(0);
}

void TrigoJoystick::SetWing(Trigo::TrigoSide side, float p) {
	if (!trigo->IsUp(side) && p > 0)
	{
		trigo->SetPower(p, side);
	}
	else if (!trigo->IsDown(side) && p < 0)
	{
		trigo->SetPower(p, side);
	}
	else {
		trigo->SetPower(0, side);
	}

}

// Called repeatedly when this Command is scheduled to run
void TrigoJoystick::Execute() {
	float p = this->stick->GetRawAxis(5);
	if (p > 0.2 || p < -0.2) {
		p *= -0.7;
		if (this->stick->GetRawButton(5) && !this->stick->GetRawButton(6)) { // only 'L' shoulder button is pressed
			SetWing(Trigo::TrigoSide::kLeft, p);
			trigo->SetPower(0, Trigo::TrigoSide::kRight);
		} else if (this->stick->GetRawButton(6)
				&& !this->stick->GetRawButton(5)) {	// only 'R' shoulder button is pressed, right is not up
			SetWing(Trigo::TrigoSide::kRight, p);
			trigo->SetPower(0, Trigo::TrigoSide::kLeft);
		} else {	// no shoulder button is pressed
			SetWing(Trigo::TrigoSide::kLeft, p);
			SetWing(Trigo::TrigoSide::kRight, p);
		}
	} else {
		trigo->SetPower(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TrigoJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TrigoJoystick::End() {
	trigo->SetPower(0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TrigoJoystick::Interrupted() {
	End();
}


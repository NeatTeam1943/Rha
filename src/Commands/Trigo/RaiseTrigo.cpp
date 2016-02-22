#include "RaiseTrigo.h"
#include "../../CommandBase.h"

RaiseTrigo::RaiseTrigo(float p, Trigo::TrigoSide s) {
	Requires(trigo);
	this->power = p;
	this->side = s;
}

// Called just before this Command runs the first time
void RaiseTrigo::Initialize() {
	trigo->SetPower(0);
}

// Called repeatedly when this Command is scheduled to run
void RaiseTrigo::Execute() {
	if (this->power > 0.1) {
		switch (this->side) {
		case Trigo::TrigoSide::kRight:
		case Trigo::TrigoSide::kLeft:
			if (!trigo->IsUp(side))
				trigo->SetPower(this->power, side);
			break;
		case Trigo::TrigoSide::kBoth:
			if (!trigo->IsUp(Trigo::TrigoSide::kLeft))
				trigo->SetPower(this->power, Trigo::TrigoSide::kLeft);
			if (!trigo->IsUp(Trigo::TrigoSide::kRight))
				trigo->SetPower(this->power, Trigo::TrigoSide::kRight);
			break;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseTrigo::IsFinished() {
	return trigo->IsUp();
}

// Called once after isFinished returns true
void RaiseTrigo::End() {
	trigo->SetPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseTrigo::Interrupted() {
	End();
}

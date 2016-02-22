#include "TrigoDefault.h"
#include "TrigoJoystick.h"
#include "RaiseTrigo.h"
TrigoDefault::TrigoDefault() {
	/*
	if (SmartDashboard::GetBoolean("Approve default raise", false)) {
		AddSequential(new RaiseTrigo(0.7));
	}*/
	AddSequential(new TrigoJoystick(CommandBase::oi->GetStick()));
}

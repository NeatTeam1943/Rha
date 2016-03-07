#include "TrigoDefault.h"
#include "TrigoJoystick.h"
#include "RaiseTrigo.h"
#include "Subsystems/Trigo.h"
TrigoDefault::TrigoDefault() {
	if (CommandBase::trigo->IsAutoRaise()) {
		AddSequential(new RaiseTrigo(0.7));
	}
	AddSequential(new TrigoJoystick(CommandBase::oi->GetStick()));
}

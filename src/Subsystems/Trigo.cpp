#include <CANTalon.h>
#include "Commands/Trigo/TrigoJoystick.h"
#include "Commands/Trigo/TrigoDefault.h"
#include "DigitalInput.h"
#include "OI.h"
#include "RobotMap.h"
#include "Subsystems/Trigo.h"

Trigo::Trigo() :
		Subsystem("Trigo") {
	this->isAutoRaise = new DigitalInput(RAISETRIGO_SWITCH);
	this->left = new TrigoWing(TRIGO_LEFT_MOTOR, TRIGO_LEFT_UPSWITCH,
			 TRIGO_LEFT_DOWNSWITCH);
	this->right = new TrigoWing(TRIGO_RIGHT_MOTOR, TRIGO_RIGHT_UPSWITCH,
			TRIGO_RIGHT_DOWNSWITCH);
	this->right->GetMotor()->SetInverted(true);
}

void Trigo::InitDefaultCommand() {
	//SetDefaultCommand(new TrigoJoystick(CommandBase::oi->GetStick()));
	SetDefaultCommand(new TrigoDefault());
}

void Trigo::SetPower(float p, TrigoSide s) {

	switch (s) {
	case kLeft:
		this->left->SetMotor(p);
		break;
	case kRight:
		this->right->SetMotor(p);
		break;
	case kBoth:
	default:
		this->left->SetMotor(p);
		this->right->SetMotor(p);
		break;
	}
}

bool Trigo::IsAutoRaise()
{
	return this->isAutoRaise->Get();
}

bool Trigo::IsUp(TrigoSide s) {
	switch (s) {
	case kLeft:
		return this->left->IsUp();
	case kRight:
		return this->right->IsUp();
	case kBoth:
	default:
		return this->left->IsUp() && this->right->IsUp();
	}
}

bool Trigo::IsDown(TrigoSide s) {
	switch (s) {
	case kLeft:
		return this->left->IsDown();
	case kRight:
		return this->right->IsDown();
	case kBoth:
	default:
		return this->left->IsDown() && this->right->IsDown();
	}

}

CANTalon* Trigo::GetMotor(TrigoSide s) {
	switch (s) {
	case kLeft:
		return this->left->GetMotor();
	case kRight:
		return this->right->GetMotor();
	case kBoth:
	default:
		return NULL;
	}
}

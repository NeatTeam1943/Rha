#include "Intake.h"
#include "../RobotMap.h"
#include "../Commands/Intake/IntakeJoystick.h"

Intake::Intake() :
		Subsystem("Intake")
{
	this->axis = new CANTalon(INTAKE_MOTOR);
}

void Intake::InitDefaultCommand()
{
	SetDefaultCommand(new IntakeJoystick(CommandBase::oi->GetStick()));
}

void Intake::SetPower(float p) {
	this->axis->Set(p);
}

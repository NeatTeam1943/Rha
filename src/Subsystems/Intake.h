#ifndef Intake_H
#define Intake_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	CANTalon *axis;

public:
	Intake();
	void InitDefaultCommand();
	void SetPower(float power);
};

#endif

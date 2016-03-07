#ifndef Intake_H
#define Intake_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	CANTalon *axis;
	DigitalInput *inSwitch;

public:
	Intake();
	void InitDefaultCommand();
	void SetPower(float power);
	bool GetIsIn();
};

#endif

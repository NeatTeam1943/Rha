#ifndef IntakeJoystick_H
#define IntakeJoystick_H

#include "../../CommandBase.h"
#include "WPILib.h"

class IntakeJoystick: public CommandBase
{
private:
	Joystick *stick;

public:
	IntakeJoystick(Joystick *stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

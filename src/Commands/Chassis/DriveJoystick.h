#ifndef DriveJoystick_H
#define DriveJoystick_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveJoystick: public CommandBase
{
private:
	Joystick *stick;

public:
	DriveJoystick(Joystick *stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

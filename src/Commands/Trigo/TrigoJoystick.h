#ifndef TrigoJoystick_H
#define TrigoJoystick_H

#include "../../CommandBase.h"
#include "WPILib.h"

class TrigoJoystick: public CommandBase
{
private:
	Joystick *stick;
public:
	TrigoJoystick(Joystick *stick);
	void SetWing(Trigo::TrigoSide side, float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{private:
	Joystick *stick;
	JoystickButton *buttons[10];

public:
	OI();
	Joystick* GetStick();
};

#endif

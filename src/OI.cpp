#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	this->stick = new Joystick(JOYSTICKPORT);
	for (int i = 0; i < 10; i++) {
		this->buttons[i] = new JoystickButton(this->stick, i+1);
	}
	//this->buttons[0]->WhenPressed(new ResetTrigo(0.6)); // Button 'A'
}


Joystick* OI::GetStick() {
	return this->stick;
}

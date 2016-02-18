#ifndef Chassis_H
#define Chassis_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem
{
private:
	RobotDrive *deino;

public:
	Chassis();
	void InitDefaultCommand();
	void Drive(float magnitude, float rotation);
	void DriveAccurate(float magnitude, float rotation);
	void Drive(Joystick *stick);
	void DriveTank(Joystick *stick);
	void DriveTank(float left,float right);
};

#endif

/*
 * TrigoWing.cpp
 *
 *  Created on: Feb 17, 2016
 *      Author: Neat Team
 */

#include <TrigoWing.h>

TrigoWing::TrigoWing(int mp, int up, int dp) {
	// TODO Auto-generated constructor stub
	this->motor = new CANTalon(mp);
	this->upSwitch = new DigitalInput(up);
	this->downSwitch = new DigitalInput(dp);
	this->motor->SetSafetyEnabled(false);
}
CANTalon* TrigoWing::GetMotor()
{
	return this->motor;
}
bool TrigoWing::IsUp()
{
	return this->upSwitch->Get();
}
bool TrigoWing::IsDown()
{
	return this->downSwitch->Get();
}
void TrigoWing::SetMotor(float p)
{
	this->motor->Set(p);
}

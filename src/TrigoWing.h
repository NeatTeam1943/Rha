/*
 * TrigoWing.h
 *
 *  Created on: Feb 17, 2016
 *      Author: Neat Team
 */

#ifndef SRC_TRIGOWING_H_
#define SRC_TRIGOWING_H_

#include "WPILib.h"

class TrigoWing {
private:
	CANTalon *motor;
	DigitalInput *upSwitch;
	DigitalInput *downSwitch;

public:
	TrigoWing(int motorPort, int upPort, int downPort);
	CANTalon *GetMotor();
	bool IsUp();
	bool IsDown();
	void SetMotor(float power);
};

#endif /* SRC_TRIGOWING_H_ */

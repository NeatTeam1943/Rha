#ifndef Trigo_H
#define Trigo_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../TrigoWing.h"

class Trigo: public Subsystem {
private:
	TrigoWing *left;
	TrigoWing *right;
	DigitalInput *isAutoRaise;
public:
	enum TrigoSide {
		kRight, kLeft, kBoth
	};
	Trigo();
	void InitDefaultCommand();
	bool IsAutoRaise();
	bool IsUp(TrigoSide side = kBoth);
	bool IsDown(TrigoSide side = kBoth);
	void SetPower(float power, TrigoSide side = kBoth);

	CANTalon* GetMotor(TrigoSide side);

};

#endif

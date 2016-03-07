#ifndef IntakeGet_H
#define IntakeGet_H

#include "../../CommandBase.h"
#include "WPILib.h"

class IntakeGet: public CommandBase
{
private:
	float power;
public:
	IntakeGet(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

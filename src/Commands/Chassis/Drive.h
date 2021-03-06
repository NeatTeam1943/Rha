#ifndef Drive_H
#define Drive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Drive: public CommandBase {
private:
float rot;
float mag;
public:
	Drive(float magnitude, float rotation);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

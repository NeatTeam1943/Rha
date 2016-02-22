#ifndef RaiseTrigo_H
#define RaiseTrigo_H

#include "../../CommandBase.h"
#include "WPILib.h"

class RaiseTrigo: public CommandBase
{
private:
	float power;
	Trigo::TrigoSide side;

public:
	RaiseTrigo(float power, Trigo::TrigoSide side = Trigo::TrigoSide::kBoth);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

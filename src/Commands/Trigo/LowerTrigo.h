#ifndef LowerTrigo_H
#define LowerTrigo_H

#include "../../CommandBase.h"
#include "WPILib.h"

class LowerTrigo: public CommandBase
{
private:
	float power;
	Trigo::TrigoSide side;

public:
	LowerTrigo(float power, Trigo::TrigoSide side = Trigo::TrigoSide::kBoth);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

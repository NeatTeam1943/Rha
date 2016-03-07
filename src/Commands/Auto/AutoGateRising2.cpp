#include "AutoGateRising2.h"
#include "../Trigo/RaiseTrigo.h"
#include "../Trigo/LowerTrigo.h"
#include "../Chassis/Drive.h"
#include "DriveNLower.h"

AutoGateRising2::AutoGateRising2()
{
	AddSequential(new Drive(0.2, 0), 1); //Reach to the Rampa
		AddSequential(new LowerTrigo(0.7, Trigo::TrigoSide::kBoth));
		AddSequential(new DriveNLower());

		AddSequential(new Drive(0, 0.6), 1.5); //turn 180 dig

		AddSequential(new Drive(0.2, 0), 1); //Reach to the Rampa
		AddSequential(new LowerTrigo(0.7, Trigo::TrigoSide::kBoth));
		AddSequential(new DriveNLower());

		AddSequential(new Drive(0, 0.6), 1.5); //turn 180 dig

		AddSequential(new Drive(0.2, 0), 1); //Reach to the Rampa
		AddSequential(new LowerTrigo(0.7, Trigo::TrigoSide::kBoth));
		AddSequential(new DriveNLower());
}

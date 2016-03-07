#include "DriveNLower.h"
#include "../Chassis/Drive.h"
#include "../Trigo/RaiseTrigo.h"
DriveNLower::DriveNLower()
{
	AddParallel(new Drive(0.5, 0), 2);
	AddParallel(new RaiseTrigo(0.4, Trigo::TrigoSide::kBoth)); //Over Ramp
}

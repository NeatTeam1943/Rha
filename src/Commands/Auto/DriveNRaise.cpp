#include "DriveNRaise.h"
#include "../Trigo/RaiseTrigo.h"
#include "../Chassis/Drive.h"

DriveNRaise::DriveNRaise() {
	AddParallel(new Drive(0.6, 0), 1.7);
	AddParallel(new RaiseTrigo(0.7));
}

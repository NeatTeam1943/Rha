#include "AutoLowBar2.h"
#include "../Chassis/Drive.h"

AutoLowBar2::AutoLowBar2() {
	// Start facing the back side, driving reverse from the beginning

	AddSequential(new Drive(-0.6, 0), 5.0); // drive reverse
	AddSequential(new Drive(0, 0.6), 1); // rotate right (hopefully 180dg)
	AddSequential(new Drive(-0.6, 0), 5.0);
}

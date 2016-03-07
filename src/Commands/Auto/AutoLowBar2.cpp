#include "AutoLowBar2.h"
#include "../Chassis/Drive.h"
#include "../Trigo/LowerTrigo.h"

AutoLowBar2::AutoLowBar2() {
	// Start facing the back side, driving reverse from the beginning

	AddSequential(new LowerTrigo(-0.7), 0.2);
	AddSequential(new Drive(-0.6, 0), 2.5); // drive reverse
	AddSequential(new Drive(0, 0.6), 1.22); // rotate left (hopefully 180dg)
	AddSequential(new Drive(-0.6, 0), 2.5);
	AddSequential(new Drive(0, -0.6), 1.22); // rotate right (hopefully 180dg)
	AddSequential(new Drive(-0.6, 0), 2.5);
}

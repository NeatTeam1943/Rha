#include "AutoSeeSaws2.h"
#include "../Chassis/Drive.h"

AutoSeeSaws2::AutoSeeSaws2() {
	AddSequential(new Drive(0.6, 0), 2);
}

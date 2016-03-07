#include "AutoSeeSaws2.h"
#include "../Chassis/Drive.h"
#include "../Trigo/LowerTrigo.h"
#include "../Auto/DriveNRaise.h"

AutoSeeSaws2::AutoSeeSaws2() {
	//Start with raised trigo
	//AddParallel(new RaiseTrigo(0.8,Trigo::TrigoSide::kBoth));

	AddSequential(new Drive(0.6, 0), 0.7); //Reaching to the SeeSaw
	AddSequential(new LowerTrigo(-0.7), 0.5);
	AddSequential(new DriveNRaise());
	AddSequential(new Drive(0, -0.6), 1.22); // rotate 180 deg


	AddSequential(new Drive(0.6, 0), 0.8); //Reaching to the SeeSaw
	AddSequential(new LowerTrigo(-0.7), 0.5);
	AddSequential(new DriveNRaise());
	AddSequential(new Drive(0, -0.6), 1.22); // rotate 180 deg

	AddSequential(new Drive(0.6, 0), 0.8); //Reaching to the SeeSaw
	AddSequential(new LowerTrigo(-0.7), 0.5);
	AddSequential(new DriveNRaise());

}
//2.5 sec total
//1.22 rotate 180deg

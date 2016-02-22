#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
OI *CommandBase::oi = NULL;
Chassis *CommandBase::chassis = NULL;
Intake *CommandBase::intake = NULL;
Trigo *CommandBase::trigo = NULL;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	oi = new OI();
	chassis = new Chassis();
	intake = new Intake();
	trigo = new Trigo();
}

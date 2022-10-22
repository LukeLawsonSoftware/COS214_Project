#include "Command.h"

Command::Command() {}

void Command::execute()
{
	// TODO - implement Command::execute
	throw "Not yet implemented";
}

Army *Command::getArmy()
{
	return army;
}

void Command::setArmy(Army *in)
{
	army = in;
}

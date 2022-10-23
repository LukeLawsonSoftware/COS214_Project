#include "Command.h"

Command::Command() {}

Army *Command::getArmy()
{
	return army;
}

void Command::setArmy(Army *in)
{
	army = in;
}

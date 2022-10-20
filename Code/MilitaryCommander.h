#ifndef MILITARYCOMMANDER_H
#define MILITARYCOMMANDER_H
#include "Command.h"
#include "WarTheatre.h"
#include "Transporter.h"
#include <string>

class MilitaryCommander
{

private:
	Command *raiseArmy;
	Command *enterTheatre;
	Command *changeStrategy;
	Command *attackTransport;

public:
	void changeStrategy();

	void setStrategy(std::string newStrategy);

	void enterTheatre();

	void setTheatreTarget(WarTheatre *theatreTarget);

	void attackTransport();

	void setTransportTarget(Transporter *transportTarget);
};

#endif

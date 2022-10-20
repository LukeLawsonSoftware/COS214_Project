#ifndef MOVEINTOTHEATRE_H
#define MOVEINTOTHEATRE_H
#include "Command.h"
#include "WarTheatre.h"

class MoveIntoTheatre : public Command
{

public:
	WarTheatre *theatre;

	void execute();
};

#endif

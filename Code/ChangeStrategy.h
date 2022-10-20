#ifndef CHANGESTRATEGY_H
#define CHANGESTRATEGY_H
#include "Command.h"
#include <string>

class ChangeStrategy : public Command
{

public:
	std::string newStrategy;

	void execute();
};

#endif

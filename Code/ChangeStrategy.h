#ifndef CHANGESTRATEGY_H
#define CHANGESTRATEGY_H
#include "Command.h"
#include <string>

class ChangeStrategy : public Command
{

public:
	ChangeStrategy();
	std::string newStrategy;
	/// @brief sets the strategy to be executed by the commmand pattern.
	/// @author Thomas Blendulf(u21446131)
	/// @param string containing state to be updated to.
	void setStrategy(std::string);

	/// @brief calls setStrategy in the stored Army.
	/// @author Thomas Blendulf(u21446131)
	void execute();
};

#endif

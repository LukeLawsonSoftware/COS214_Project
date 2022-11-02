#ifndef COMMAND_H
#define COMMAND_H

class Army;
class Command
{
protected:
	Army *army;

public:
	Command();
	/// @brief sets the army to be executed on.
	/// @author Thomas Blendulf(u21446131)
	/// @param Army containing army to be updated to.
	void setArmy(Army *);
	/// @brief returns the currently stored army.
	/// @author Thomas Blendulf(u21446131)
	/// @return Army*.
	Army *getArmy();
	virtual void execute() = 0;
};

#endif

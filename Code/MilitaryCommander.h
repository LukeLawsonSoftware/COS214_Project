#ifndef MILITARYCOMMANDER_H
#define MILITARYCOMMANDER_H
#include "ChangeStrategy.h"
#include "AttackTransport.h"
#include "MoveIntoTheatre.h"
#include "WarTheatre.h"
#include "Transporter.h"

#include <string>

class MilitaryCommander
{

private:
	MoveIntoTheatre *_enterTheatre;
	ChangeStrategy *_changeStrategy;
	AttackTransport *_attackTransport;

public:
	MilitaryCommander();
	/// @brief executes the changeStrategy Command.
	/// @author Thomas Blendulf(u21446131)
	void changeStrategy();
	/// @brief sets variables of the ChangeStrategy Command.
	/// @author Thomas Blendulf(u21446131)
	/// @param Army* the army to be set in the ChangeStrategy Command.
	/// @param String the string storing the state of the Command.
	void setStrategy(Army *army, std::string newStrategy);
	/// @brief executes the enterTheatre Command.
	/// @author Thomas Blendulf(u21446131)
	void enterTheatre();
	/// @brief sets variables of the enterTheatre Command.
	/// @author Thomas Blendulf(u21446131)
	/// @param Army* the army to be set in the enterTheatre Command.
	/// @param WarTheatre* the war theatre the army is to fight in.
	void setTheatreTarget(Army *army, WarTheatre *theatreTarget);
	/// @brief executes the enterTheatre Command.
	/// @author Thomas Blendulf(u21446131)
	void attackTransport();
	/// @brief sets variables of the attackTransport Command.
	/// @author Thomas Blendulf(u21446131)
	/// @param Army* the army to be set in the attackTransport Command.
	/// @param Transporter* the transport to be attacked.
	void setTransportTarget(Transporter *transportTarget, Army *army);
};

#endif

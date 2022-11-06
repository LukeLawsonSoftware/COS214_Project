#ifndef MILITARYCOMMANDER_H
#define MILITARYCOMMANDER_H
class ChangeStrategy;
class AttackTransport;
class MoveIntoTheatre;
class WarTheatre;
class Transporter;
class Army;

#include <string>
class Country;

/**
 * @class MilitaryCommander MilitaryCommander.h
 * 
 * This is one of the big components in the War. Each Country will make use of the military commander to issue different commands throughout the duration of the war.
 * The different commands which a commander can issue includes the following:
 * - change strategy: This command is issued when a Country either has the greater advantage in the war or when it realises that the enemy has the greater advantage.
 * - set strategy: This command will be issued when a country has decided to use a different strategy in the war.
 * - enter theatre: Issuing this command will allow the country to start participating in the war.
 * - set theatre target: This command is issued to order the country's army to attack/fight in a specific WarTheatre.
 * - attack transport: This command orders the country's army to attack an enemy's transport lines with the hope of destroying it to gain the upper hand in the war.
 * - set transport target: This command allows the country's army to attack a specific Country's transport lines.
 * 
 * The military commander is definitely a crucial component for a country because without a commander the country will not be able to instruct its army to attack/surrender.
 * 
 * @note A country can only have one military commander.
 * 
 */
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
	/// @warning The second argument must be a string value to specify a specific ArmyStrategy
	void setStrategy(Army *army, std::string newStrategy);
	/// @brief executes the enterTheatre Command.
	/// @author Thomas Blendulf(u21446131)
	void enterTheatre();
	/// @brief sets variables of the enterTheatre Command.
	/// @author Thomas Blendulf(u21446131)
	/// @param Army* the army to be set in the enterTheatre Command.
	/// @param WarTheatre* the war theatre the army is to fight in.
	/// @warning The second argument must be an existing WarTheatre in the current War
	void setTheatreTarget(Army *army, WarTheatre *theatreTarget);
	/// @brief executes the enterTheatre Command.
	/// @author Thomas Blendulf(u21446131)
	void attackTransport();
	/// @brief sets variables of the attackTransport Command.
	/// @author Thomas Blendulf(u21446131)
	/// @param Army* the army to be set in the attackTransport Command.
	/// @param Transporter* the transport to be attacked.
	void setTransportTarget(Country *transportTarget, Army *army);
};

#endif

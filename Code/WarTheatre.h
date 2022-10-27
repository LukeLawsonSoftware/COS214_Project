#ifndef WARTHEATRE_H
#define WARTHEATRE_H
#include "Army.h"
#include "NonCombatEntity.h"
#include <vector>

class WarTheatre
{

private:
	int contentionState;
	Army *armies;
	std::vector<NonCombatEntity *> medics;
	std::vector<NonCombatEntity *> civilians;
	std::string type;
	std::string name;

public:
	void applyTerrainBonus();

private:
	virtual void adjustDefence() = 0;

	virtual void adjustAttack() = 0;

public:
	void conflict();

	// needs to print something out if the army can't be added to the Theatre
	void addArmy(Army *newArmy);

	void replenishNonCombatEntities();

	std::string getType();
	std::string getName();
};

#endif

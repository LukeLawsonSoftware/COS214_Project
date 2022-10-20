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

public:
	void applyTerrainBonus();

private:
	virtual void adjustDefence() = 0;

	virtual void adjustAttack() = 0;

public:
	void conflict();

	void addArmy(Army *newArmy);

	void replenishNonCombatEntities();
};

#endif

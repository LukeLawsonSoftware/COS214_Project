#ifndef WARTHEATRE_H
#define WARTHEATRE_H
#include "Army.h"
#include "NonCombatEntity.h"
#include <vector>

class WarTheatre
{

private:
	int contentionState;					   // 0=no armies, 1=army from alliance1 only, 2=army from alliance2 only, 3=2 armies in contention (different alliances)
	Army *armies;							   // maybe make this an array. army[0] =from alliance1, army[1] from alliance2
	std::vector<NonCombatEntity *> *medics;	   // might need to be dynamically cast to getHealing
	std::vector<NonCombatEntity *> *civilians; // Almost entirely to be killed
	std::string type;						   // Land/Sea/Air
	std::string name;						   // ex: The Red Sea, or No Man's Land

	// A constructor is required for type, name and to initialise  array/vectors
	// Add a number of civilians and medics at instantiation

	// A destructor will also be necessary to delete the medics and civilians
public:
	void applyTerrainBonus(); // templateMethod (calls the two primitive operations)

private:
	// when altering the stats, make sure to alter the BattleStatistics* stats member of the army using the appropriate setters
	virtual void adjustDefence() = 0; // primitiveOperation

	virtual void adjustAttack() = 0; // primitiveOperation

public:
	// This is the main complicated method, please see WarTheatre.cpp for a description of the algorithm
	void conflict();

	// needs to print something out if the army can't be added to the Theatre
	// ie: if an army from alliance1 wants to join but there already is one
	// alternatively, you can make it so there are two vectors of armies (one for alliance1 and one for alliance2 and add that army to the appropriate vector)
	void addArmy(Army *newArmy);

	// call this at the end of the round to add a fixed number of civilains and medics each time
	void replenishNonCombatEntities();

	// basic getters
	std::string getType();
	std::string getName();
};

#endif

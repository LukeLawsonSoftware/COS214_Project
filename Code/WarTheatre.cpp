#include "WarTheatre.h"

void WarTheatre::applyTerrainBonus()
{
	// TODO - implement WarTheatre::applyTerrainBonus
	throw "Not yet implemented";
}

void WarTheatre::conflict() // one call of conflict() = 1 turn in the WarTheatre
{
	// Please note that you may need to add additional methods/attributes to Army/Country to implement this

	// btw remeber to add print statements so that a user can trace what is going on
	//  ALGORITHM (please feel free to adjust over time, this is a general guide)
	//  print "name is under contention/controlled by/empty"
	//  apply terrain bonus
	//  apply army->applyStrategyBonus
	// print a head-to-head summary (you can choose what is relevant)
	// make armies fight. Use some maths magic as well as the offense and defence stats to determine how much damage to do to morale
	// if you're feeling up to it, you can make other stats change during the fight too
	// Army's have ammo. BattleStatistics (probs easier) or the ammoSupply (harder) attributes can be used to control ammo. At the end of each round, each army needs to lose some ammo. If an army runs out of ammo, their morale becomes zero. You will likely need to make some changes to Army to implement this functionality
	//  if morale<=0, the army has 'died' (will need to print this and set Country's army to null)
	// make it so that we can't have a case where both armies die at the same time. pick a winner somehow
	//  surviving armies call recuperate (this uses the armys' medical supplies)
	//  medics use getHealing to 'heal' armies (healing an army is adding to morale)
	//  print "name is under contention/controlled by/empty"

	// TODO - implement WarTheatre::conflict
	throw "Not yet implemented";
}

void WarTheatre::addArmy(Army *newArmy)
{
	// TODO - implement WarTheatre::addArmy
	throw "Not yet implemented";
}

void WarTheatre::replenishNonCombatEntities()
{
	// TODO - implement WarTheatre::replenishNonCombatEntities
	throw "Not yet implemented";
}

int WarTheatre::getContentionState()
{
	return contentionState;
}

std::string WarTheatre::getType()
{
}
std::string WarTheatre::getName()
{
}

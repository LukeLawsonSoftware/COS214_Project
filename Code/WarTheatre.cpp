#include "WarTheatre.h"
#include "Civilian.h"
#include "Medic.h"
#include <ctime>
#include <cstdlib>

WarTheatre::WarTheatre(std::string Type, std::string Name)
{

	type = Type;
	name = Name;

	// Initialise armies array:
	for(int i =0; i < 2; i++)
	{
		armies[i] = NULL;
	}

	// Populate Civilian and Medic Vectors
	srand(time(0));

	int Civilians = rand() % 19 + 2;
	int refugees = Civilians/2;
	int citizen = Civilians - refugees;

	for(int i = 0; i < citizen; i++)
	{
		civilians->push_back(new Civilian("citizen"));
	}

	for(int i = 0; i < refugees; i++)
	{
		civilians->push_back(new Civilian("refugee"));
	}

	int Medics = rand() % 19 + 2 ;

	for(int i = 0; i < Medics; i++)
	{
		civilians->push_back(new Medic());
	}

}

WarTheatre::~WarTheatre()
{
	// A destructor will also be necessary to delete the medics and civilians

	if (medics != NULL)
	{
		 
    }

	if(civilians !=NULL)
	{

	}
}

void WarTheatre::applyTerrainBonus()
{
	// templateMethod (calls the two primitive operations)

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
	// needs to print something out if the army can't be added to the Theatre
	// ie: if an army from alliance1 wants to join but there already is one
	// alternatively, you can make it so there are two vectors of armies 
	//  (one for alliance1 and one for alliance2 and add that army to the appropriate vector)

	
}

void WarTheatre::replenishNonCombatEntities()
{
	// call this at the end of the round to add a fixed number of civilains and medics each time

	int Medics = 8;
	int Refugees = 8;
	int Citizens = 6;

	for(int i = 0; i < Citizens; i++)
	{
		civilians->push_back(new Civilian("citizen"));
	}

	for(int i = 0; i < Refugees; i++)
	{
		civilians->push_back(new Civilian("refugee"));
	}

	int Medics = rand() % 19 + 2 ;

	for(int i = 0; i < Medics; i++)
	{
		civilians->push_back(new Medic());
	}


}

std::string WarTheatre::getType()
{
	return type;
}

std::string WarTheatre::getName()
{
	return name;
}


Army* WarTheatre::getArmies()
{
	return *armies;
}
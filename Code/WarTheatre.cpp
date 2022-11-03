#include "WarTheatre.h"
#include "Civilian.h"
#include "Medic.h"
#include "Country.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

WarTheatre::WarTheatre(std::string Type, std::string Name)
{

	type = Type;
	name = Name;
	contentionState = 0;

	// Initialise armies array:
	for (int i = 0; i < 2; i++)
	{
		armies[i] = NULL;
	}

	// Populate Civilian and Medic Vectors
	srand(time(0));

	int Civilians = rand() % 19 + 2;
	int refugees = Civilians / 2;
	int citizen = Civilians - refugees;

	for (int i = 0; i < citizen; i++)
	{
		civilians->push_back(new Civilian("citizen"));
	}

	for (int i = 0; i < refugees; i++)
	{
		civilians->push_back(new Civilian("refugee"));
	}

	int Medics = rand() % 19 + 2;

	for (int i = 0; i < Medics; i++)
	{
		civilians->push_back(new Medic());
	}
}

WarTheatre::~WarTheatre()
{
	// A destructor will also be necessary to delete the medics and civilians

	if (medics != NULL)
	{
		for (auto m : *medics)
		{
			delete m;
		}

		delete medics;
		medics = NULL;
	}

	if (civilians != NULL)
	{
		for (auto c : *civilians)
		{
			delete c;
		}

		delete civilians;
		civilians = NULL;
	}
}

void WarTheatre::applyTerrainBonus()
{
	// templateMethod (calls the two primitive operations)
	this->adjustAttack();
	this->adjustDefence();
}

void WarTheatre::conflict() // one call of conflict() = 1 turn in the WarTheatre
{
	
	// Make sure there are two armies in this theatre:
	if(contentionState == 3) // 2 Armies are present - conflict is possible
	{
		std::cout << "The " + armies[0]->getName() + " army is at battle with the " + armies[1]->getName() + " army in " + name + " war theatre!" << std::endl;

		//  apply terrain bonus
		applyTerrainBonus();

		//  apply army->applyStrategyBonus
		armies[0]->applyStrategyBonus();
		armies[1]->applyStrategyBonus();

		// print a head-to-head summary using the armies battlestatistics
		BattleStatistics* StatsArmy1 = armies[0]->getBattleStatistics();
		BattleStatistics* StatsArmy2 = armies[1]->getBattleStatistics();

		std::cout << "===================================== Battle Statistics : " + name + " =====================================" << std::endl;
		
		// make armies fight. Use some maths magic as well as the offense and defence stats to determine how much damage to do to morale
		int moraleArmy1 = 0;
		int moraleArmy2 = 0;

		// Army's have ammo. BattleStatistics (probs easier) or the ammoSupply (harder) attributes can be used to control ammo. At the end of each round,
		//	each army needs to lose some ammo. If an army runs out of ammo, their morale becomes zero. You will likely need to make some changes to Army to implement this functionality
		//  if morale<=0, the army has 'died' (will need to print this and set Country's army to null)
		if (moraleArmy1 <= 0)
		{
			std::cout << armies[0]->getName() + " army was overcome by " + armies[1]->getName() ;
			armies[0] = NULL;
			contentionState = 2;
		}
		else if (moraleArmy2 <= 0)
		{
			std::cout << armies[1]->getName() + " army was overcome by " + armies[0]->getName() ;
			armies[1] = NULL;
			contentionState = 1;
		}

		//  surviving armies call recuperate (this uses the armys' medical supplies)
		if (contentionState == 3) // both armies still alive after this round
		{
			armies[0]->recuperate();
			armies[1]->recuperate();
		}
		else if(contentionState == 1) // Army from allience 1 is left
		{
			armies[0]->recuperate();
		}
		else if(contentionState == 2) // Army from allience 2 is left
		{
			armies[1]->recuperate();
		}

		//  medics use getHealing to 'heal' armies (healing an army is adding to morale)
		
	}
	
	if (contentionState == 1) // Only an army from alliance 1 is present
	{
		std::cout << "The " + armies[0]->getName() + " army from allience 1 is controlling the "+ name +" war theatre!" << std::endl;
	}
	else if (contentionState == 2) // Only an army from alliance 2 is present
	{
		std::cout << "The " + armies[1]->getName() + " army from allience 2 is controlling the "+ name +" war theatre!" << std::endl;
	}
	else if (contentionState == 0)// No armies in the war theatre yet
	{
		std::cout << "The " + name + " war theatre is peaceful." << std::endl;
	}
	else // 2 armies are present in the war theatre
	{
		std::cout << "The " + armies[0]->getName() + " army is at battle with the " + armies[1]->getName() + " army in " + name + " war theatre!" << std::endl;
	}

}

void WarTheatre::addArmy(Army *newArmy)
{

	std::string NewArmyName = newArmy->getName();
	int alliance = 0;

	// Determine alliance

	for (int i = 0; i < Country::alliance1.size(); i++)
	{
		if (Country::alliance1.at(i)->getName() == newArmy->getName())
		{
			alliance = 1;
			break;
		}
	}

	for (int i = 0; i < Country::alliance2.size(); i++)
	{
		if (Country::alliance2.at(i)->getName() == newArmy->getName())
		{
			alliance = 2;
			break;
		}
	}

	// Add army
	if (contentionState == 0) // Contentionstate = 0 -> no armies has been added :
	{
		if (alliance == 1)
		{
			armies[0] = newArmy;
			contentionState = 1;
		}
		else if (alliance == 2)
		{
			armies[1] = newArmy;
			contentionState = 2;
		}
	}
	else if (contentionState == 1) // Contentionstate = 1 -> army from alliance1 only :
	{
		if (alliance == 1)
		{
			std::cout << newArmy->getName() + " Army cannot be added to " + name + "  " + type + " war theatre -> army from alliance 1 already arrived!" << std::endl;
		}
		else if (alliance == 2)
		{
			armies[1] = newArmy;
			contentionState = 3;
		}
	}
	else if (contentionState == 2) // Contentionstate = 2 -> army from alliance2 only :
	{
		if (alliance == 2)
		{
			std::cout << newArmy->getName() + " Army cannot be added to " + name + "  " + type + " war theatre -> army from alliance 2 already arrived!" << std::endl;
		}
		else if (alliance == 1)
		{
			armies[0] = newArmy;
			contentionState = 3;
		}
	}
	else if (contentionState == 3) // Contentionstate = 3 ->  armies in contention (different alliances) :
	{
		std::cout << newArmy->getName() + " Army cannot be added to " + name + "  " + type + " war theatre -> 2 armies are already at battle!" << std::endl;
	}
}

void WarTheatre::replenishNonCombatEntities()
{
	// call this at the end of the round to add a fixed number of civilains and medics each time

	int Medics = 8;
	int Refugees = 8;
	int Citizens = 6;

	for (int i = 0; i < Citizens; i++)
	{
		civilians->push_back(new Civilian("citizen"));
	}

	for (int i = 0; i < Refugees; i++)
	{
		civilians->push_back(new Civilian("refugee"));
	}

	for (int i = 0; i < Medics; i++)
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

Army *WarTheatre::getArmies()
{
	return *armies;
}
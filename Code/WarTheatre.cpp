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

	this->civilians = new std::vector<NonCombatEntity *>();
	this->medics = new std::vector<NonCombatEntity *>();

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
	if (contentionState == 3) // 2 Armies are present - conflict is possible
	{
		std::cout << "\033[1;34m";
		std::cout << "The " + armies[0]->getName() + " army is at battle with the " + armies[1]->getName() + " army in " + name + " war theatre!" << std::endl;
		std::cout << "\033[0m";
		//  apply terrain bonus
		applyTerrainBonus();

		//  apply army->applyStrategyBonus
		armies[0]->applyStrategyBonus();
		armies[1]->applyStrategyBonus();

		// print a head-to-head summary using the armies battlestatistics
		BattleStatistics *StatsArmy1 = armies[0]->getBattleStatistics();
		BattleStatistics *StatsArmy2 = armies[1]->getBattleStatistics();

		std::cout << "\033[;34m";
		std::cout << "===================================== Battle Statistics : " + name + " =====================================" << std::endl;
		std::cout << std::endl;

		std::cout << "Alliance 1     : " + armies[0]->getName() + "         ==        Alliance 2     : " + armies[1]->getName() << std::endl;
		std::cout << "Air-Attack     : " + std::to_string(StatsArmy1->getAirAttack()) + "           ==         Air-Attack     : " + std::to_string(StatsArmy2->getAirAttack()) << std::endl;
		std::cout << "Air-Defense    : " + std::to_string(StatsArmy1->getAirDefence()) + "           ==         Air-Defense    : " + std::to_string(StatsArmy2->getAirDefence()) << std::endl;
		std::cout << "Land-Attack    : " + std::to_string(StatsArmy1->getLandAttack()) + "           ==         Land-Attack    : " + std::to_string(StatsArmy2->getLandAttack()) << std::endl;
		std::cout << "Land-Defense   : " + std::to_string(StatsArmy1->getLandDefence()) + "           ==         Land-Defense   : " + std::to_string(StatsArmy2->getLandDefence()) << std::endl;
		std::cout << "Sea-Attack     : " + std::to_string(StatsArmy1->getSeaAttack()) + "           ==         Sea-Attack     : " + std::to_string(StatsArmy2->getSeaAttack()) << std::endl;
		std::cout << "Sea-Defense    : " + std::to_string(StatsArmy1->getSeaDefence()) + "           ==         Sea-Defense    : " + std::to_string(StatsArmy2->getSeaDefence()) << std::endl;
		std::cout << "Morale         : " + std::to_string(StatsArmy1->getMorale()) + "           ==         Morale         : " + std::to_string(StatsArmy2->getMorale()) << std::endl;
		std::cout << "Available Ammo : " + std::to_string(StatsArmy1->getAvailableAmmo()) + "           ==         Available Ammo : " + std::to_string(StatsArmy2->getAvailableAmmo()) << std::endl;
		std::cout << "Medical        : " + std::to_string(StatsArmy1->getMedical()) + "           ==         Medical        : " + std::to_string(StatsArmy2->getMedical()) << std::endl;

		std::cout << std::endl;
		std::cout << "=============================================== " + name + " ===============================================" << std::endl;
		std::cout << "\033[0m";
		// make armies fight. Use some maths magic as well as the offense and defence stats to determine how much
		//    damage to do to morale
		int moraleArmy1 = StatsArmy1->getMorale();
		int moraleArmy2 = StatsArmy2->getMorale();

		int AttackArmy1 = StatsArmy1->getAirAttack() + StatsArmy1->getLandAttack() + StatsArmy1->getSeaAttack();
		int AttackArmy2 = StatsArmy2->getAirAttack() + StatsArmy2->getLandAttack() + StatsArmy2->getSeaAttack();

		int DefenseArmy1 = StatsArmy1->getAirDefence() + StatsArmy1->getAirDefence() + StatsArmy1->getAirDefence();
		int DefenseArmy2 = StatsArmy2->getAirDefence() + StatsArmy2->getAirDefence() + StatsArmy2->getAirDefence();

		int differenceArmy1 = AttackArmy1 - DefenseArmy1;
		int differenceArmy2 = AttackArmy2 - DefenseArmy2;

		// army 1 attack army 2
		// if differenceArmy1 == 0 : army 1 cannot do anything to army 2
		if (differenceArmy1 > 0)
		{
			moraleArmy2 = moraleArmy2 - (differenceArmy1 * 2);
		}
		else if (differenceArmy1 < 0)
		{
			moraleArmy2 = moraleArmy2 - (differenceArmy1 * (-1.4));
		}

		// army 2 attack army 1
		// if differenceArmy2 == 0 : army 2 cannot do anything to army 1
		if (differenceArmy2 > 0)
		{
			moraleArmy1 = moraleArmy1 - (differenceArmy2 * 2);
		}
		else if (differenceArmy1 < 0)
		{
			moraleArmy1 = moraleArmy1 - (differenceArmy2 * (-1.4));
		}

		// Update the Morale statistics
		StatsArmy1->setMorale(moraleArmy1);
		StatsArmy2->setMorale(moraleArmy2);

		// Army's have ammo.
		// BattleStatistics attributes are used to control ammo.
		int AmoArmy1 = StatsArmy1->getAvailableAmmo();
		int AmoArmy2 = StatsArmy2->getAvailableAmmo();

		// At the end of each round,each army needs to lose some ammo.
		if (moraleArmy1 > 0)
		{
			AmoArmy1 = AmoArmy1 - 20;
			StatsArmy1->setAvailableAmmo(AmoArmy1);
		}

		if (moraleArmy2 > 0)
		{
			AmoArmy2 = AmoArmy2 - 20;
			StatsArmy2->setAvailableAmmo(AmoArmy2);
		}

		// If an army runs out of ammo, their morale becomes zero.
		if (AmoArmy1 == 0)
		{
			moraleArmy1 = 0;
			StatsArmy1->setMorale(0);
		}
		else if (AmoArmy2 == 0)
		{
			moraleArmy2 = 0;
			StatsArmy2->setMorale(0);
		}

		//  if morale<=0, the army has 'died' (will need to print this and set Country's army to null)
		if (moraleArmy1 <= 0)
		{
			std::cout << "\033[;31m";
			std::cout << armies[0]->getName() + " army was overcome by " + armies[1]->getName();
			armies[0] = NULL;
			contentionState = 2;
			std::cout << "\033[0m";
		}
		else if (moraleArmy2 <= 0)
		{
			std::cout << "\033[;32m";
			std::cout << armies[1]->getName() + " army was overcome by " + armies[0]->getName();
			armies[1] = NULL;
			contentionState = 1;
			std::cout << "\033[0m";
		}

		//  surviving armies call recuperate (this uses the armys' medical supplies)
		if (contentionState == 3) // both armies still alive after this round
		{
			armies[0]->recuperate();
			armies[1]->recuperate();
		}
		else if (contentionState == 1) // Army from alliance 1 is left
		{
			armies[0]->recuperate();
		}
		else if (contentionState == 2) // Army from alliance 2 is left
		{
			armies[1]->recuperate();
		}

		//  medics use getHealing to 'heal' armies (healing an army is adding to morale)
		// Dynamic casting
		std::vector<Medic *> *_medics;
		for (int i = 0; i < medics->size(); i++)
		{
			_medics->push_back(dynamic_cast<Medic *>(medics->at(i)));
		}

		for (int i = 0; i < medics->size(); i++)
		{
			if (contentionState == 3)
			{
				moraleArmy1 = moraleArmy1 + _medics->at(i)->getHealing();
				moraleArmy2 = moraleArmy2 + _medics->at(i)->getHealing();
			}
			else if (contentionState == 1)
			{
				moraleArmy1 = moraleArmy1 + _medics->at(i)->getHealing();
			}
			else if (contentionState == 2)
			{
				moraleArmy2 = moraleArmy2 + _medics->at(i)->getHealing();
			}
		}

		replenishNonCombatEntities();
	}

	if (contentionState == 1) // Only an army from alliance 1 is present
	{
		std::cout << "\033[;32m";
		std::cout << "The " + armies[0]->getName() + " army from alliance 1 is controlling " + name + " war theatre!" << std::endl;
		std::cout << "\033[0m";
	}
	else if (contentionState == 2) // Only an army from alliance 2 is present
	{
		std::cout << "\033[;31m";
		std::cout << "The " + armies[1]->getName() + " army from alliance 2 is controlling " + name + " war theatre!" << std::endl;
		std::cout << "\033[0m";
	}
	else if (contentionState == 0) // No armies in the war theatre yet
	{
		std::cout << "\033[;34m";
		std::cout << name + " war theatre is peaceful." << std::endl;
		std::cout << "\033[0m";
	}
	else // 2 armies are present in the war theatre
	{
		std::cout << "\033[1;34m";
		std::cout << "The " + armies[0]->getName() + " army is at battle with the " + armies[1]->getName() + " army in " + name + " war theatre!" << std::endl;
		std::cout << "\033[0m";
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
			newArmy->makeDeployed();
			contentionState = 1;
		}
		else if (alliance == 2)
		{
			armies[1] = newArmy;
			newArmy->makeDeployed();
			contentionState = 2;
		}
	}
	else if (contentionState == 1) // Contentionstate = 1 -> army from alliance1 only :
	{
		if (alliance == 1)
		{
			std::cout << "\033[;32m";
			std::cout << newArmy->getName() + " Army cannot be added to " + name + "  " + type + " war theatre -> army from alliance 1 already arrived!" << std::endl;
			std::cout << "\033[;0m";
		}
		else if (alliance == 2)
		{
			armies[1] = newArmy;
			newArmy->makeDeployed();
			contentionState = 3;
		}
	}
	else if (contentionState == 2) // Contentionstate = 2 -> army from alliance2 only :
	{
		if (alliance == 2)
		{
			std::cout << "\033[;31m";
			std::cout << newArmy->getName() + " Army cannot be added to " + name + "  " + type + " war theatre -> army from alliance 2 already arrived!" << std::endl;
			std::cout << "\033[;0m";
		}
		else if (alliance == 1)
		{
			armies[0] = newArmy;
			newArmy->makeDeployed();
			contentionState = 3;
		}
	}
	else if (contentionState == 3) // Contentionstate = 3 ->  armies in contention (different alliances) :
	{
		std::cout << "\033[;34m";
		std::cout << newArmy->getName() + " Army cannot be added to " + name + "  " + type + " war theatre -> 2 armies are already at battle!" << std::endl;
		std::cout << "\033[;0m";
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

int WarTheatre::getContentionState()
{
	return contentionState;
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
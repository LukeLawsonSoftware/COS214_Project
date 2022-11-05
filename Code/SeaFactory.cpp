#include "SeaFactory.h"
// #include "UnitFactory.h"
#include "SeaVehicle.h"
#include "SeaUnit.h"

SeaFactory::SeaFactory(double budget, int level, std::string type)
	: UnitFactory(budget, level, type) {}

ArmyComponent *SeaFactory::createVehicle()
{
	srand((unsigned)time(0));				 // to generate a different value each time
	int cost = (double)(18 + (rand() % 25)); // random number between 18 and 25 (25 excluded)

	int costAfterProduction = cost + totalSpent;

	if (costAfterProduction > getBudget())
	{
		std::cout << "NOTE: FACTORY BUDGET REACHED." << std::endl;
		return nullptr;
	}
	else
	{
		//	std::cout << "NOTE: SEA FACTORY STILL ABLE TO CREATE MORE VEHICLES." << std::endl;
		totalSpent += costAfterProduction;
	}
	return new SeaVehicle(determineActualLevel());
}

ArmyComponent *SeaFactory::createSoldier()
{
	srand((unsigned)time(0));				 // to generate a different value each time
	int cost = (double)(10 + (rand() % 15)); // random number between 10 and 15 (15 excluded) {SOLDIER COST KEPT THE SAME AS THE OTHER SOLDIERS}

	int costAfterProduction = cost + totalSpent;

	if (costAfterProduction > getBudget())
	{
		std::cout << "NOTE: FACTORY BUDGET REACHED." << std::endl;
		return nullptr;
	}
	else
	{
		//	std::cout << "NOTE: SEA FACTORY STILL ABLE TO CREATE MORE SOLDIERS." << std::endl;
		totalSpent += costAfterProduction;
	}
	return new SeaUnit(determineActualLevel());
}

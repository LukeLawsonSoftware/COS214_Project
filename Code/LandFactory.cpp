#include "LandFactory.h"
// #include "UnitFactory.h"
#include "LandVehicle.h"
#include "LandUnit.h"

LandFactory::LandFactory(double budget, int level, std::string type)
	: UnitFactory(budget, level, type) {}

ArmyComponent *LandFactory::createVehicle()
{
	srand((unsigned)time(0));				 // to generate a different value each time
	int cost = (double)(15 + (rand() % 21)); // random number between 15 and 21 (21 excluded)

	int costAfterProduction = cost + totalSpent;

	if (costAfterProduction > getBudget())
	{
		std::cout << "NOTE: CANNOT CREATE A VEHICLE DUE TO THE LAND FACTORY'S BUDGET THAT HAS BEEN REACHED." << std::endl;
		return nullptr;
	}
	else
	{
		std::cout << "NOTE: LAND FACTORY STILL ABLE TO CREATE MORE VEHICLES." << std::endl;
		totalSpent += costAfterProduction;
	}
	return new LandVehicle(determineActualLevel());
}

ArmyComponent *LandFactory::createSoldier()
{
	srand((unsigned)time(0));				 // to generate a different value each time
	int cost = (double)(10 + (rand() % 15)); // random number between 5 and 15 (15 excluded)

	int costAfterProduction = cost + totalSpent;

	if (costAfterProduction > getBudget())
	{
		std::cout << "NOTE: CANNOT CREATE A SOLDIER DUE TO THE LAND FACTORY'S BUDGET THAT HAS BEEN REACHED." << std::endl;
		return nullptr;
	}
	else
	{
		std::cout << "NOTE: LAND FACTORY STILL ABLE TO CREATE MORE SOLDIERS." << std::endl;
		totalSpent += costAfterProduction;
	}
	return new LandUnit(determineActualLevel());
}

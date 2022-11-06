#include "LandFactory.h"
// #include "UnitFactory.h"
#include "LandVehicle.h"
#include "LandUnit.h"

LandFactory::LandFactory(double budget, int level, std::string type)
	: UnitFactory(budget, level, type) {}

ArmyComponent *LandFactory::createVehicle()
{
	static int seeder = 1718191;
	seeder += 927;
	srand((unsigned)time(0) + seeder);		 // to generate a different value each time
	int cost = (double)(15 + (rand() % 21)); // random number between 15 and 21 (21 excluded)

	int costAfterProduction = cost + totalSpent;
	//	std::cout << "Cost: " << cost << " Total so far: " << costAfterProduction << std::endl;

	if (costAfterProduction > getBudget())
	{
		std::cout << "\033[;33mNOTE: FACTORY BUDGET REACHED.\033[0m" << std::endl;
		return nullptr;
	}
	else
	{
		//	std::cout << "NOTE: LAND FACTORY STILL ABLE TO CREATE MORE VEHICLES." << std::endl;
		totalSpent += cost;
	}
	return new LandVehicle(determineActualLevel());
}

ArmyComponent *LandFactory::createSoldier()
{
	static int seeder = 3777;
	seeder += 9898;
	srand((unsigned)time(0) + seeder);		 // to generate a different value each time
	int cost = (double)(10 + (rand() % 15)); // random number between 5 and 15 (15 excluded)

	int costAfterProduction = cost + totalSpent;
	// std::cout << "Cost: " << cost << " Total so far: " << costAfterProduction << std::endl;
	if (costAfterProduction > getBudget())
	{
		std::cout << "\033[;33mNOTE: FACTORY BUDGET REACHED.\033[0m" << std::endl;
		return nullptr;
	}
	else
	{
		// std::cout << "NOTE: LAND FACTORY STILL ABLE TO CREATE MORE SOLDIERS." << std::endl;
		totalSpent += cost;
	}
	return new LandUnit(determineActualLevel());
}

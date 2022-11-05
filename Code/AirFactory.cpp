#include "AirFactory.h"
// #include "UnitFactory.h"
#include "AirVehicle.h"
#include "AirUnit.h"

AirFactory::AirFactory(double budget, int level, std::string type)
	: UnitFactory(budget, level, type) {}

ArmyComponent *AirFactory::createVehicle()
{
	static int seeder = 123735;
	seeder += 862748;
	srand((unsigned)time(0) + seeder);		 // to generate a different value each time
	int cost = (double)(21 + (rand() % 26)); // random number between 21 and 26 (26 excluded)

	int costAfterProduction = cost + totalSpent;

	if (costAfterProduction > getBudget())
	{
		std::cout << "\033[;33mNOTE: FACTORY BUDGET REACHED.\033[0m" << std::endl;
		return nullptr;
	}
	else
	{
		// std::cout << "NOTE: AIR FACTORY STILL ABLE TO CREATE MORE VEHICLES." << std::endl;
		totalSpent += costAfterProduction;
	}
	return new AirVehicle(determineActualLevel());
}

ArmyComponent *AirFactory::createSoldier()
{
	static int seeder = 462346;
	seeder += 3256426;
	srand((unsigned)time(0) + seeder);		 // to generate a different value each time
	int cost = (double)(15 + (rand() % 21)); // random number between 15 and 21 (21 excluded) {COST FOR AIR SOLDIERS KEPT THE SAME FOR OTHER SOLDIERS}

	int costAfterProduction = cost + totalSpent;

	if (costAfterProduction > getBudget())
	{
		std::cout << "\033[;33mNOTE: FACTORY BUDGET REACHED.\033[0m" << std::endl;
		return nullptr;
	}
	else
	{
		// std::cout << "NOTE: AIR FACTORY STILL ABLE TO CREATE MORE SOLDIERS." << std::endl;
		totalSpent += costAfterProduction;
	}
	return new AirUnit(determineActualLevel());
}

#include "AmmoFactory.h"
// #include "SupplyFactory.h"
#include "AmmoSupply.h"

AmmoFactory ::AmmoFactory(int budget, std::string type) : SupplyFactory(budget, type){};

Supply *AmmoFactory::makeSupply(int quantity)
{
	// TODO - implement AmmoFactory::makeSupply

	static int seeder = 4352525;
	seeder += 346457;
	srand((unsigned)time(0) + seeder);	   // to generate a different value each time
	int cost = (double)(2 + (rand() % 5)); // random number between 2 and 4

	int totalToBeProduced = cost * quantity;

	int costAfterProduction = totalToBeProduced + totalSpent;

	if (costAfterProduction >= getBudget())
	{
		// run loop to get the maximumm quantity we can produce
		int counter = 1;
		int possibleAmount = 0; // the maximum amount we will be able to spend
		while (counter <= quantity)
		{
			possibleAmount = cost * counter;
			if (possibleAmount > getBudget())
			{
				quantity = counter - 1;
				std::cout << "\033[;33mNOTE: FACTORY BUDGET REACHED.\033[0m" << std::endl;
				break;
			}
			else if (possibleAmount == getBudget())
			{
				quantity = counter;
				std::cout << "\033[;33mNOTE: FACTORY BUDGET REACHED.\033[0m" << std::endl;
				break;
			}

			counter++;
		}

		totalSpent += possibleAmount;
	}
	else
	{
		// std::cout << "NOTE: AMMO FACTORY STILL ABLE TO PRODUCE MORE SUPPLIES." << std::endl;
		totalSpent += costAfterProduction;
	}

	return new AmmoSupply(getLevel(), quantity);

	// throw "Not yet implemented";
}

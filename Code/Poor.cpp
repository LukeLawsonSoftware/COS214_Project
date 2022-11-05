#include "Poor.h"
#include "Country.h"
#include <ctime>
#include <cstdlib>
#include "Army.h"

int Poor::mySeed = 3857256;

int Poor::decideMyTurn(Country *country)
{
	mySeed += mySeed * 1.2;

	int Decision = 0;
	bool Possible = false;
	bool Possibilities[10];

	// Initialize every index as false
	for (int i = 0; i < 10; i++)
	{
		Possibilities[i] = false;
	}

	// Possible decisions:
	// 1. formAlliance (if not already in alliance1 or alliance2 ie: in neutral)
	Possibilities[0] = true;
	if (Country::neutral.size() == 0)
	{
		Possibilities[0] = false;
	}

	// for (int i = 0; i < Country::neutral.size(); i++)
	//{
	//	if (Country::neutral.at(i)->getName() == country->getName())
	//	{
	//		Possibilities[0] = true;
	//  std::cout << country->getName() << " thinks they can form an alliance" << std::endl;
	//		break;
	//	}
	//}

	// 2. raiseArmy
	if (country->getArmy() != NULL)
	{
		Possibilities[1] = false;
	}
	else
	{
		Possibilities[1] = true;
	}

	// 3. upgradeUnitFactory = not possible
	Possibilities[2] = false;

	// 4. upgradeSupplyFactory = not possible
	Possibilities[3] = false;

	// 5, 6, 7 require there to be an army alreayd
	//  5. enterArmyIntoTheatre
	//  6. changeArmyStrategy
	//  7. attackTransport
	if (country->getArmy() == NULL)
	{
		Possibilities[4] = false;
		Possibilities[5] = false;
		Possibilities[6] = false;

		// 9. sendSupplies
		Possibilities[8] = false;
	}
	else
	{
		Possibilities[4] = true;
		Possibilities[5] = country->getArmy()->armyIsDeployed();
		Possibilities[6] = !country->getArmy()->armyIsDeployed();

		// 9 .sendSupplies
		Possibilities[8] = country->getArmy()->armyIsDeployed();
	}

	// 8. surrender
	Possibilities[7] = true;

	// 9. sendSupplies
	//	Possibilities[8] = true;

	// 10. do nothing
	Possibilities[9] = false;

	// Generate random number
	// srand(time(0));
	// int index = 0;
	/*
		while (Possible == false)
		{
			srand(mySeed + 100);
			index = (rand() + mySeed + 100) % 10;

			if (Possibilities[index] == true)
			{
				Possible = true;
				Decision = index + 1;
			}
		}
	*/

	int numOptions = 0;
	for (int i = 0; i < 10; i++)
	{
		if (Possibilities[i] == true)
		{
			numOptions++;
		}
	}

	int *options = new int[numOptions];
	int counter = 0;
	for (int i = 0; i < 10; i++)
	{
		if (Possibilities[i] == true)
		{
			options[counter++] = i;
		}
	}

	static int seeder = 11;
	seeder += 13;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
	int temp = rand() + mySeed + 100;
	if (temp < 0)
	{
		temp = -1 * temp;
	}
	int index = (temp) % numOptions;

	/*
		std::cout << "Index " << index << std::endl;
		std::cout << "Options: ";
		for (int i = 0; i < numOptions; i++)
		{
			std::cout << options[i] + 1 << " ";
		}
		std::cout << std::endl;
	*/

	Decision = options[index];
	// std::cout << country->getName() << " " << Decision + 1 << std::endl;
	return Decision + 1;
}

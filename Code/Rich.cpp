#include "Rich.h"
#include "Country.h"
#include <ctime>
#include <cstdlib>

int Rich::decideMyTurn(Country* country) {
	
	int Decision = 0;
	bool Possible = false;
	bool Possibilities[10];

	//Initialize every index as false
	for (int i = 0; i < 10; i++)
	{
		Possibilities[i] = false;
	}

	// Possible decisions
	// 1. formAlliance (if not already in alliance1 or alliance2 ie: in neutral)

	// 2. raiseArmy
	Possibilities[1] = true;

	// 3. upgradeUnitFactory
	Possibilities[2] = true;

	// 4. upgradeSupplyFactory
	Possibilities[3] = true;

	// 5, 6, 7 require there to be an army alreayd
	//  5. enterArmyIntoTheatre
	//  6. changeArmyStrategy
	//  7. attackTransport
	if (country->getArmy() == NULL)
	{
		Possibilities[4] = false;
		Possibilities[5] = false;
		Possibilities[6] = false;
	}
	else
	{
		Possibilities[4] = true;
		Possibilities[5] = true;
		Possibilities[6] = true;
	}

	// 8. Surrender = not possible
	Possibilities[7] = false;
	
	// 9 .sendSupplies
	Possibilities[8] = true;

	// 10. do nothing = not possible
	Possibilities[9] = false;

	// Generate random number
	srand(time(0)); 
	int index = 0;

	while (Possible == false)
	{
		index = rand()%10;

		if(Possibilities[index] == true)
		{
			Possible = true;
			Decision = index + 1;
		}
	}

	return Decision;
}

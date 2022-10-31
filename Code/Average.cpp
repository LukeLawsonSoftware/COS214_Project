#include "Average.h"
#include "Country.h"
// #include "EconomicState.h"
#include <ctime>
#include <cstdlib>

int Average::decideMyTurn(Country *country)
{

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
	Possibilities[0] = false;
	for (int i = 0; i < country->Country::neutral.size(); i++)
	{
		if (Country::neutral.at(i)->getName() == country->getName())
		{
			Possibilities[0] = true;
			break;
		}
	}

	// 2. raiseArmy (I have implemented s.t. this could fail if not enought gdp)
	Possibilities[1] = true;

	// 3. upgradeUnitFactory (I have implemented s.t. this could fail if not enought gdp)
	Possibilities[2] = true;

	// 4. upgradeSupplyFactory (I have implemented s.t. this could fail if not enought gdp)
	Possibilities[3] = true;

	// 5, 6, 7 require there to be an army already
	// 	5. enterArmyIntoTheatre
	// 	6. changeArmyStrategy
	// 	7. attackTransport
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

	// 9. sendSupplies
	Possibilities[8] = true;

	// 10. do nothing
	Possibilities[9] = true;

	// Generate random number
	srand(time(0));
	int index = 0;

	while (Possible == false)
	{
		index = rand() % 10;

		if (Possibilities[index] == true)
		{
			Possible = true;
			Decision = index + 1;
		}
	}

	return Decision;
}

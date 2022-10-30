#include "Poor.h"
#include <ctime>
#include <cstdlib>

int Poor::decideMyTurn() {

	int Decision = 0;
	bool Possible = false;
	bool Possibilities[10];

	//Initialize every index as false
	for (int i = 0; i < 10; i++)
	{
		Possibilities[i] = false;
	}

	// Possible decisions:
	//  1. formAlliance (if not already in alliance1 or alliance2 ie: in neutral)

	//  2. raiseArmy (this methdo will fail if the country does not have enough gdp)

	//  5, 6, 7 require there to be an army alreayd
	//  5. enterArmyIntoTheatre
	//  6. changeArmyStrategy
	//  7. attackTransport
	
	//  8. surrender
	//  10. do nothing

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

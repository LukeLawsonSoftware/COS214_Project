#include "AmmoSupply.h"
// #include "Supply.h"

AmmoSupply::AmmoSupply(int factoryLevel, int quantity) : Supply(quantity)
{
	// TODO - implement AmmoSupply::AmmoSupply

	double bonus = 0;
	srand((unsigned)time(0)); // to generate a different value each time

	// generate bonus based on factory level
	if (factoryLevel == 1)
	{
		bonus = (double)(10 + (rand() % 20)) / 100;
	}
	else if (factoryLevel > 1 && factoryLevel < 4)
	{
		bonus = (double)(20 + (rand() % 40)) / 100;
	}
	else
	{
		bonus = (double)(40 + (rand() % 80)) / 100;
	}

	setAmmoBonus(bonus * quantity);

	// throw "Not yet implemented";
}

int AmmoSupply::getAmmoBonus()
{
	return this->ammoBonus;
}

void AmmoSupply::setAmmoBonus(int bonus)
{
	this->ammoBonus = bonus;
}

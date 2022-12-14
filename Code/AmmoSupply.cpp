#include "AmmoSupply.h"
// #include "Supply.h"

AmmoSupply::AmmoSupply(int factoryLevel, int quantity) : Supply(quantity)
{
	// TODO - implement AmmoSupply::AmmoSupply

	double bonus = 0;
	static int seeder = 1352352;
	seeder += 1212121;
	srand((unsigned)time(0) + seeder); // to generate a different value each time

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
	if (bonus < 0)
		throw std::invalid_argument("Cannot set ammo bonus as a negative value");

	this->ammoBonus = bonus;
}

#ifndef AMMOSUPPLY_H
#define AMMOSUPPLY_H
#include "Supply.h"

class AmmoSupply : public Supply
{

public:
	int ammoBonus;

	AmmoSupply(int factoryLevel, int quantity);

	int getAmmoBonus();

	void setAmmoBonus(int bonus);
};

#endif

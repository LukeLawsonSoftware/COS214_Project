#ifndef AMMOFACTORY_H
#define AMMOFACTORY_H

#include "SupplyFactory.h"
class AmmoSupply;

#include <iostream>
#include <cstdlib>
#include <ctime>

class AmmoFactory : public SupplyFactory
{
public:
	/// @brief Class constructor for the AmmoFactory to initialize the budget.
	/// @author Arno Jooste (u21457451)
	/// @param budget The amount that can be spent to make ammo supplies.
	/// @param type The type of the factory.
	AmmoFactory(int budget, std::string type);

	/// @brief Creates ammo supplies by creating a new AmmoSupply product.
	/// @author Arno Jooste (u21457451)
	/// @param quantity The quantity of ammo supplies to be produced by the ammo factory.
	/// @return Pointer to newly created AmmoSupply product.
	Supply *makeSupply(int quantity);
};

#endif

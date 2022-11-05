#ifndef AMMOFACTORY_H
#define AMMOFACTORY_H

#include "SupplyFactory.h"
class AmmoSupply;

#include <iostream>
#include <cstdlib>
#include <ctime>
/**
 * @class AmmoFactory AmmoFactory.h
 * The AmmoFactory class is a derived class derived from the UnitFactory class
 * @ref SupplyFactory.h "(See the definition of the SupplyFactory class)"
 * 
 * The AmmoFactory will be used to create Ammo Suppliess for the Country's Armies. The AmmoFactory
 * has a method "makeSupply()" which will create the AmmoSuppply object.
 * @note This class is ONLY used to create AmmoSupply objects
*/

class AmmoFactory : public SupplyFactory
{
public:
	/// @brief Class constructor for the AmmoFactory to initialize the budget.
	/// @author Arno Jooste (u21457451)
	/// @param budget The amount that can be spent to make ammo supplies.
	/// @param type The type of the factory.
	/// @warning "type" has to be "Ammo" and "budget" may not be less than or equal to zero.
	AmmoFactory(int budget, std::string type);

	/// @brief Creates ammo supplies by creating a new AmmoSupply product.
	/// @author Arno Jooste (u21457451)
	/// @param quantity The quantity of ammo supplies to be produced by the ammo factory.
	/// @return Pointer to newly created AmmoSupply product.
	/// @warning "quantity" need to be positive.
	/// @note This function may return NULL if the budget has run out.
	Supply *makeSupply(int quantity);
};

#endif

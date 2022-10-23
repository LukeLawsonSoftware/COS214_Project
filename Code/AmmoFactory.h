#ifndef AMMOFACTORY_H
#define AMMOFACTORY_H
#include "SupplyFactory.h"
#include "AmmoSupply.h"

class AmmoFactory : public SupplyFactory
{

	public:
		/// @brief Creates ammo supplies by creating a new AmmoSupply product.
		/// @author Arno Jooste (u21457451)
		/// @param quantity The quantity of ammo supplies to be produced by the ammo factory.
		/// @return Pointer to newly created AmmoSupply product.
		Supply *makeSupply(int quantity);
};

#endif

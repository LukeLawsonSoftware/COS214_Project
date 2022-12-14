#ifndef AMMOSUPPLY_H
#define AMMOSUPPLY_H

#include "Supply.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * @class AmmoSupply AmmoSupply.h
 * 
 * This class is derived from the Supply class. This is the actual product created by the AmmoFactory.
 * - Armies will use ammo supply objects to fight the war. 
 * - If an army's ammo supply runs out they are in great disadvantage.
 * @note The ammo supply has a variety of small and large ammo i.e. small bullets and heavy bullets.
 */

class AmmoSupply : public Supply
{

public:
	/// @brief Constructor for AmmoSupply class to specify the factory level and quantity that will be produced.
	/// @author Arno Jooste (21457451)
	/// @param factoryLevel Specifies the currrent factory level in order to set the multiplier of the bonus.
	/// @param quantity Specifies the quentity of ammo supplies to be produced. This amount will be used to calculate the ammoBonus.
	/// @warning The factoryLevel must be a value greater than the integer value 0.
	/// @warning The quantity must also be a value greater than zero.
	AmmoSupply(int factoryLevel, int quantity);

	/// @brief Getter for the ammo bonus member variable.
	/// @author Arno Jooste (u21457451)
	/// @return ammo bonus of type int.
	int getAmmoBonus();

	/// @brief Setter for the ammo bonus member variable.
	/// @author Arno Jooste (u21457451)
	/// @param bonus Specfies to which value the ammo bonus will be set.
	void setAmmoBonus(int bonus);

private:
	int ammoBonus;
};

#endif

#ifndef AMMOSUPPLY_H
#define AMMOSUPPLY_H

#include "Supply.h"

#include <cstdlib>
#include <ctime>

class AmmoSupply : public Supply
{

public:
	/// @brief Constructor for AmmoSupply class to specify the factory level and quantity that will be produced.
	/// @author Arno Jooste (21457451)
	/// @param factoryLevel Specifies the currrent factory level in order to set the multiplier of the bonus.
	/// @param quantity Specifies the quentity of ammo supplies to be produced. This amount will be used to calculate the ammoBonus.
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

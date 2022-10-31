#ifndef MEDICALSUPPLY_H
#define MEDICALSUPPLY_H

#include "Supply.h"

#include <cstdlib>
#include <ctime>

class MedicalSupply : public Supply
{
public:
	/// @brief Constructor for MedicalSupply class to specify the factory level and quantity that will be produced.
	/// @author Arno Jooste (21457451)
	/// @param factoryLevel Specifies the currrent factory level in order to set the multiplier of the bonus.
	/// @param quantity Specifies the quentity of medical supplies to be produced. This amount will be used to calculate the medicalBonus
	MedicalSupply(int factoryLevel, int quantity);

	/// @brief Getter for the medical bonus member variable.
	/// @author Arno Jooste (u21457451)
	/// @return medical bonus of type int.
	int getMedicalBonus();

	/// @brief Setter for the medical bonus member variable.
	/// @author Arno Jooste (u21457451)
	/// @param bonus Specfies to which value the medical bonus will be set.
	void setMedicalBonus(int bonus);

private:
	int medicalBonus;
};

#endif

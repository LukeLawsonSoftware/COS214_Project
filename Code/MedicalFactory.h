#ifndef MEDICALFACTORY_H
#define MEDICALFACTORY_H
#include "SupplyFactory.h"
class MedicalSupply;

#include <iostream>
#include <cstdlib>
#include <ctime>

class MedicalFactory : public SupplyFactory
{

public:
	/// @brief Class constructor for MedicalFactory
	/// @author Arno Jooste (u21457451)
	/// @param budget The amount that can be spent to make medical supplies.
	/// @param type The type of the factory.
	MedicalFactory(int budget, std::string type);

	/// @brief Creates medical supplies by creating a new MedicalSupply product.
	/// @author Arno Jooste (u21457451)
	/// @param quantity The quantity of medical supplies to be produced by the medical factory.
	/// @return Pointer to newly created MedicalSupply product.
	Supply *makeSupply(int quantity);
};

#endif

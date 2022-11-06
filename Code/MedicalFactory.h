#ifndef MEDICALFACTORY_H
#define MEDICALFACTORY_H
#include "SupplyFactory.h"
class MedicalSupply;

#include <iostream>
#include <cstdlib>
#include <ctime>


/**
 * @class MedicalFactory MedicalFactory.h
 * The MedicalFactory class is a derived class derived from the SupplyFactory class
 * @ref SupplyFactory.h "(See the definition of the SupplyFactory class)"
 * 
 * The MedicalFactory will be used to create Medical Supplies for the Country's Armies. The MedicalFactory
 * has a method "makeSupply()" which will create the MedicalSuppply object.
 * @note This class is ONLY used to create MedicalSupply objects
*/
class MedicalFactory : public SupplyFactory
{

public:
	/// @brief Class constructor for MedicalFactory
	/// @author Arno Jooste (u21457451)
	/// @param budget The amount that can be spent to make medical supplies.
	/// @param type The type of the factory.
	/// @warning "type" has to be "Medical" and "budget" may not be less than or equal to zero.
	MedicalFactory(int budget, std::string type);

	/// @brief Creates medical supplies by creating a new MedicalSupply product.
	/// @author Arno Jooste (u21457451)
	/// @param quantity The quantity of medical supplies to be produced by the medical factory.
	/// @return Pointer to newly created MedicalSupply product.
	/// @warning "quantity" need to be positive.
	/// @note This function may return NULL if the budget has run out.
	Supply *makeSupply(int quantity);
};

#endif

#ifndef MEDICALFACTORY_H
#define MEDICALFACTORY_H
#include "SupplyFactory.h"
#include "MedicalSupply.h"

class MedicalFactory : public SupplyFactory
{

	public:
		/// @brief Creates medical supplies by creating a new MedicalSupply product.
		/// @author Arno Jooste (u21457451)
		/// @param quantity The quantity of medical supplies to be produced by the medical factory.
		/// @return Pointer to newly created MedicalSupply product.
		Supply *makeSupply(int quantity);
};

#endif

#ifndef MEDICALFACTORY_H
#define MEDICALFACTORY_H
#include "SupplyFactory.h"
#include "Supply.h"

class MedicalFactory : public SupplyFactory
{

public:
	Supply *makeSupply();
};

#endif

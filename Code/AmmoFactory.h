#ifndef AMMOFACTORY_H
#define AMMOFACTORY_H
#include "SupplyFactory.h"
#include "Supply.h"

class AmmoFactory : public SupplyFactory
{

public:
	Supply *makeSupply();
};

#endif

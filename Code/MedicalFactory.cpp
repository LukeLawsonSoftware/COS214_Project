#include "MedicalFactory.h"

MedicalFactory::MedicalFactory(int budget):SupplyFactory(budget){};

Supply* MedicalFactory::makeSupply(int quantity) {
	// TODO - implement MedicalFactory::makeSupply

	return new MedicalSupply(getLevel(), quantity);

	// throw "Not yet implemented";
}

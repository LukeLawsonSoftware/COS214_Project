#include "MedicalFactory.h"

Supply* MedicalFactory::makeSupply(int quantity) {
	// TODO - implement MedicalFactory::makeSupply

	return new MedicalSupply(getLevel(), quantity);

	// throw "Not yet implemented";
}

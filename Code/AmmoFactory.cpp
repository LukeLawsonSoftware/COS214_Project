#include "AmmoFactory.h"

Supply *AmmoFactory::makeSupply(int quantity)
{
	// TODO - implement AmmoFactory::makeSupply

	return new AmmoSupply(getLevel(), quantity);

	// throw "Not yet implemented";
}

#ifndef POOR_H
#define POOR_H
#include "EconomicState.h"

class Poor : public EconomicState
{

public:
	int decideMyTurn();
};

#endif

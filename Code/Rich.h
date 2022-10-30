#ifndef RICH_H
#define RICH_H
#include "EconomicState.h"

class Rich : public EconomicState
{

public:
	/// @brief randomly decide what a country can do during their turn
	/// @author Jonelle Coertze (u21446271)
	/// @return an int corresponding with the decision
	int decideMyTurn(Country* country);
};

#endif

#ifndef RICH_H
#define RICH_H
#include "EconomicState.h"

class Rich : public EconomicState
{

public:
	/// @brief randomly decide what a country can do during their turn
	/// @author Jonelle Coertze (u21446271)
	/// @param country pointer to an existing Country object to have access to the country's army and alliences
	/// @return an int corresponding with the decision
	int decideMyTurn(Country* country);
};

#endif

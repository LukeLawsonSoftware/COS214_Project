#ifndef AVERAGE_H
#define AVERAGE_H
#include "EconomicState.h"

class Average : public EconomicState
{
public:

	/// @brief randomly decide what a country can do during their turn
	/// @author Jonelle Coertze (u21446271)
	/// @return an int corresponding with the decision
	int decideMyTurn(Country* country);
};

#endif

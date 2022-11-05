#ifndef ECONOMICSTATE_H
#define ECONOMICSTATE_H
#include <iostream>

class Country;

class EconomicState
{
public:
	/// @brief randomly decide what a country can do during their turn
	/// @author Jonelle Coertze (u21446271)
	/// @param country pointer to an existing Country object to have access to the country's army and alliences
	/// @return an int corresponding with the decision
	virtual int decideMyTurn(Country *country) = 0;
};

#endif

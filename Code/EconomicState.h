#ifndef ECONOMICSTATE_H
#define ECONOMICSTATE_H

class Country;

class EconomicState {
public:
	/// @brief randomly decide what a country can do during their turn 
	/// @author Jonelle Coertze (u21446271)
	/// @return an int corresponding with the decision
	virtual int decideMyTurn(Country* country) = 0;
};

#endif

#ifndef ECONOMICSTATE_H
#define ECONOMICSTATE_H

class EconomicState {


public:
	/// @brief randomly decide what a country can do during their turn 
	/// @author Jonelle Coertze
	/// @return an int corresponding with the decision
	virtual int decideMyTurn() = 0;
};

#endif

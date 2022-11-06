#ifndef ECONOMICSTATE_H
#define ECONOMICSTATE_H
#include <iostream>

class Country;


/**
 * @class EconommicState EconomicState.h
 * 
 * This class will be used to specify in which economic state the country is throughout the duration of the War.
 * 
 * There are three states in which a country can find itself:
 * - Rich: Being in a rich state gives the country the benefit of upgrading its UnitFactory and SupplyFactory. This would increase the budget of the factories therefore making it possible to create more units and supplies giving them a greater advantage to winnning the War.
 * - Average: Being in an average state has the same advantages of being in a rich state except the Country should be careful not to spend too much gdp since they are only in an average state.
 * - Poor: Being in a poor state has the disadvantage of not being able to upgrade factories. Therefore if the factories run out of budget then the country will not be able to create armies and send supplies to the armies. In this state the Country has the option to surrender to the enemy.
 * 
 * @note The economic state of a country can change rappidly throughout the duration of the War.
 * 
 */

class EconomicState {


public:
	/// @brief randomly decide what a country can do during their turn
	/// @author Jonelle Coertze (u21446271)
	/// @param country pointer to an existing Country object to have access to the country's army and alliences
	/// @return an int corresponding with the decision
	virtual int decideMyTurn(Country *country) = 0;
};

#endif

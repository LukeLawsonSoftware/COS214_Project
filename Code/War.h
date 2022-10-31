#ifndef WAR_H
#define WAR_H
#include "WarPhase.h"
#include "WarTheatre.h"

class WarPhase; // forward Declaration

class War
{

private:
	WarTheatre *warTheatre; // should rather have an airTheatre, a seaTheatre and a landTheatre
	WarPhase *phase;		// this needs to be a chain of responsibility. Phase changes each turn
	bool isActive;			// to determine whether war has ended or not

public:
	// Needs a constructor to initialise theatres and phase chain

	void setupTheatres();		  // rather initialise in constructor
	void setWarPhase(WarPhase *); // rather make this a method to request chain

	// obvious getters
	WarTheatre *getLandTheatre();
	WarTheatre *getAirTheatre();
	WarTheatre *getSeaTheatre();

	// needs to be made relevant for chain of responsibility
	void changePhase();

	// This is the main complicated method of the entire war. It's pseudo-code is as follows:
	// Prompt the user to configure Countries and alliances/neutral
	// while (isActive)
	//{
	// iterate through each alliance of countries and call takeTurn (if the country has not surrendered) (go 1 2 n 1 2 n 1 2 n etc)
	// call conflict() on each war theatre
	// check if war is over yet. ie: check if everyone in an alliance has surrendered or one alliance controls every war theatre
	// if so, isActive = false
	// each country earns an amount of gdp or loses an amount of gdp (can be random)
	//}
	void startWarSim();

	// similar to above methdo, except modified s.t. at each turn, the user is prompted to make the decisions for alliance1 countries rather than using takeTurn
	// alliance2 and neutral can use takeTurn()
	void startWarGame();

	// ends the simulation with approriate output
	void stopWar();
};

#endif

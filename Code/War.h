#ifndef WAR_H
#define WAR_H
#include <map>
// #include "WarPhase.h"
// #include "WarTheatre.h"
class WarPhase;
class WarTheatre;
class War
{

private:
	std::map<std::string, WarTheatre *> warTheatres; // should rather have an airTheatre, a seaTheatre and a landTheatre
	WarPhase *phase;								 // this needs to be a chain of responsibility. Phase changes each turn
	bool isActive;									 // to determine whether war has ended or not

public:
	// Needs a constructor to initialise theatres and phase chain
	/// @brief Constructor to initialise a War object and set initialise its WarPhase and War theatres
	///@author Thomas Blendulf (u21446131)
	War();

	void setWarPhase(WarPhase *); // rather make this a method to request chain maybe? idk how chain works

	// obvious getters

	/// @brief Getter for the Land Theatre of the War.
	/// @return Land WarTheatre*
	///@author Thomas Blendulf (u21446131)
	WarTheatre *getLandTheatre();
	/// @brief Getter for the Air Theatre of the War.
	/// @return Air WarTheatre*
	///@author Thomas Blendulf (u21446131)
	WarTheatre *getAirTheatre();
	/// @brief Getter for the Sea Theatre of the War.
	/// @return Sea WarTheatre*
	///@author Thomas Blendulf (u21446131)
	WarTheatre *getSeaTheatre();

	// needs to be made relevant for chain of responsibility

	/// @brief Method Changes the next corresponding phase of the War Phases
	/// @author Thomas Blendulf (u21446131)
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

	/// @brief Method to be run if the user desires a uninterruptable war simulation.
	/// @author Thomas Blendulf (u21446131)
	void startWarSim();

	// similar to above methdo, except modified s.t. at each turn, the user is prompted to make the decisions for alliance1 countries rather than using takeTurn
	// alliance2 and neutral can use takeTurn()

	/// @brief Method to be run if the user desires a interruptable war simulation, whereby an alliance1's countries decisions are decided by the user.
	/// @author Thomas Blendulf (u21446131)
	void startWarGame();

	// ends the simulation with approriate output

	/// @brief Ends the war.
	/// @author Thomas Blendulf (u21446131)
	void stopWar();
};

#endif

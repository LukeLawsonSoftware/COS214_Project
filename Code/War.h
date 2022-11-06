#ifndef WAR_H
#define WAR_H
#include <map>
// #include "WarPhase.h"
// #include "WarTheatre.h"
class WarPhase;
class WarTheatre;

/**
 * @class War War.h
 * 
 * This class represent the actual war gameplay.
 * 
 * - The war will consist of three different war theatres namely: AirTheatre, LandTheatre and SeaTheatre.
 * - Throughout the gameplay it is possible to change from one WarPhase to another. The different war phases include:
 * 		- EarlyPhase: This phases is sort of the introduction phase of a war where the tention between two countries is only starting to develop. There are three early phases of the war:
 * 						- EarlyCrisis
 * 						- EarlyOpenConflict
 * 						- EarlyPeace
 * 						- EarlyUnstablePeace
 * 		- MidPhase: In this phase the actual war between two countries starts. We enter this phase once two countries have declared War against one another.
 * 		- LatePhase: Once we enter the late phase the war starts coming to an end. In order end the war one country either needs to surrender against the enemy country or the country needs to be defeated by the enemy country. There are four late phases of the war:
 * 						- LateCrisis
 * 						- LateOpenConflict
 * 						- LatePeace
 * 						- LateUnstablePeace
 * @note The flow of the war phases will be from early phase -> mid phase -> late phase
 * 
 * 
 */

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

	/// @brief When called will prompt the user to enter the countries for Alliance 1, Alliance 2 and Neutral Countries.
	/// @author Thomas Blendulf (u21446131)
	void setUpCountries();

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

	void selectConfiguration();
};

#endif

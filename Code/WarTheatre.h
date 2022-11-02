#ifndef WARTHEATRE_H
#define WARTHEATRE_H
#include "Army.h"
#include "NonCombatEntity.h"
#include "BattleStatistics.h"
#include <vector>
#include <string>

class WarTheatre
{

private:
	int contentionState;					   // 0=no armies, 1=army from alliance1 only, 2=army from alliance2 only, 3=2 armies in contention (different alliances)
	Army* armies[2];						   // maybe make this an array. army[0] =from alliance1, army[1] from alliance2
	std::vector<NonCombatEntity *> *medics;	   // might need to be dynamically cast to getHealing
	std::vector<NonCombatEntity *> *civilians; // Almost entirely to be killed
	std::string type;						   // Land/Sea/Air
	std::string name;						   // ex: The Red Sea, or No Man's Land

	// when altering the stats, make sure to alter the BattleStatistics* stats member of the army using the appropriate setters

	/// @brief a function to apply bonus to the approriate terrain defenesive stats of both armies
	/// @author Jonelle Coertze (u21446271)
	virtual void adjustDefence() = 0; // primitiveOperation

	/// @brief a function to apply bonus to the approriate terrain offensive stats of both armies
	/// @author Jonelle Coertze (u21446271)
	virtual void adjustAttack() = 0; // primitiveOperation

public:
	/// @brief a paramaterized constructor to set the type, name and the medics and civilian vectors
	/// @author Jonelle Coertze (u21446271)
	/// @param Type string used to indicate if the war theatre is a land, sea or air terrain
	/// @param Name string used to give the war theatre a name
	WarTheatre(std::string Type, std::string Name);

	
	/// @brief a destructor to delete the medics and civilian vectors
	/// @author Jonelle Coertze (u21446271)
	~WarTheatre();

	/// @brief the template method used to call the appropriate terrain's adjustDefence and adjustAttack methods
	/// @author Jonelle Coertze (u21446271)
	void applyTerrainBonus(); 

	// This is the main complicated method, please see WarTheatre.cpp for a description of the algorithm
	void conflict();

	/// @brief a function to add an army to the war theatre
	/// @author Jonelle Coertze (u21446271)
	/// @param newArmy pointer to an army object that wants to enter the war theatre
	void addArmy(Army *newArmy);

	/// @brief a function to add a fixed number of civilains and medics each time
	/// @author Jonelle Coertze (u21446271)
	void replenishNonCombatEntities();

	/// @brief a get method to return the type of the war theatre
	/// @author Jonelle Coertze (u21446271)
	/// @return string used to indicate the type(air/land/sea) of the war theatre
	std::string getType();

	/// @brief a get method to return the name of the war theatre
	/// @author Jonelle Coertze (u21446271)
	/// @return string used to indicate the name of the war theatre
	std::string getName();

	/// @brief a get method to return the armies currently present in the war theatre
	/// @author Jonelle Coertze (u21446271)
	/// @return pointer to the army array containing the armies currently present in the war theatre
	Army* getArmies();
};

#endif

#ifndef ARMY_H
#define ARMY_H

class ArmyComponent;
class AmmoSupply;
class Country;
class WarTheatre;
#include "Corresponder.h"
class Offensive;
class Defensive;
class Neutral;
class MedicalSupply;
class BattleStatistics;
class ArmyStrategy;
class Supply;

#include <string>
#include <vector>

/**
 * @class Army Army.h
 * 
 * The Army class is a big component in the War since we use this class to keep track of the army's supplies (AmmoSuppply & MedicalSupply).
 * We also use this class to fight against other Countries. We are also able to attack the enemy's Transport which will disable the enemy's
 * transport lines. Thus they won't be able to send supplies to their armies, giving our Army a slight advantage.
 * @note This class has vectors for the ammo and medical supplies to separate the two supplies such that we can keep track of the size for both supplies.
*/
class Army : public Corresponder
{

private:
	ArmyComponent *army;
	std::vector<AmmoSupply *> *ammoSupply;
	std::vector<MedicalSupply *> *medicalSupply;
	ArmyStrategy *currentStrategy;
	std::string type;
	BattleStatistics *stats;
	std::string name;

public:
	/// @brief Constructor to initialise an army object with ArmyComponents, Supplies and a type
	/// @author Luke Lawson (u21433811)
	/// @param battalions pointer to vector of ArmyComponent pointers representing battalions
	/// @param individuals pointer to vector of ArmyComponent pointers representing individuals (vehicles or units)
	/// @param supplies pointer to vector of Supply pointers for Ammo and Meds
	/// @param type string type of the army. Land, Air or Sea
	/// @warning To instantiate the Army object, the battalions, individuals and suppplies need to be already defined.
	/// @note The type is used to specify which army we will instantiate i.e. in which theatre the army will be fighting (Land, Air or Sea).
	Army(std::vector<ArmyComponent *> *battalions, std::vector<ArmyComponent *> *individuals, std::vector<Supply *> *supplies, std::string type);

	/// @brief Function to apply bonus to the army's BattleStatistics
	/// @author Luke Lawson (u21433811)
	void applyStrategyBonus();

	/// @brief Function to use medical supplies to replenish army's morale/hp
	/// @author Luke Lawson (u21433811)
	/// @note This function is used to heal our army by using the medical supplies.
	void recuperate();

	/// @brief Function to add to Army's available ammo supplies
	/// @author Luke Lawson (u21433811)
	/// @param ammo pointer to AmmoSupply object to be added
	void addNewAmmoSupplies(AmmoSupply *ammo);

	/// @brief Function to add to Army's available medical supplies
	/// @author Luke Lawson (u21433811)
	/// @param ammo pointer to MedicalSupply object to be added
	void addNewMedicalSupplies(MedicalSupply *);

	/// @brief Function to change an Army's current strategy
	/// @author Luke Lawson (u21433811)
	/// @param newStart string represening the new strategy to adopt
	void changeStrategy(std::string newStrat);

	/// @brief Function move this Army into a War Theatre
	/// @author Luke Lawson (u21433811)
	/// @param theatre pointer to War Theatre to be added to
	/// @warning The specified WarTheatre needs to be of the same type as the Army object. We cannot let Land armies fight in an Air theatre.
	void setBattleField(WarTheatre *theatre); // theatre->add(this)

	/// @brief Function for an Army to attack a Country's
	/// @author Luke Lawson (u21433811)
	/// @param country pointer to Country whose Transport lines are to be attacked
	void attackTransport(Country *country);

	/// @brief Function to change an Army's current strategy
	/// @author Luke Lawson (u21433811)
	/// @return string representing the army's type (Air, Land or Sea)
	std::string getType();

	/// @brief a function to get the BattleStatistics of a army to alter the statistics
	/// @author Jonelle Coertze (u21446271) 
	/// @return pointer to a BattleStatistics object
	BattleStatistics* getBattleStatistics();

	/// @brief a function to set the name of the army
	/// @author Jonelle Coertze (u21446271)
	/// @param Name string to set the name of the Army
	void setName(std::string Name);

	/// @brief a function to get the name of the army
	/// @author Jonelle Coertze (u21446271)
	/// @return a string giving the army's name
	std::string getName();
};

#endif

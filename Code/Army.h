#ifndef ARMY_H
#define ARMY_H
#include "ArmyComponent.h"
#include "AmmoSupply.h"
#include "Country.h"
#include "WarTheatre.h"
#include "Corresponder.h"
#include "Offensive.h"
#include "Defensive.h"
#include "Neutral.h"
#include "MedicalSupply.h"

class Army : public Corresponder
{

private:
	ArmyComponent *army;
	std::vector<AmmoSupply *> *ammoSupply;
	std::vector<MedicalSupply *> *medicalSupply;
	ArmyStrategy *currentStrategy;
	std::string type;
	BattleStatistics *stats;

public:
	/// @brief Constructor to initialise an army object with ArmyComponents, Supplies and a type
	/// @author Luke Lawson (u21433811)
	/// @param battalions pointer to vector of ArmyComponent pointers representing battalions
	/// @param individuals pointer to vector of ArmyComponent pointers representing individuals (vehicles or units)
	/// @param supplies pointer to vector of Supply pointers for Ammo and Meds
	/// @param type string type of the army. Land, Air or Sea
	Army(std::vector<ArmyComponent *> *battalions, std::vector<ArmyComponent *> *individuals, std::vector<Supply *> *supplies, std::string type);

	/// @brief Function to apply bonus to the army's BattleStatistics
	/// @author Luke Lawson (u21433811)
	void applyStrategyBonus();

	/// @brief Function to use medical supplies to replenish army's morale/hp
	/// @author Luke Lawson (u21433811)
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
	void setBattleField(WarTheatre *theatre); // theatre->add(this)

	/// @brief Function for an Army to attack a Country's
	/// @author Luke Lawson (u21433811)
	/// @param country pointer to Country whose Transport lines are to be attacked
	void attackTransport(Country *country);

	/// @brief Function to change an Army's current strategy
	/// @author Luke Lawson (u21433811)
	/// @return string representing the army's type (Air, Land or Sea)
	std::string getType();
};

#endif

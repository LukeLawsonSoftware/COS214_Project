#ifndef COUNTRY_H
#define COUNTRY_H
#include "Rich.h"
#include "Poor.h"
#include "Average.h"
#include "Corresponder.h"
#include "LandFactory.h"
#include "AirFactory.h"
#include "SeaFactory.h"
#include "AmmoFactory.h"
#include "MedicalFactory.h"
#include "Army.h"
#include "WarTheatre.h"
#include "ArmyDirector.h"
#include "ArmyBuilder.h"
#include "MilitaryCommander.h"
#include <vector>
#include <string>

class War;

class Country : public Corresponder
{

public:
	// need to make an array of Country vectors
	static std::vector<Country *> alliance1;
	static std::vector<Country *> alliance2;
	static std::vector<Country *> neutral;

private:
	std::string name;
	double gdp;
	EconomicState *ecoState;
	std::vector<UnitFactory *> *unitFactories;
	std::vector<SupplyFactory *> *supplyFactories;
	Army *army;
	MilitaryCommander *commander;

public:
	/// @brief Constructor to initialise a Country based on its starting EconomicState
	///@author Luke Lawson (u21433811)
	/// @param ecoState String of value Rich, Average or Poor
	/// @param name the name of the Country
	Country(std::string ecoState, std::string name);

	/// @brief Destructor to deallocate any dynamic memory involved
	///@author Luke Lawson (u21433811)
	~Country();

	/// @brief Getter for the Country name
	/// @author Luke Lawson (u21433811)
	/// @return string name of the Country
	std::string getName();

	/// @brief Function to increase Country GDP and manage change of economic state.
	///@author Luke Lawson (u21433811)
	/// @param gdpEarned double which indicates the amount to increase GDP by
	void earnGDP(double gdpEarned);

	/// @brief Function to decrease Country GDP and manage change of economic state.
	/// @author Luke Lawson (u21433811)
	/// @param gdpSpent double which indicates the amount to decrease GDP by
	void spendGDP(double gdpSpent);

	/// @brief Function to decide and enact the Country's play for a turn.
	/// @author Luke Lawson (u21433811)
	/// @param currWar pointer to the War the Country is currently engaged in
	void takeTurn(War *currWar);

	/// @brief Function to add random Country from neutral to this Country's alliance
	/// @author Luke Lawson (u21433811)
	void formAlliance();

	/// @brief Function to call appropriate creational structures to create an army and add it to Country's armies.
	///@author Luke Lawson (u21433811)
	void raiseArmy();

	/// @brief Function to upgrade a Country's Unit Factory such to produce better military units
	///@author Luke Lawson (u21433811)
	void upgradeUnitFactory();

	/// @brief Function to upgrade a Country's Supply Factory such to produce better/greater quantity of medical supplies and ammo
	///@author Luke Lawson (u21433811)
	void upgradeSupplyFactory();

	/// @brief Function to use MilitaryCommander to send an Army into a WarTheatre
	/// @author Luke Lawson (u21433811)
	/// @param war pointyer to the War the country is currently engaged in
	void enterArmyIntoTheatre(War *war);

	/// @brief Function to use MilitaryCommander to change the Army's strategy
	/// @author Luke Lawson (u21433811)
	void changeArmyStrategy();

	/// @brief Function to use MilitaryCommander to instruct an army to attack another Country's transport
	/// @author Luke Lawson (u21433811)
	void attackTransport();

	/// @brief Function to cause Country to surrender and withdraw from the War and alliance
	/// @author Luke Lawson (u21433811)
	void surrender();

	/// @brief Function to set this Country's Transport to NULL
	/// @author Luke Lawson (u21433811)
	void destroyTransport();

	/// @brief Function to send/distribute supplies to a Country's armies
	/// @author Luke Lawson (u21433811)
	/// @param ammo AmmoSupplies to be transported
	/// @param meds MedicalSupplies to be transported
	void sendSupplies(AmmoSupply *ammo, MedicalSupply *meds);
};

#endif

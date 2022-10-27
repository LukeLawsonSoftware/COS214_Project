#ifndef COUNTRY_H
#define COUNTRY_H
#include "Rich.h"
#include "Poor.h"
#include "Average.h"
#include "Corresponder.h"
#include "LandFactory.h"
#include "AirFactory.h"
#include "SeaFactory.h"
#include "SupplyFactory.h"
#include "Army.h"
#include "WarTheatre.h"
#include <vector>
#include <string>

class War;

class Country : public Corresponder
{

public:
	// need to make an array of Country vectors
	static std::vector<Country> alliance1;
	static std::vector<Country> alliance2;
	static std::vector<Country> neutral;

private:
	std::string name;
	double gdp;
	EconomicState *ecoState;
	UnitFactory **unitFactories;
	SupplyFactory **supplyFactories;
	Army *army;

public:
	/// @brief Constructor to initialise a Country based on its starting EconomicState
	///@author Luke Lawson (u21433811)
	/// @param ecoState String of value Rich, Average or Poor
	/// @param name the name of the Country
	Country(std::string ecoState, std::string name);

	/// @brief Destructor to deallocate any dynamic memory involved
	///@author Luke Lawson (u21433811)
	~Country();

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

	/// @brief Function to decrease Country GDP and manage change of economic state.
	///@author Luke Lawson (u21433811)
	/// @param gdpEarned double which indicates the amount to decrease GDP by
	void formAlliance(Country *newAlly);

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
	///@author Luke Lawson (u21433811)
	/// @param army the Army to be sent into the WarTheatre
	/// @param theatre the theatre to be entered into by the Army
	void enterArmyIntoTheatre(Army *army, WarTheatre *theatre);

	/// @brief Function to use MilitaryCommander to change the Army's strategy
	///@author Luke Lawson (u21433811)
	/// @param army the Army whose strategy is to be changes
	/// @param newStrategy string inidcating the new strategy to be employed (offensive, defensive or neutral)
	void changeArmyStrategy(Army *army, std::string newStrategy);

	/// @brief Function to use MilitaryCommander to instruct an army to attack another Country's transport
	///@author Luke Lawson (u21433811)
	/// @param army the Army which is to attack the transport
	/// @param transport the Transport to be attacked and potentilly destroyed
	void attackTransport(Army *army, Transporter *transport);

	/// @brief Function to cause Country to surrender and withdraw from the War and alliance
	///@author Luke Lawson (u21433811)
	void surrender();

	/// @brief Function to send/distribute supplies to a Country's armies
	///@author Luke Lawson (u21433811)
	/// @param ammo AmmoSupplies to be transported
	/// @param meds MedicalSupplies to be transported
	void sendSupplies(AmmoSupply *ammo, MedicalSupply *meds);
};

#endif

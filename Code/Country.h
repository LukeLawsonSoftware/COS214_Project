#ifndef COUNTRY_H
#define COUNTRY_H
#include "Rich.h"
#include "Poor.h"
#include "Average.h"
#include "AmmoTransporter.h"
#include "MedicTransporter.h"
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
	bool hasSurrendered; // use tbis field to check in War class and WarTheatre
	AmmoSupply* newAmmoSupply;
	MedicalSupply* newMedicalSupply;
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

	/// @brief Gets whether Country has surrender from the war
	/// @author Luke Lawson (u21433811)
	/// @return boolean value of hasSurrendered
	bool isSurrendered();

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

	/// @brief Function to get the newly created supply such that we know which supply to send to the transport line
	/// @author Reuben Jooste (u21457060)
	/// @return The newly created ammo supply
	AmmoSupply* getNewAmmoSupply();

	/// @brief Function to get the newly created supply such that we know which supply to send to the transport line
	/// @author Reuben Jooste (u21457060)
	/// @return The newly created medical supply
	MedicalSupply* getNewMedicalSupply();

	/// @brief Function to set the member variable to store the newly created ammo supply
	/// @author Reuben Jooste (u21457060)
	/// @param newAmmoSupply The new ammo supply
	void setnewAmmoSupplies(AmmoSupply* newAmmoSupply);

	/// @brief Function to set the member variable to store the newly created medical supply
	/// @author Reuben Jooste (u21457060)
	/// @param newAmmoSupply The new medical supply
	void setnewMedicalSupplies(MedicalSupply* newMedicalSupply);
};

#endif

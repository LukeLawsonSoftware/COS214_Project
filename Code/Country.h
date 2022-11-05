#ifndef COUNTRY_H
#define COUNTRY_H
class Rich;
class Poor;
class Average;
class AmmoTransporter;
class MedicTransporter;
class Corresponder;
class LandFactory;
class AirFactory;
class SeaFactory;
class AmmoFactory;
class MedicalFactory;
class Army;
class WarTheatre;
class ArmyDirector;
class ArmyBuilder;
class MilitaryCommander;
#include "Corresponder.h"
class UnitFactory;
class SupplyFactory;
class AmmoSupply;
class MedicalSupply;
#include <vector>
#include <string>

class War;
class EconomicState;
// class Army;

/**
 * @class Country Country.h
 * 
 * The Country class is a big component in the War since we use this class to fight the on going war.
 * Countries will be able to form an alliance with other countries and fight together againts other countries.
 * - For this War there will only be three alliance groups: group1, group2 and group3.
 * Group 1 will fight against Countries in Group 2 and the Countries in Group 3 will "watch" the on going war and may decide (at a later stage) which
 * alliance group they want to join.
 * - Each Country will also have different factories for Supplies and to create Soldiers/Vehicles. But creating the units and supplies will cost them money
 * therefore each Country will need to keep track of their budget (gdp) in order to determine if they can afford to create more supplies/units.
 * - If a Country starts to realise that it is losing the war then it has the option of surrendering to the enemy Country.
 * - The Country also has the option to upgrade its different factories but this would only be possible if the Country is in a Rich EconomicState.
 * - Countries will have millitary commanders which will issue different commands for the Country for example raising an army to prepare for the war.
 * - Finally the Country will be able to create suppplies and signal the millitary commander to send the supplies to the Country's transport lines such that it can
 * be transported to the armies of the Country.
 * @note This class has vectors for the ammo and medical supplies to separate the two supplies such that we can keep track of the size for both supplies.
*/
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
	AmmoSupply *newAmmoSupply;
	MedicalSupply *newMedicalSupply;

public:
	/// @brief Constructor to initialise a Country based on its starting EconomicState
	///@author Luke Lawson (u21433811)
	/// @param ecoState String of value Rich, Average or Poor
	/// @param name the name of the Country
	/// @note The ecoState can only be one of the specified three (Rich, Average, Poor)
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
	/// @warning The parameter must be a positive double value. If we want to decrease the GDP we must use the function "spendGDP()".
	void earnGDP(double gdpEarned);

	/// @brief Function to decrease Country GDP and manage change of economic state.
	/// @author Luke Lawson (u21433811)
	/// @param gdpSpent double which indicates the amount to decrease GDP by
	/// @warning The parameter must be a negative double value. If we want to increase the GDP we must use the function "earnGDP()".
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
	/// @warning This function can only be used when the Country is in a Rich EconomicState
	void upgradeUnitFactory();

	/// @brief Function to upgrade a Country's Supply Factory such to produce better/greater quantity of medical supplies and ammo
	///@author Luke Lawson (u21433811)
	/// @warning This function can only be used when the Country is in a Rich EconomicState
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
	AmmoSupply *getNewAmmoSupply();

	/// @brief Function to get the newly created supply such that we know which supply to send to the transport line
	/// @author Reuben Jooste (u21457060)
	/// @return The newly created medical supply
	MedicalSupply *getNewMedicalSupply();

	/// @brief Function to set the member variable to store the newly created ammo supply
	/// @author Reuben Jooste (u21457060)
	/// @param newAmmoSupply The new ammo supply
	void setNewAmmoSupplies(AmmoSupply *newAmmoSupply);

	/// @brief Function to set the member variable to store the newly created medical supply
	/// @author Reuben Jooste (u21457060)
	/// @param newAmmoSupply The new medical supply
	void setNewMedicalSupplies(MedicalSupply *newMedicalSupply);

	/// @brief Function to return the army variable of this Country class
	/// @author Reuben Jooste (u21457060)
	/// @return Returns the army of the Country as a pointer
	Army *getArmy();
};

#endif

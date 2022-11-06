#ifndef ARMYBUILDER_H
#define ARMYBUILDER_H
class Army;
class UnitFactory;
class SupplyFactory;
class ArmyComponent;
class Supply;

#include <iostream>
#include <vector>

/**
 * @class ArmyBuilder ArmyBuilder.h
 * 
 * The ArmyBuilder class is a big component in the War since we use this class build each Country's army.
 * - This class creates the different parts of the army such as the Battalions, Individuals (Soldiers or Vehicles) and the army's supplies (AmmoSupplies or MedicalSupplies).
 * - The builder makes use of the country's factories to build/train the different supplies/units.
 * - If the country's factory do not have the budget to create even just a single unit/supply then the builder will not be able to build the army.
 * @warning Without this class the Country will not be able to raise an army.
 * @note This class has vectors for the ammo and medical supplies to separate the two supplies such that we can keep track of the size for both supplies.
*/

class ArmyBuilder
{
private:
	Army *army;		  // pointer to hold the army which we constructed
	std::string type; // specifies which type of army this builder will construct
	std::vector<UnitFactory *> *unitFactories;
	std::vector<SupplyFactory *> *supplyFactories;
	std::vector<ArmyComponent *> *individuals;
	std::vector<ArmyComponent *> *battalions;
	std::vector<Supply *> *supplies;

public:
	/// @brief Class constructor used to instantiate the object and initialize the type member variable
	/// @author Reuben Jooste (u21457060)
	/// @param type Specifies which type of army builder this class will construct
	/// @param unitFactories UnitFactories to choose from for creating the army
	/// @param supplyFactories SupplyFactories to choose from for creating the supplies
	/// @warning To instantiate the ArmyBuilder object, unit factories and supply factories vectors need be already defined.
	/// @note The type is used to specify which armies this builder will instantiate i.e. Land, Air or Sea.
	ArmyBuilder(std::string type, std::vector<UnitFactory *> *unitFactories, std::vector<SupplyFactory *> *supplyFactories);

	/// @brief Function to create individual army components (soldiers or vehicles)
	/// @author Reuben Jooste (u21457060)
	/// @return Pointer to a list used for storing pointers to ArmyComponents
	/// @note This function may return NULL if all the unit factories did not have the budget to create a single soldier or vehicle.
	std::vector<ArmyComponent *> *createIndividuals();

	/// @brief Function to create battalions which consist out of other battalions, soldiers or vehicles
	/// @author Reuben Jooste (u21457060)
	/// @return Pointer to a list of pointers to battalions
	/// @note This function may return NULL if all the unit factories did not have the budget to create a single soldier or vehicle.
	/// @note This function uses the "createIndividuals()" to build the battalions.
	std::vector<ArmyComponent *> *buildBattalions();

	/// @brief Function tp create supplies for the army
	/// @author Reuben Jooste (u21457060)
	/// @return Pointer to a list of pointers of Suppply objects (AmmoSupply or MedicalSupply)
	/// @note This function may return NULL if all the suppply factories did not have the budget to create a single ammo or medical supply.
	std::vector<Supply *> *determineSupplies();

	/// @brief This function is used to merge the different parts (objects) of an army into one Army object
	/// @author Reuben Jooste (u21457060)
	/// @return Completed Army object
	/// @note This function returns a Army object by call the Army class's constructor
	Army *putArmyTogether();

	/// @brief Function to receive the newly constructed Army object
	/// @author Reuben Jooste (u21457060)
	/// @return Member variable of constructed Army
	Army *getArmy();

	/// @brief This function is used to return the vector of individuals which was create by the createIndividuals() method
	/// @author Reuben Jooste (u21457060)
	/// @return Return vector of individual ArmyComponents
	/// @warning If this function returns NULL then the constructor initialised the member variable as NULL. This happens if a builder's constructor is called with the second argument as NULL.
	std::vector<ArmyComponent *> *getIndividuals();

	/// @brief This function is used to return the vector of battalions which was create by the buildBattalions() method
	/// @author Reuben Jooste (u21457060)
	/// @return Return vector of battalion ArmyComponents
	/// @warning If this function returns NULL then the constructor initialised the member variable as NULL. This happens if a builder's constructor is called with the second argument as NULL.
	std::vector<ArmyComponent *> *getBattalions();

	/// @brief This function is used to return the vector of supplies which was create by the determineSupplies() method
	/// @author Reuben Jooste (u21457060)
	/// @return Return vector of supplies
	/// @warning If this function returns NULL then the constructor initialised the member variable as NULL. This happens if a builder's constructor is called with the third argument as NULL.
	std::vector<Supply *> *getSupplies();

	/// @brief This function will set the member variable individuals in order to keep track of the individuals created
	/// @author Reuben Jooste (u21457060)
	/// @param individuals The parameter is used to set our member variable by making a deep copy of it.
	/// @warning If the parameter is NULL the member variable will NOT be set.
	/// @warning This function overwrites the current member variable because this function should only be called inside the buildBattalions() method and the createIndividuals() method. 
	void setIndividuals(std::vector<ArmyComponent *> *individuals);

	/// @brief This function will set the member variable battalions in order to keep track of the battalions created
	/// @author Reuben Jooste (u21457060)
	/// @param battalions The parameter is used to set our member variable by making a deep copy of it.
	/// @warning If the parameter is NULL the member variable will NOT be set.
	/// @warning This function overwrites the current member variable because this function should only be called inside the buildBattalions() method.
	void setBattalions(std::vector<ArmyComponent *> *battalions);

	/// @brief This function will set the member variable supplies in order to keep track of the supplies created
	/// @author Reuben Jooste (u21457060)
	/// @param supplies The parameter is used to set our member variable by making a deep copy of it.
	/// @warning If the parameter is NULL the member variable will NOT be set.
	/// @warning This function overwrites the current member variable because this function should only be called inside the determineSupplies() method.
	void setSupplies(std::vector<Supply *> *supplies);
};

#endif

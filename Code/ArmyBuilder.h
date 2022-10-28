#ifndef ARMYBUILDER_H
#define ARMYBUILDER_H
#include "Army.h"
#include "UnitFactory.h"
#include "SupplyFactory.h"
#include <iostream>
#include <vector>

class ArmyBuilder{
	private:
		Army *army; //pointer to hold the army which we constructed
		std::string type; //specifies which type of army this builder will construct
		std::vector<UnitFactory*>* unitFactories;
		std::vector<SupplyFactory*>* supplyFactories;
		std::vector<ArmyComponent*>* individuals;
		std::vector<ArmyComponent*>* battalions;
		std::vector<Supply*>* supplies;

	public:
		/// @brief Class constructor used to instantiate the object and initialize the type member variable
		/// @author Reuben Jooste (u21457060)
		/// @param type Specifies which type of army builder this class will construct 
		/// @param unitFactories UnitFactories to choose from for creating the army
		/// @param supplyFactories SupplyFactories to choose from for creating the supplies
		ArmyBuilder(std::string type, std::vector<UnitFactory*>* unitFactories, std::vector<SupplyFactory*>* supplyFactories);
		
		/// @brief Function to create individual army components (soldiers or vehicles)
		/// @author Reuben Jooste (u21457060)
		/// @return Pointer to a list used for storing pointers to ArmyComponents
		std::vector<ArmyComponent*>* createIndividuals();

		/// @brief Function to create battalions which consist out of other battalions, soldiers or vehicles
		/// @author Reuben Jooste (u21457060)
		/// @return Pointer to a list of pointers to battalions
		std::vector<ArmyComponent*>* buildBattalions();

		/// @brief Function tp create supplies for the army
		/// @author Reuben Jooste (u21457060)
		/// @return Pointer to a list of pointers of Suppply objects (AmmoSupply or MedicalSupply)
		std::vector<Supply*>* determineSupplies();

		/// @brief This function is used to merge the different parts (objects) of an army into one Army object
		/// @author Reuben Jooste (u21457060)
		/// @return Completed Amry object
		Army *putArmyTogether();

		/// @brief Function to receive the newly constructed Army object
		/// @author Reuben Jooste (u21457060)
		/// @return Member variable of constructed Army
		Army *getArmy();

		/// @brief This function is used to return the vector of individuals which was create by the createIndividuals() method
		/// @author Reuben Jooste (u21457060) 
		/// @return Return vector of individual ArmyComponents
		std::vector<ArmyComponent*>* getIndividuals();

		/// @brief This function is used to return the vector of battalions which was create by the buildBattalions() method
		/// @author Reuben Jooste (u21457060) 
		/// @return Return vector of battalion ArmyComponents
		std::vector<ArmyComponent*>* getBattalions();

		/// @brief This function is used to return the vector of supplies which was create by the determineSupplies() method
		/// @author Reuben Jooste (u21457060) 
		/// @return Return vector of supplies
		std::vector<Supply*>* getSupplies();

		/// @brief This function will set the member variable individuals in order to keep track of the individuals created
		/// @author Reuben Jooste (u21457060)
		/// @param individuals The parameter is used to set our member variable by making a deep copy of it.
		void setIndividuals(std::vector<ArmyComponent*>* individuals);

		/// @brief This function will set the member variable battalions in order to keep track of the battalions created
		/// @author Reuben Jooste (u21457060)
		/// @param battalions The parameter is used to set our member variable by making a deep copy of it.
		void setBattalions(std::vector<ArmyComponent*>* battalions);

		/// @brief This function will set the member variable supplies in order to keep track of the supplies created
		/// @author Reuben Jooste (u21457060)
		/// @param supplies The parameter is used to set our member variable by making a deep copy of it.
		void setSupplies(std::vector<Supply*>* supplies);
};

#endif

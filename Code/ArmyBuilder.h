#ifndef ARMYBUILDER_H
#define ARMYBUILDER_H
#include "Army.h"

class ArmyBuilder{
	private:
		Army *army; //pointer to hold the army which we constructed

	public:
		/// @brief Function to create individual army components (soldiers or vehicles)
		/// @author Reuben Jooste (u21457060)
		/// @return Pointer to a list used for storing pointers to ArmyComponents
		ArmyComponent **createIndividuals();

		/// @brief Function to create battalions which consist out of other battalions, soldiers or vehicles
		/// @author Reuben Jooste (u21457060)
		/// @return Pointer to a list of pointers to battalions
		ArmyComponent **buildBattalions();

		/// @brief Function tp create supplies for the army
		/// @author Reuben Jooste (u21457060)
		/// @return Pointer to a list of pointers of Suppply objects (AmmoSupply or MedicalSupply)
		Supply **determineSupplies();

		/// @brief This function is used to merge the different parts (objects) of an army into one Army object
		/// @author Reuben Jooste (u21457060)
		/// @return Completed Amry object
		Army *putArmyTogether();

		/// @brief Function to receive the newly constructed Army object
		/// @author Reuben Jooste (u21457060)
		/// @return Member variable of constructed Army
		Army *getArmy();
};

#endif

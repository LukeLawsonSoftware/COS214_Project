#ifndef SUPPLYFACTORY_H
#define SUPPLYFACTORY_H
#include "Supply.h"
#include <iostream>

/**
 * @class SupplyFactory SupplyFactory.h
 * 
 * This class is a necessity if a Country wants to create ammo supplies or medical supplies and send the supplies to the Country's army.
 * There are two types of factories:
 * - AmmoFactory
 * - MedicalFactory
 * 
 */

class SupplyFactory
{
	public:
		/// @brief Class constructor for the SuplyFactory which will initialize the budget of the factory as well as set the level to 1.
		/// @author Arno Jooste (u21457451)
		/// @param budget The amount that can be spent to make supplies.
		/// @param type The type of supply factory that will be created.
		/// @warning The budget must be a interger value greater than zero.
		SupplyFactory(int budget, std::string type);

		/// @brief Class destructor to reset the member variables.
		/// @author Arno Jooste (u21457451)
		virtual ~SupplyFactory();

		/// @brief Factory method to let AmmoFactory and MedicalFactory create the AmmoSupply and MedicalSupply products, respectively.
		/// @author Arno Jooste (u21457451)
		/// @return pointer to newly created Supply product (it will be either a MedicalSupply or AmmoSupply).
		virtual Supply *makeSupply(int quantity) = 0;

		/// @brief Upgrades the factory, which will increase the budget capacity and level.
		/// @author Arno Jooste (u21457451)
		void upgrade();

		/// @brief Sets a new budget for the factory (it will mostly be used by the upgrade() method to increase/set a new budget).
		/// @author Arno Jooste (u21457451)
		/// @param newBudget 
		/// @warning The input must be a value greater than zero.
		/// @note This function only increases the current budget by the given parameter.
		void setBudget(int newBudget);

		/// @brief Getter for the current budget of the factory in order to get access to the private member variable.
		/// @author Arno Jooste (u21457451)
		/// @return current budget of type int.
		int getBudget();

		/// @brief Getter for the current level of the factory in order to get access to the private member variable.
		/// @author Arno Jooste (u21457451)
		/// @return current factory level of type int.
		int getLevel();

		/// @brief Getter for the total amount spent so far by the factory. This will be used to test if the factory can produce more supplies based on the budget capacity.
		/// @author Arno Jooste (u21457451)
		/// @return current amount spent of type int.
		/// @note This helps us to keep track of how much we already spent on supplies.
		int getTotalSpent();

		/// @brief Getter for the type of factory ,either an Ammo or a medical factory
		/// @author Reuben Jooste (u21457060)
		/// @return Type of factory
		std::string getType();

	protected:		
		double totalSpent;

	private:
		int budget;
		int level;
		std::string type;
};

#endif

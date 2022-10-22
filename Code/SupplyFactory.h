#ifndef SUPPLYFACTORY_H
#define SUPPLYFACTORY_H
#include "Supply.h"

class SupplyFactory
{

	private:
		int budget;

	protected:		
		double totalSpent;

	private:
		int level;

	public:
		/// @brief Factory method to let AmmoFactory and MedicalFactory create the AmmoSupply and MedicalSupply products, respectively.
		/// @author Arno Jooste (u21457451)
		/// @return pointer to newly created Supply product (it will be either a MedicalSupply or AmmoSupply).
		virtual Supply *makeSupply() = 0;

		/// @brief Upgrades the factory, which will increase the budget capacity and level.
		/// @author Arno Jooste (u21457451)
		void upgrade();

		/// @brief Sets a new budget for the factory (it will mostly be used by the upgrade() method to increase/set a new budget).
		/// @author Arno Jooste (u21457451)
		/// @param newBudget 
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
		int getTotalSpent();
};

#endif

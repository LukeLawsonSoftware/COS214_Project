#ifndef CIVILIAN_H
#define CIVILIAN_H
#include "NonCombatEntity.h"
#include <string>


class Civilian : public NonCombatEntity
{
	
	public:

		/// @brief A default constructor that sets the designation to a citizen
		/// @author Jonelle Coertze (u21446271)
		Civilian();

		/// @brief a parameterized constructor to craete a new Civilian with a specific designation
		/// @author Jonelle Coertze (u21446271)
		/// @param Designation string to indicate if a civilian is a refugee or a citizen
		Civilian(std::string Designation);

		/// @brief clone the current Civilian
		/// @author Jonelle Coertze (u21446271)
		/// @return a pointer to the cloned/new NonCombatEntity : Civilian
		NonCombatEntity *clone();

		/// @brief set the attribute designation, which can be a refugee or a citizen
		/// @author Jonelle Coertze (u21446271)
		/// @param Designation string to indicate if a civilian is a refugee or a citizen
		void setDesignation(std::string Designation);

		/// @brief get the attribute designation, which can be a refugee or a citizen
		/// @author Jonelle Coertze (u21446271)
		/// @return a string to indicate if a civilian is a refugee or a citizen
		std::string getDesignation();

	private:
		std::string designation; // : is a refugee or a citizen

};

#endif

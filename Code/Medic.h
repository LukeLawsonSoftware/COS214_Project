#ifndef MEDIC_H
#define MEDIC_H
#include "NonCombatEntity.h"

class Medic : public NonCombatEntity
{

	public:

		/// @brief A default constructor that generates the amount of healing of a Medic
		Medic();

		/// @brief a parameterized constructor to be used in the clone function
		/// @param Healing an integer to set the healing of the Medic
		Medic(int Healing);

		/// @brief clone the current Medic
		/// @author Jonelle Coertze (u21446271)
		/// @return a pointer to the cloned/new NonCombatEntity : Medic
		NonCombatEntity *clone();

		/// @brief get a random number between 1 and 10 that can be seen as the healing value
		/// @author Jonelle Coertze (u21446271)
		/// @return a integer to indicate the amount of healing of a Medic
		int getHealing() ; // returns an int 1-10

	private:
		int healing; // random number betwween 1 and 10
};

#endif

#ifndef ARMYDIRECTOR_H
#define ARMYDIRECTOR_H
#include "ArmyBuilder.h"

class ArmyDirector{
	private:
		ArmyBuilder *builder;

	public:
		/// @brief Constructor for the ArmyDirector class to instantiate the object and set the member variable
		/// @author Reuben Jooste (u21457060)
		/// @param builder pointer to an existing ArmyBuilder object used to set this class' member variable
		ArmyDirector(ArmyBuilder* builder);
		
		/// @brief This function is used to construct an army which will be used by the Country to fight the war
		/// @author Reuben Jooste (u21457060)
		void constructArmy();
};

#endif

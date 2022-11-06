#ifndef ARMYDIRECTOR_H
#define ARMYDIRECTOR_H

class ArmyBuilder;

/**
 * @class ArmyDirector ArmyDirector.h
 * 
 * The ArmyDirector class is a big component in the War since we use this class to command the ArmyBuilder to build the Country's army.
 * - Each country must have a director otherwise the country will not be able to build any armies.
 * - The director receives the command "raise army" from the millitary commander and then only instructs the ArmyBuilder to build the army. 
 * @warning If the member variable (builder) is NULL we cannot build the army.
*/

class ArmyDirector
{
private:
	ArmyBuilder *builder;

public:
	/// @brief Constructor for the ArmyDirector class to instantiate the object and set the member variable
	/// @author Reuben Jooste (u21457060)
	/// @param builder pointer to an existing ArmyBuilder object used to set this class' member variable
	/// @warning The parameter MUST NOT BE NULL otherwise the it is impossible to build an army for a Country.
	ArmyDirector(ArmyBuilder *builder);

	/// @brief This function is used to construct an army which will be used by the Country to fight the war
	/// @author Reuben Jooste (u21457060)
	void constructArmy();
};

#endif

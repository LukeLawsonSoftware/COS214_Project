#ifndef BATTALION_H
#define BATTALION_H
#include "ArmyComponent.h"
#include <vector>

class Battalion : public ArmyComponent
{

private:
	std::vector<ArmyComponent *> members;

public:
	/// @brief Traverses members to get the sum of the AirOffence statistics. This is the statistic value for the Battalio
	/// @author Luke Lawson (u21433811)
	/// @return int value for AirOffence statistic of Battalion
	int calculateAirOffense();

	/// @brief Traverses members to get the sum of the AirDefence statistics. This is the statistic value for the Battalion
	/// @author Luke Lawson (u21433811)
	/// @return int value for AirDefence statistic of Battalion
	int calculateAirDefense();

	/// @brief Traverses members to get the sum of the SeaOffence statistics. This is the statistic value for the Battalion
	/// @author Luke Lawson (u21433811)
	/// @return int value for SeaOffence statistic of Battalion
	int calculateSeaOffense();

	/// @brief Traverses members to get the sum of the SeaDefence statistics. This is the statistic value for the Battalion
	/// @author Luke Lawson (u21433811)
	/// @return int value for SeaDefence statistic of Battalion
	int calculateSeaDefense();

	/// @brief Traverses members to get the sum of the LandOffence statistics. This is the statistic value for the Battalion
	/// @author Luke Lawson (u21433811)
	/// @return int value for LandOffence statistic of Battalion
	int calculateLandOffense();

	/// @brief Traverses members to get the sum of the LandDefence statistics. This is the statistic value for the Battalion
	/// @author Luke Lawson (u21433811)
	/// @return int value for LandDefence statistic of Battalion
	int calculateLandDefense();

	/// @brief Adds ArmyComponent to this Composite object
	/// @author Luke Lawson (u21433811)
	/// @param newMember new ArmyComponent pointer to add to members vector
	void addMember(ArmyComponent *newMember);
};

#endif

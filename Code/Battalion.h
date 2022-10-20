#ifndef BATTALION_H
#define BATTALION_H
#include "ArmyComponent.h"
#include <vector>

class Battalion : public ArmyComponent
{

public:
	std::vector<ArmyComponent *> members;

	int calculateAirOffense();

	int calculateAirDefense();

	int calculateSeaOffense();

	int calculateSeaDefense();

	int calculateLandOffense();

	int calculateLandDefense();

	void addMember(ArmyComponent *newMember);
};

#endif

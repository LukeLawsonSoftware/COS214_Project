#ifndef ARMYCOMPONENT_H
#define ARMYCOMPONENT_H
#include <cstdlib>
#include <cmath>
#include <ctime>

class ArmyComponent
{

public:
	virtual int calculateAirOffense() = 0;

	virtual int calculateAirDefense() = 0;

	virtual int calculateSeaOffense() = 0;

	virtual int calculateSeaDefense() = 0;

	virtual int calculateLandOffense() = 0;

	virtual int calculateLandDefense() = 0;

	virtual void addMember(ArmyComponent *newMember) = 0;
};

#endif

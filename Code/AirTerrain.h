#ifndef AIRTERRAIN_H
#define AIRTERRAIN_H

#include "WarTheatre.h"

class AirTerrain : public WarTheatre
{

private:
	// apply bonus to airOffense stats of both armies
	void adjustAttack();

	// apply bonus to airDefence stats of both armies
	void adjustDefence();
};

#endif

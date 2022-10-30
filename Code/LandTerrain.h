#ifndef LANDTERRAIN_H
#define LANDTERRAIN_H
#include "WarTheatre.h"

class LandTerrain : public WarTheatre
{

private:
	// apply bonus to landOffense stats of both armies
	void adjustAttack();

	// apply bonus to landDefence stats of both armies
	void adjustDefence();
};

#endif

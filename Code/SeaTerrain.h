#ifndef SEATERRAIN_H
#define SEATERRAIN_H
#include "WarTheatre.h"

class SeaTerrain : public WarTheatre
{

private:
	// apply bonus to seaOffense stats of both armies
	void adjustAttack();

	// apply bonus to seaDefence stats of both armies
	void adjustDefence();
};

#endif

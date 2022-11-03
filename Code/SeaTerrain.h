#ifndef SEATERRAIN_H
#define SEATERRAIN_H
#include "WarTheatre.h"

class SeaTerrain : public WarTheatre
{
public:
	SeaTerrain();

private:
	/// @brief a function to apply bonus to seaOffense stats of both armies
	/// @author Jonelle Coertze (u21446271)
	void adjustAttack();

	/// @brief a function to apply bonus to seaDefence stats of both armies
	/// @author Jonelle Coertze (u21446271)
	void adjustDefence();
};

#endif

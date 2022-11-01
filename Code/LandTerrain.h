#ifndef LANDTERRAIN_H
#define LANDTERRAIN_H
#include "WarTheatre.h"

class LandTerrain : public WarTheatre
{
	private:
		/// @brief a function to apply bonus to landOffense stats of both armies
		/// @author Jonelle Coertze (u21446271)
		void adjustAttack();

		/// @brief a function to apply bonus to landDefence stats of both armies
		/// @author Jonelle Coertze (u21446271)
		void adjustDefence();
};

#endif

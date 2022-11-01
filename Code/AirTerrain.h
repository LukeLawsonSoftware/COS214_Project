#ifndef AIRTERRAIN_H
#define AIRTERRAIN_H

#include "WarTheatre.h"

class AirTerrain : public WarTheatre
{
	private:
		/// @brief a function to apply bonus to airOffense stats of both armies
		/// @author Jonelle Coertze (u21446271)
		void adjustAttack();

		/// @brief a function to apply bonus to airDefence stats of both armies
		/// @author Jonelle Coertze (u21446271)
		void adjustDefence();
};

#endif

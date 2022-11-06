#ifndef AIRTERRAIN_H
#define AIRTERRAIN_H

#include "WarTheatre.h"
/**
 * @class AirTerrain AirTerrain.h
 * @ref WarTheatre.h "(See the definition of the WarTheatre class)"
 * 
 * The AirTerrain class is a derived class derived from the WarTheatre class
 * The AirTerrain will be used to create an Air Terrain Theatre where the war can will take place.
 * @note This class is used to expand the War by adding a new Theatre to it.
*/
class AirTerrain : public WarTheatre
{
public:
	/// @brief This is the default constructor of the class.
	/// @author Jonelle Coertze (u21446271)
	AirTerrain();

private:
	/// @brief a function to apply bonus to airOffense stats of both armies
	/// @author Jonelle Coertze (u21446271)
	void adjustAttack();

	/// @brief a function to apply bonus to airDefence stats of both armies
	/// @author Jonelle Coertze (u21446271)
	void adjustDefence();
};

#endif

#ifndef LANDTERRAIN_H
#define LANDTERRAIN_H
#include "WarTheatre.h"

/**
 * @class LandTerrain LandTerrain.h
 * @ref WarTheatre.h "(See the definition of the WarTheatre class)"
 * 
 * The LandTerrain class is a derived class derived from the WarTheatre class
 * The LandTerrain will be used to create a Land Terrain Theatre where the war can will take place.
 * @note This class is used to expand the War by adding a new Theatre to it.
*/
class LandTerrain : public WarTheatre
{
public:
	/// @brief This is the default constructor of the class.
	/// @author Jonelle Coertze (u21446271)
	LandTerrain();

private:
	/// @brief a function to apply bonus to landOffense stats of both armies
	/// @author Jonelle Coertze (u21446271)
	void adjustAttack();

	/// @brief a function to apply bonus to landDefence stats of both armies
	/// @author Jonelle Coertze (u21446271)
	void adjustDefence();
};

#endif

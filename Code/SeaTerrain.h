#ifndef SEATERRAIN_H
#define SEATERRAIN_H
#include "WarTheatre.h"

/**
 * @class SeaTerrain SeaTerrain.h
 * @ref WarTheatre.h "(See the definition of the WarTheatre class)"
 * 
 * The SeaTerrain class is a derived class derived from the WarTheatre class
 * The SeaTerrain will be used to create a Sea Terrain Theatre where the war can will take place.
 * @note This class is used to expand the War by adding a new Theatre to it.
*/
class SeaTerrain : public WarTheatre
{
public:
	/// @brief This is the default constructor of the class.
	/// @author Jonelle Coertze (u21446271)
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

#include "MoveIntoTheatre.h"

void MoveIntoTheatre::execute()
{
	army->setBattleField(theatre);
	// theatre->addArmy(army); this is done by the above method
}

void MoveIntoTheatre::setTheatre(WarTheatre *in)
{
	theatre = in;
}
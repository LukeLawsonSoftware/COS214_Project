#include "MoveIntoTheatre.h"

void MoveIntoTheatre::execute()
{
	army->setBattleField(theatre);
	theatre->addArmy(army);
}

void MoveIntoTheatre::setTheatre(WarTheatre *in)
{
	theatre = in;
}
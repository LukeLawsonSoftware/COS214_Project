#include "MidPhase.h"

void MidPhase::handleChange(War *inWar)
{
	inWar->setWarPhase(new LateCrisis());
}

MidPhase::MidPhase()
{
	peaceChance = 0;
}
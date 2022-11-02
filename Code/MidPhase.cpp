#include "MidPhase.h"
#include "War.h"
#include "LateCrisis.h"

void MidPhase::handleChange(War *inWar)
{
	inWar->setWarPhase(new LateCrisis());
}

MidPhase::MidPhase()
{
	std::cout << "All out war has broken out." << std::endl;
	peaceChance = 0;
}
#include "Medic.h"
#include <ctime>
#include <cstdlib>

Medic::Medic()
{
	srand(time(0)); 
	healing = (rand()%10 + 1) ;
}

Medic::Medic(int Healing)
{
	healing = Healing;
}

NonCombatEntity* Medic::clone() {
	return new Medic(healing);
}

int Medic::getHealing()
{
	return healing;
}
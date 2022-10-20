#ifndef MEDIC_H
#define MEDIC_H
#include "NonCombatEntity.h"

class Medic : public NonCombatEntity
{

public:
	NonCombatEntity *clone();
};

#endif

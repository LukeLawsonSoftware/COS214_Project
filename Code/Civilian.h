#ifndef CIVILIAN_H
#define CIVILIAN_H
#include "NonCombatEntity.h"

class Civilian : public NonCombatEntity
{

public:
	NonCombatEntity *clone();
};

#endif

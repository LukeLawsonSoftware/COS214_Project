#include "LateOpenConflict.h"
LateOpenConflict::LateOpenConflict()
{
    next = new LateUnstablePeace();
    peaceChance = 0.35;
}
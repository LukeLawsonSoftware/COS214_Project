#include "EarlyPeace.h"

EarlyPeace::EarlyPeace()
{
    next = new EarlyUnstablePeace();
    peaceChance = 1;
}
#include "EarlyUnstablePeace.h"

EarlyUnstablePeace::EarlyUnstablePeace()
{
    outputChange();
    next = new EarlyOpenConflict();
    peaceChance = 0.6;
}

void EarlyUnstablePeace::outputChange()
{
    std::cout << "A period of unstable peace has begun." << std::endl;
}
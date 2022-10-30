#include "LateCrisis.h"
LateCrisis::LateCrisis()
{
    outputChange();
    next = new LateOpenConflict();
    peaceChance = 0.2;
}

void LateCrisis::outputChange()
{
    std::cout << "The war has declined to a crisis." << std::endl;
}
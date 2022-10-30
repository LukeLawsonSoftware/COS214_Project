#include "LateOpenConflict.h"
LateOpenConflict::LateOpenConflict()
{
    next = new LateUnstablePeace();
    peaceChance = 0.35;
}

void LateOpenConflict::outputChange()
{
    std::cout << "The war has further declined to occasional open conflict." << std::endl;
}
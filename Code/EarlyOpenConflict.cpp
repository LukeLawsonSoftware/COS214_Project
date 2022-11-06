#include "EarlyOpenConflict.h"

EarlyOpenConflict::EarlyOpenConflict()
{

    next = new EarlyCrisis();
    peaceChance = 0.035;
}

void EarlyOpenConflict::outputChange()
{
    std::cout << "Open conflict has started to occur." << std::endl;
}
#include "EarlyCrisis.h"
EarlyCrisis::EarlyCrisis()
{

    next = nullptr;
    peaceChance = 0.02;
}

void EarlyCrisis::outputChange()
{
    std::cout << "The tensions have developed to a crisis." << std::endl;
}
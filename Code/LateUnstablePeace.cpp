#include "LateUnstablePeace.h"
LateUnstablePeace::LateUnstablePeace()
{
    next = new LatePeace();
    peaceChance = 0.6;
}

void LateUnstablePeace::outputChange()
{
    std::cout << "The war is now in a phase of unstable peace." << std::endl;
}
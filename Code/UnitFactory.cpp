#include "UnitFactory.h"

int UnitFactory::determineActualLevel()
{
    int actualLevel = 0;
    if (this->level <= 1)
    {
        actualLevel = 1;
    }
    else if (this->level >= 10)
    {
        actualLevel = 10;
    }
    else
    {
        actualLevel = this->level;
    }
    return actualLevel;
}

std::string UnitFactory::getType(){
    return type;
}
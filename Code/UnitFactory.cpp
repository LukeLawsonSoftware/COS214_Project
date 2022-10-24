#include "UnitFactory.h"

UnitFactory::UnitFactory(double b, int l, std::string t){
    cost = b;//starting budget
    level = l; //starting level
    totalSpent = 0;
    type = t;
}

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

double UnitFactory::getTotalSpent(){
    return totalSpent;
}

double UnitFactory::getBudget(){
    return cost;
}

void UnitFactory::increaseTotalSpent(double addedCost){
    totalSpent += addedCost;
}

void UnitFactory::setNewBudget(double newBudget){
    cost = newBudget;
}
#include "BattleStatistics.h"

int BattleStatistics::getAirAttack()
{
    return airAttack;
}
int BattleStatistics::getAirDefence()
{
    return airDefence;
}
int BattleStatistics::getLandAttack()
{
    return landAttack;
}
int BattleStatistics::getLandDefence()
{
    return landDefence;
}
int BattleStatistics::getSeaAttack()
{
    return seaAttack;
}
int BattleStatistics::getSeaDefence()
{
    return seaDefence;
}
int BattleStatistics::getMorale()
{
    return morale;
}
int BattleStatistics::getAvailableAmmo()
{
    return availableAmmo;
}
int BattleStatistics::getMedical()
{
    return medical;
}

void BattleStatistics::setAirAttack(int in)
{
    this->airAttack = in;
}
void BattleStatistics::setAirDefence(int in)
{
    this->airDefence = in;
}
void BattleStatistics::setLandAttack(int in)
{
    this->landAttack = in;
}
void BattleStatistics::setLandDefence(int in)
{
    this->landDefence = in;
}
void BattleStatistics::setSeaAttack(int in)
{
    this->seaAttack = in;
}
void BattleStatistics::setSeaDefence(int in)
{
    this->seaDefence = in;
}
void BattleStatistics::setMorale(int in)
{
    this->morale = in;
}
void BattleStatistics::setAvailableAmmo(int in)
{
    this->availableAmmo = in;
}
void BattleStatistics::setMedical(int in)
{
    this->medical = in;
}
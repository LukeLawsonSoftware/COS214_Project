#include "EarlyOpenConflict.h"

EarlyOpenConflict::EarlyOpenConflict()
{
    next = new EarlyCrisis();
    peaceChance = 0.35;
}
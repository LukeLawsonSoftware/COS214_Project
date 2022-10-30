#ifndef EARLYOPENCONFLICT_H
#define EARLYOPENCONFLICT_H
#include "EarlyCrisis.h"

class EarlyOpenConflict : public EarlyPhase
{
public:
    /// @brief Sets next to EarlyCrisis and peaceChance.
    /// @author Thomas Blendulf (u21446131)
    EarlyOpenConflict();
    void outputChange();
};

#endif

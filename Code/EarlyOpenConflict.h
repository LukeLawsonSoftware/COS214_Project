#ifndef EARLYOPENCONFLICT_H
#define EARLYOPENCONFLICT_H
#include "EarlyCrisis.h"

class EarlyOpenConflict : public EarlyPhase
{
public:
    /// @brief Sets next to EarlyCrisis and peaceChance.
    /// @author Thomas Blendulf (u21446131)
    EarlyOpenConflict();

    /// @brief This function just shows when there was a change to the current WarPhase.
    /// @author Thomas Blendulf (u21446131)
    void outputChange();
};

#endif

#ifndef EARLYCRISIS_H
#define EARLYCRISIS_H
#include "EarlyPhase.h"

class EarlyCrisis : public EarlyPhase
{
public:
    /// @brief Sets next to null and peaceChance.
    /// @author Thomas Blendulf (u21446131)
    EarlyCrisis();

    /// @brief This function just shows when there was a change to the current WarPhase.
    /// @author Thomas Blendulf (u21446131)
    void outputChange();
};

#endif

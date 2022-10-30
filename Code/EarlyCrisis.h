#ifndef EARLYCRISIS_H
#define EARLYCRISIS_H
#include "EarlyPhase.h"

class EarlyCrisis : public EarlyPhase
{
public:
    /// @brief Sets next to null and peaceChance.
    /// @author Thomas Blendulf (u21446131)
    EarlyCrisis();
    void outputChange();
};

#endif

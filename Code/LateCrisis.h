#ifndef LATECRISIS_H
#define LATECRISIS_H
#include "LateOpenConflict.h"

class LateCrisis : public LatePhase
{
public:
    /// @brief Sets next to LateOpenConflict.
    /// @author Thomas Blendulf (u21446131)

    LateCrisis();
    void outputChange();
};

#endif

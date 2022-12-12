#pragma once
#include "DataTypes.h"

class IWorldEvents {
public:
    virtual void subscribeWorldEvent(worldevent eventType, eventfn fun, void *source, void *target) = 0;
    virtual void emitWorldEvent(worldevent eventType, void *data) = 0;
};


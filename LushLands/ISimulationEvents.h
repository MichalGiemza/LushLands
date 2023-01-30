#pragma once
#include "DataTypes.h"
#include "Events.h"
#include "EventTypes.h"

class ISimulationEvents {
public:
    virtual void update(miliseconds dt) = 0;
    virtual void subscribeEvent(simulationevent eventType, eventfn fun, void *source, void *target) = 0;
    virtual void emitEvent(simulationevent eventType, void *data) = 0;
};


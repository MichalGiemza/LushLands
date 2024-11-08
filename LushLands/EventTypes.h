#pragma once
#include <functional>
#include "DataTypes.h"

typedef std::function<void(ALLEGRO_EVENT *allegroEvent, void *caller)> eventfn;
typedef std::function<void(miliseconds timeNow, miliseconds dt, void *caller)> updatefn;
typedef std::function<void(void *caller)> defaultfn;

struct SimpleSubscription {
    defaultfn func;
    void *caller;
};

struct EventSubscription {
    eventfn func;
    void *caller;
};

typedef EventSubscription KeySubscribtion;
typedef EventSubscription MouseAxisSubscribtion;

struct TimerSubscription {
    tickperiod period;
    int64_t lastTickExecutedOn;
    eventfn func;
    void *caller;
};

struct EntityUpdateSubscription {
    tickperiod period;
    int64_t lastTickExecutedOn;
    updatefn update;
    void *caller;
};

struct SystemEventSubscription {
    systemevent systemEvent;
    eventfn func;
    void *caller;
};

struct LoggerSubscription {
    loglevel logLevel;
    std::function<void(void *caller, char *msg)> func;
    void *caller;
};

struct SimulationEventSubscription {
    simulationevent eventType;
    eventfn func;
    void *source;
    void *target;
};

#pragma once
#include <allegro5/events.h>
#include <functional>
#include "DataTypes.h"

typedef std::function<void(ALLEGRO_EVENT *allegroEvent, void *caller)> eventfn;


struct KeySubscribtion {
    eventfn func;
    void *caller;
};

struct TimerSubscription {
    tickperiod period;
    int64_t lastTickExecutedOn;
    eventfn func;
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
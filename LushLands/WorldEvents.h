#pragma once
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include "InputEvents.h"
#include "IWorldEvents.h"
#include "EventHandler.h"


struct WorldEventSubscription {
    worldevent eventType;
    eventfn func;
    void *source;
    void *target;
};

class WorldEvents : IWorldEvents {
    /** 
    * Manages events within world.
    * Events are being handled, when "update" method is called by InputEvents.
    */
    ALLEGRO_EVENT_SOURCE *worldEventSource;
    ALLEGRO_EVENT_QUEUE *eventQueue;
    std::unordered_map<int, std::vector<WorldEventSubscription>> subscribers;
public:
    WorldEvents(EventHandler *eventHandler);
    void update();
    virtual void subscribeWorldEvent(worldevent eventType, eventfn fun, void *source, void *target) override;
    virtual void emitWorldEvent(worldevent eventType, void *data) override;
};


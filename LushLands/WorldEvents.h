#pragma once
#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include "InputEvents.h"
#include "ISimulationEvents.h"
#include "EventHandler.h"
#include "Events.h"
#include "EventTypes.h"
#include "Player.h"
#include "AngleTools.h"


class WorldEvents : public ISimulationEvents {
    /** 
    * Manages events within world.
    * Events are being handled, when "update" method is called by InputEvents.
    */
    Player *player;
    ALLEGRO_EVENT_SOURCE *worldEventSource;
    ALLEGRO_EVENT_QUEUE *eventQueue;
    std::unordered_map<int, std::vector<SimulationEventSubscription>> subscribers;
public:
    WorldEvents(EventHandler *eventHandler);
    virtual void update(miliseconds timeNow, miliseconds dt) override;
    virtual void subscribeEvent(simulationevent eventType, eventfn fun, void *source, void *target) override;
    virtual ALLEGRO_EVENT_SOURCE *getEventSource() override;
    void registerPlayer(Player *player);
};


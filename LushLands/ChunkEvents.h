#pragma once
#include <allegro5/events.h>
#include <unordered_map>
#include "ISimulationEvents.h"
#include "EventHandler.h"
#include "DynamicCollider.h"
#include "Position.h"
#include "WorldEvents.h"
#include "ChunkEventHandler.h"
#include <set>


class ChunkEvents : public ISimulationEvents {
    /**
    * System do obs³ugi eventów w obrêbie jednego chunka.
    */
    ALLEGRO_EVENT_SOURCE *chunkEventSource;
    ALLEGRO_EVENT_QUEUE *eventQueue;
    std::unordered_map<int, std::vector<SimulationEventSubscription>> subscribers;
    ChunkEventHandler chunkEventHandler;
    std::set<TimerSubscription *> toUpdate;
public:
    ChunkEvents(EventHandler *eventHandler, ChunkPosition *chunkPosition, CollisionManager *collisionManager);
    virtual void update(miliseconds dt) override;
    virtual void subscribeEvent(simulationevent eventType, eventfn fun, void *source, void *target) override;
    virtual void emitEvent(simulationevent eventType, void *data) override;
    void subscribeUpdate(TimerSubscription *ts);
    void unsubscribeUpdate(TimerSubscription *ts);
};


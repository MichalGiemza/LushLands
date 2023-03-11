#pragma once
#include <allegro5/events.h>
#include <unordered_map>
#include <set>
#include "ISimulationEvents.h"
#include "EventHandler.h"
#include "DynamicCollider.h"
#include "Position.h"
#include "WorldEvents.h"
#include "ChunkEventHandler.h"
#include "EntityUpdater.h"


class ChunkEvents : public ISimulationEvents {
    /**
    * System do obs�ugi event�w w obr�bie jednego chunka.
    */
    ALLEGRO_EVENT_SOURCE *chunkEventSource;
    ALLEGRO_EVENT_QUEUE *eventQueue;
    std::unordered_map<int, std::vector<SimulationEventSubscription>> subscribers;
    ChunkEventHandler chunkEventHandler;
    std::set<TimerSubscription *> toUpdate; // Fixme: To remove?
    std::unordered_set<Entity *> *randomTickEntities; // Fixme: B�dzie problem z castowaniem!
    std::unordered_set<EntityUpdater *> *toUpdateEntities;
public:
    ChunkEvents(ChunkPosition *chunkPosition, CollisionManager *collisionManager, std::unordered_set<Entity *> *randomTickEntities, std::unordered_set<EntityUpdater *> *toUpdateEntities);
    virtual void update(miliseconds timeNow, miliseconds dt) override;
    virtual void subscribeEvent(simulationevent eventType, eventfn fun, void *source, void *target) override;
    virtual ALLEGRO_EVENT_SOURCE *getEventSource() override;
    void subscribeUpdate(TimerSubscription *ts);
    void unsubscribeUpdate(TimerSubscription *ts);
};

#pragma once
#include <allegro5/events.h>
#include <unordered_map>
#include "ISimulationEvents.h"
#include "EventHandler.h"
#include "DynamicCollider.h"
#include "Position.h"
#include "Chunk.h"
#include "WorldEvents.h"


class ChunkEvents : public ISimulationEvents {
    /**
    * System do obs³ugi eventów w obrêbie jednego chunka.
    */
    ALLEGRO_EVENT_SOURCE *chunkEventSource;
    ALLEGRO_EVENT_QUEUE *eventQueue;
    std::unordered_map<int, std::vector<SimulationEventSubscription>> subscribers;
    Chunk *chunk;
public:
    ChunkEvents(EventHandler *eventHandler, Chunk *chunk);
    virtual void update(miliseconds dt) override;
    virtual void subscribeEvent(simulationevent eventType, eventfn fun, void *source, void *target) override;
    virtual void emitEvent(simulationevent eventType, void *data) override;
};


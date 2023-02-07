#include "ChunkEvents.h"

ChunkEvents::ChunkEvents(EventHandler *eventHandler, ChunkPosition *chunkPosition, CollisionManager *collisionManager) :
    chunkEventHandler(collisionManager) {
    eventHandler->registerChunkEvents(*chunkPosition, this);
    toUpdate = std::set<TimerSubscription *>();
    // Queue
    eventQueue = al_create_event_queue();
    if (!eventQueue)
        throw std::logic_error(could_not_create_event_queue);
    // Chunk Events
    chunkEventSource = new ALLEGRO_EVENT_SOURCE();
    al_init_user_event_source(chunkEventSource);
    al_register_event_source(eventQueue, chunkEventSource);
}

void ChunkEvents::update(miliseconds dt) {
    /** This method needs to be called from WorldEvents once every tick. */
    // Prepare loop
    ALLEGRO_EVENT *currentEvent = new ALLEGRO_EVENT();
    // Start loop
    while (al_get_next_event(eventQueue, currentEvent)) {
        if (not ALLEGRO_EVENT_TYPE_IS_USER(currentEvent->type))
            throw new std::logic_error(system_event_in_chunk_event_queue);

        switch (currentEvent->type) {
        case mob_attempt_go:
            chunkEventHandler.handleMobMovementAttempt(currentEvent);
            break;
        default:
            break;
        }
    }
}

void ChunkEvents::subscribeEvent(simulationevent eventType, eventfn fun, void *source, void *target) {
    auto p = SimulationEventSubscription { eventType, fun, source, target };
    subscribers[eventType].push_back(p);
}

void ChunkEvents::emitEvent(simulationevent eventType, void *data) {
    al_emit_user_event(chunkEventSource, (ALLEGRO_EVENT *)data, NULL);
}

void ChunkEvents::subscribeUpdate(TimerSubscription *ts) {
    toUpdate.insert(ts);
}

void ChunkEvents::unsubscribeUpdate(TimerSubscription *ts) {
    toUpdate.erase(ts);
}

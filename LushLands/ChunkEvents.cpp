#include "ChunkEvents.h"

ChunkEvents::ChunkEvents(ChunkPosition *chunkPosition, CollisionManager *collisionManager, ChunkElements *ce, std::unordered_set<Entity *> *randomTickEntities, std::unordered_set<EntityUpdater *> *toUpdateEntities) :
    chunkEventHandler(collisionManager, ce), randomTickEntities(randomTickEntities), toUpdateEntities(toUpdateEntities), ce(ce) {
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

void ChunkEvents::update(miliseconds timeNow, miliseconds dt) {
    /** This method needs to be called from WorldEvents once every tick. */
    // Prepare loop
    ALLEGRO_EVENT *currentEvent = new ALLEGRO_EVENT();
    // Start loop
    while (al_get_next_event(eventQueue, currentEvent)) {
        if (not ALLEGRO_EVENT_TYPE_IS_USER(currentEvent->type))
            throw new std::logic_error(system_event_in_chunk_event_queue);

        switch (currentEvent->type) {
        case mobility_attempt_go:
            chunkEventHandler.handleMobMovementAttempt(currentEvent);
            break;
        case item_drop: // TODO: Mo¿e niech te metody subskrybuj¹ ChunkEventy, a nie bêd¹ przez niego wywo³ywane?
            chunkEventHandler.handleItemDrop(currentEvent);
            break;
        default:
            break;
        }
    }
    // Update Updateable entities
    for (EntityUpdater *en : *toUpdateEntities) {
        en->updateEntity(timeNow, dt);
    }
    // Item Collection
    chunkEventHandler.handleItemCollection(); // TODO: Czy musi byæ na ka¿dym update?
    // RandomTick 
    // TODO
}

void ChunkEvents::subscribeEvent(simulationevent eventType, eventfn fun, void *source, void *target) {
    auto p = SimulationEventSubscription { eventType, fun, source, target };
    subscribers[eventType].push_back(p);
}

ALLEGRO_EVENT_SOURCE *ChunkEvents::getEventSource() {
    return chunkEventSource;
}

void ChunkEvents::subscribeUpdate(TimerSubscription *ts) { // Fixme: To remove?
    toUpdate.insert(ts);
}

void ChunkEvents::unsubscribeUpdate(TimerSubscription *ts) { // Fixme: To remove?
    toUpdate.erase(ts);
}

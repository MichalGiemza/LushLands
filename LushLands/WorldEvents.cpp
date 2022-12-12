#include "WorldEvents.h"

WorldEvents::WorldEvents(EventHandler *eventHandler) {
    subscribers = std::unordered_map<int, std::vector<WorldEventSubscription>>();
    eventHandler->registerWorldEvents(this);
    // Queue
    eventQueue = al_create_event_queue();
    // Events
    worldEventSource = new ALLEGRO_EVENT_SOURCE();
    al_init_user_event_source(worldEventSource);
    al_register_event_source(eventQueue, worldEventSource);
}

void WorldEvents::update() {
    // Prepare loop
    ALLEGRO_EVENT *currentEvent = new ALLEGRO_EVENT();
    // Start loop
    while (al_get_next_event(eventQueue, currentEvent)) {
        if (ALLEGRO_EVENT_TYPE_IS_USER(currentEvent->type) == false)
            throw new std::logic_error(system_event_in_world_event_queue);

        switch (currentEvent->type) {
        case player_attempt_go_north: // TODO: Ju� mam dost�p do playera, podpi�� (player ma si� sam tutaj podpi��) ruch i jazda
            break;
        case player_attempt_go_south:
            break;
        case player_attempt_go_east:
            break;
        case player_attempt_go_west:
            break;
        case player_attempt_use:
            break;

        default:
            break;
        }
    }
}

void WorldEvents::subscribeWorldEvent(worldevent eventType, eventfn fun, void *source, void *target) {
    auto p = WorldEventSubscription { eventType, fun, source, target };
    subscribers[eventType].push_back(p);
}

void WorldEvents::emitWorldEvent(worldevent eventType, void *data) {
    //ALLEGRO_EVENT ae {};
    //ae.user.type = eventType;
    //ae.user.data1 = (intptr_t)data;
    al_emit_user_event(worldEventSource, (ALLEGRO_EVENT *)data, NULL);
}

#include "WorldEvents.h"

WorldEvents::WorldEvents(EventHandler *eventHandler) {
    subscribers = std::unordered_map<int, std::vector<SimulationEventSubscription>>();
    eventHandler->registerWorldEvents(this);
    // Queue
    eventQueue = al_create_event_queue();
    // Events
    worldEventSource = new ALLEGRO_EVENT_SOURCE();
    al_init_user_event_source(worldEventSource);
    al_register_event_source(eventQueue, worldEventSource);
}

void WorldEvents::update(miliseconds timeNow, miliseconds dt) {
    // Prepare loop
    ALLEGRO_EVENT *currentEvent = new ALLEGRO_EVENT();
    // Start loop
    while (al_get_next_event(eventQueue, currentEvent)) {
        if (not ALLEGRO_EVENT_TYPE_IS_USER(currentEvent->type))
            throw new std::logic_error(system_event_in_world_event_queue);

        switch (currentEvent->type) {
        case player_attempt_go_north: // TODO: Ju¿ mam dostêp do playera, podpi¹æ (player ma siê sam tutaj podpi¹æ) ruch i jazda
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

void WorldEvents::subscribeEvent(simulationevent eventType, eventfn fun, void *source, void *target) {
    auto p = SimulationEventSubscription { eventType, fun, source, target };
    subscribers[eventType].push_back(p);
}

ALLEGRO_EVENT_SOURCE *WorldEvents::getEventSource() {
    return worldEventSource;
}


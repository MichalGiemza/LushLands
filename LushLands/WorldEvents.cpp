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
    Mobility *playerMobility = ((Humanoid *)player->getEntity())->getMobility();
    bool pN = false, pS = false, pE = false, pW = false;
    // Start loop
    while (al_get_next_event(eventQueue, currentEvent)) {
        if (not ALLEGRO_EVENT_TYPE_IS_USER(currentEvent->type))
            throw new std::logic_error(system_event_in_world_event_queue);

        switch (currentEvent->type) {
        case player_attempt_go_north:
            pN = true;
            break;
        case player_attempt_go_south:
            pS = true;
            break;
        case player_attempt_go_east:
            pE = true;
            break;
        case player_attempt_go_west:
            pW = true;
            break;
        case player_attempt_use:
            break;

        default:
            break;
        }
    }
    // Apply collected changes
    radian direction = AngleTools::directionToRadian(pN, pS, pE, pW);
    playerMobility->setDirection(direction);
    if (not isnan(direction))
        playerMobility->attemptMovement();
}

void WorldEvents::subscribeEvent(simulationevent eventType, eventfn fun, void *source, void *target) {
    auto p = SimulationEventSubscription { eventType, fun, source, target };
    subscribers[eventType].push_back(p);
}

ALLEGRO_EVENT_SOURCE *WorldEvents::getEventSource() {
    return worldEventSource;
}

void WorldEvents::registerPlayer(Player *player) {
    this->player = player;
}


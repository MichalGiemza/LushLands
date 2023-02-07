#include "EntityUpdater.h"

EntityUpdater::EntityUpdater() {
    toUpdate = std::set<TimerSubscription *>();
}

void EntityUpdater::addToUpdate(TimerSubscription *ts) {
    toUpdate.insert(ts);
}

void EntityUpdater::rmFromUpdate(TimerSubscription *ts) {
    toUpdate.erase(ts);
}

void EntityUpdater::updateEntity(ALLEGRO_EVENT *allegroEvent) {
    int64_t ticks = allegroEvent->timer.count;
    for (TimerSubscription *timerSub : toUpdate) {
        if (ticks - timerSub->lastTickExecutedOn >= timerSub->period) {
            timerSub->func(allegroEvent, timerSub->caller);
            timerSub->lastTickExecutedOn = ticks;
        }
    }
}

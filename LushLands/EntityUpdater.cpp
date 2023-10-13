#include "stdafx.h"
#include "EntityUpdater.h"

EntityUpdater::EntityUpdater() {
    toUpdate = std::set<EntityUpdateSubscription *>();
}

void EntityUpdater::addToUpdate(EntityUpdateSubscription *es) {
    toUpdate.insert(es);
}

void EntityUpdater::rmFromUpdate(EntityUpdateSubscription *es) {
    toUpdate.erase(es);
}

void EntityUpdater::updateEntity(miliseconds timeNow, miliseconds dt) {
    for (auto *entityUpdateSub : toUpdate) {
        if (timeNow - entityUpdateSub->lastTickExecutedOn >= entityUpdateSub->period) {
            entityUpdateSub->update(timeNow, dt, entityUpdateSub->caller);
            entityUpdateSub->lastTickExecutedOn = timeNow;
        }
    }
}

void EntityUpdater::registerParentEventSource(ALLEGRO_EVENT_SOURCE *aes) {
    this->parentEventSource = aes;
}

void EntityUpdater::unregisterParentEventSource() {
    this->parentEventSource = 0;
}

ALLEGRO_EVENT_SOURCE *EntityUpdater::getEventSource() {
    return parentEventSource;
}

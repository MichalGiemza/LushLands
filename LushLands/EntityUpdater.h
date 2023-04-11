#pragma once
#include "EventTypes.h"
#include <set>

class EntityUpdater {
    /**
    * Entity module, provides means to update entity.
    * 
    */
    std::set<EntityUpdateSubscription *> toUpdate;
protected:
    ALLEGRO_EVENT_SOURCE *parentEventSource = 0;
public:
    EntityUpdater();
    void updateEntity(miliseconds timeNow, miliseconds dt);
    void addToUpdate(EntityUpdateSubscription *es);
    void rmFromUpdate(EntityUpdateSubscription *es);
    void registerParentEventSource(ALLEGRO_EVENT_SOURCE *aes);
    void unregisterParentEventSource();
    ALLEGRO_EVENT_SOURCE *getEventSource();
};

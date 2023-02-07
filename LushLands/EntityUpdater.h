#pragma once
#include "EventTypes.h"
#include <set>

class EntityUpdater {
    /**
    * Entity module, provides means to update entity.
    * 
    */
    std::set<TimerSubscription *> toUpdate;
public:
    EntityUpdater();
    void updateEntity(ALLEGRO_EVENT *allegroEvent);
    void addToUpdate(TimerSubscription *ts);
    void rmFromUpdate(TimerSubscription *ts);
};

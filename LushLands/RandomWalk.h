#pragma once
#include <random>
#include "DynamicCollider.h"
#include "Mobility.h"
#include "Random_.h"
#include "Time.h"
#include "EntityUpdater.h"
#include "Events.h"


class RandomWalk {
    /**
    * Entity module responsible for automatic wandering.
    */
    DynamicCollider *dynamicCollider;
    EntityUpdater *entityUpdater;

    miliseconds continueActionUntil = 0;
    actiontype currentAction = 0;
    miliseconds walkInterval;
private:
    void setNewAction(miliseconds currentTime);
public:
    // Constructors and main methods
    RandomWalk(DynamicCollider *dynamicCollider, EntityUpdater *entityUpdater, miliseconds walkInterval);

    // Getters, Setters
    Mobility *getMobility();
    Position *getPosition();
    DynamicCollider *getDynamicCollider();

    // Methods
    
    // Update
    friend void updateRandomWalk(miliseconds timeNow, miliseconds dt, void *caller);
};

void updateRandomWalk(miliseconds timeNow, miliseconds dt, void *caller);


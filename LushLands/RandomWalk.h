#pragma once
#include <random>
#include <cmath>
#include "DynamicCollider.h"
#include "Mobility.h"
#include "Random_.h"
#include "WorldTime.h"
#include "EntityUpdater.h"
#include "Events.h"


class RandomWalk {
    /**
    * Entity module responsible for automatic wandering.
    */
    EntityUpdater *entityUpdater;
    Mobility *mobility;

    miliseconds continueActionUntil = 0;
    actiontype currentAction = 0;
    miliseconds walkInterval;
private:
    void setNewAction(miliseconds currentTime);
public:
    // Constructors and main methods
    RandomWalk(Mobility *mobility, EntityUpdater *entityUpdater, miliseconds walkInterval);

    // Getters, Setters
    Mobility *getMobility();
    Position *getPosition();
    DynamicCollider *getDynamicCollider();
    Collider *getCollider();
    // Methods
    radian getRandomDirection(bool forbidTop, bool forbidBottom, bool forbidLeft, bool forbidRight);

    // Update
    friend void updateRandomWalk(miliseconds timeNow, miliseconds dt, void *caller);
};

void updateRandomWalk(miliseconds timeNow, miliseconds dt, void *caller);


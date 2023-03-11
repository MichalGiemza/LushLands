#pragma once
#include <random>
#include "DynamicCollider.h"
#include "Mobility.h"
#include "Random_.h"
#include "Time.h"
#include "EntityUpdater.h"
#include "Events.h"


class RandomWalk : public DynamicCollider, public virtual EntityUpdater {
    /**
    * Entity module responsible for automatic wandering.
    */
private:
    miliseconds continueActionUntil = 0;
    actiontype currentAction = 0;
protected:
    miliseconds walkInterval;

    void setNewAction(miliseconds currentTime);
public:
    RandomWalk(Position &position, Size &size, int movementSpeed_, miliseconds walkInterval);
    friend void updateRandomWalk(miliseconds timeNow, miliseconds dt, void *caller);
};

void updateRandomWalk(miliseconds timeNow, miliseconds dt, void *caller);


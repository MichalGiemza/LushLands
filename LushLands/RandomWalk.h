#pragma once
#include "DynamicCollider.h"
#include "Mobility.h"
#include "Random_.h"
#include <random>
#include "Time.h"

class RandomWalk : public virtual DynamicCollider, public virtual Mobility {
    /**
    * Entity module responsible for automatic wandering.
    */
private:
    miliseconds continueActionUntil = 0;
    actiontype currentAction = 0;
protected:
    miliseconds walkInterval;
    Time *worldTime;

    void setNewAction(miliseconds currentTime);
public:
    RandomWalk(Position &position, Size &size, int movementSpeed_, miliseconds walkInterval, Time *worldTime);
    friend void updateRandomWalk(ALLEGRO_EVENT *allegroEvent, void *caller);

};

void updateRandomWalk(ALLEGRO_EVENT *allegroEvent, void *caller);


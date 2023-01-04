#pragma once
#include "Body.h"

class Mobility : public virtual Body {
    /** 
    * Entity module responsible for movement.
    */
    int movementSpeed;
    int direction;
public:
    Mobility(int movementSpeed_, Position &position, Size &size);
    friend void applyMovement(Position &newPosition, void *obj);
    int getMovementSpeed();
    int getDirection();
};

void applyMovement(Position &newPosition, void *obj);
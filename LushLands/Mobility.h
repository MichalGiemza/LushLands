#pragma once
#include "Body.h"

class Mobility : public virtual Body {
    /** 
    * Entity module responsible for movement.
    */
protected:
    int movementSpeed;
    radian direction;
public:
    Mobility(int movementSpeed_, Position &position, Size &size);
    friend void applyMovement(Position &newPosition, void *obj);
    int getMovementSpeed();
    radian getDirection();
};

void applyMovement(Position &newPosition, void *obj);
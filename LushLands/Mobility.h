#pragma once
#include "Body.h"

class Mobility {
    /** 
    * Entity module responsible for movement.
    */
    Body *body;
protected:
    int movementSpeed;
    radian direction;
public:
    Mobility(Body *body, int movementSpeed);
    int getMovementSpeed();
    radian getDirection();
    void setDirection(radian direction);
    Body *getBody();
    friend void applyMovement(Position &newPosition, void *obj); // FIXME: Unused
};

void applyMovement(Position &newPosition, void *obj);

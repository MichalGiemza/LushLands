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
    // Constructors and main methods
    Mobility(Body *body, int movementSpeed);

    // Getters, Setters
    int getMovementSpeed();
    radian getDirection();
    void setDirection(radian direction);
    Body *getBody();

    // Methods


    // Update
    friend void applyMovement(Position &newPosition, void *obj); // FIXME: Unused
};

void applyMovement(Position &newPosition, void *obj);

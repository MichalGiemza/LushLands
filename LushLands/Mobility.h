#pragma once
#include "Body.h"
#include "Events.h"
#include "DynamicCollider.h"
#include "EntityUpdater.h"

class Mobility {
    /** 
    * Entity module responsible for movement.
    */
    EntityUpdater *entityUpdater;
    DynamicCollider *dynamicCollider;
protected:
    int movementSpeed;
    radian direction;
public:
    // Constructors and main methods
    Mobility(DynamicCollider *dynamicCollider, EntityUpdater *entityUpdater, int movementSpeed);

    // Getters, Setters
    int getMovementSpeed();
    radian getDirection();
    void setDirection(radian direction);
    Body *getBody();
    DynamicCollider *getDynamicCollider();

    // Methods
    void attemptMovement();

    // Update
    friend void applyMovement(Position &newPosition, void *obj); // FIXME: Unused
};

void applyMovement(Position &newPosition, void *obj);

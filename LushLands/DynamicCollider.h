#pragma once
#include "Collider.h"
#include "Mobility.h"
#include "Body.h"
#include <unordered_set>

class DynamicCollider {
    /**
    * Entity module responsible for collision control.
    */
    Collider *collider;
    Mobility *mobility;
private:
    Position *pos();
    Size *size();
public:
    // Constructors and main methods
    DynamicCollider(Collider *collider, Mobility *mobility);

    // Getters, Setters
    Mobility *getMobility();
    Collider *getCollider();
    void setPosition(Position &position);
    
    // Methods
    void updateNewPositionWithColliders(Position &newPosition, std::unordered_set<Collider *> &colliders);
};


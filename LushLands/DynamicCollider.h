#pragma once
#include "Collider.h"
#include "Body.h"
#include <unordered_set>
#include <algorithm>
#include <functional>

class DynamicCollider {
    /**
    * Entity module responsible for collision control.
    */
    Collider *collider;
private:
    Position *pos();
    Size *size();
public:
    // Constructors and main methods
    DynamicCollider(Collider *collider);

    // Getters, Setters
    Collider *getCollider();
    void setPosition(Position &position);
    
    // Methods
    void updateNewPositionWithColliders(Position &newPosition, std::unordered_set<Collider *> &colliders);
};


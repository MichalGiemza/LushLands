#pragma once
#include "Collider.h"
#include "Mobility.h"
#include "Body.h"
#include <unordered_set>

class DynamicCollider : public virtual Collider, public virtual Mobility {
    /**
    * Entity module responsible for collision control.
    */
public:
    DynamicCollider(Position &position, Size &size, int movementSpeed_);
    void updateNewPositionWithColliders(Position &newPosition, std::unordered_set<Collider *> &colliders);
};


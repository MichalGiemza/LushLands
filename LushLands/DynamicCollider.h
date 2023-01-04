#pragma once
#include "Collider.h"
#include "Mobility.h"
#include <unordered_set>

class DynamicCollider : public virtual Collider, public virtual Mobility {
    /**
    * Entity module responsible for collision control.
    */
public:
    int checkWalkableDistance(int accurateDistance, std::unordered_set<Collider *> colliders);
};


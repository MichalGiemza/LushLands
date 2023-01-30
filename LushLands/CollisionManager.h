#pragma once
#include "DynamicCollider.h"
#include <unordered_set>

class CollisionManager {
    /**
    * Manager responsible for collisions
    */

    std::unordered_set<Collider *> colliders;
public:
    CollisionManager();
    void addCollider(Collider *c);
    void rmCollider(Collider *c);
    std::unordered_set<Collider *> *getCollidersObstructuringNewPosition(DynamicCollider *c, Position *newPos);
};


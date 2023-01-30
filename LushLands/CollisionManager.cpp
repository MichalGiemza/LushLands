#include "CollisionManager.h"

CollisionManager::CollisionManager() {
    colliders = std::unordered_set<Collider *>();
}

void CollisionManager::addCollider(Collider *c) {
    colliders.insert(c);
}

void CollisionManager::rmCollider(Collider *c) {
    colliders.erase(c);
}

std::unordered_set<Collider *> *CollisionManager::getCollidersObstructuringNewPosition(DynamicCollider *dc, Position *newPos) {
    Rectangle_ r = Rectangle_(*dc->getRectangle());
    r.setPosition(newPos);
    auto conp = new std::unordered_set<Collider *>();

    for (auto *c : colliders) {
        if (not c->isCloseBy(&r))
            continue;
        if ((Body)(*c) == (Body)(*dc))
            continue;
        if (dc->overlapes(c))
            conp->insert(c);
    }
    return conp;
}

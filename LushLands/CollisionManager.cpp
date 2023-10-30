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
    WorldRectangle r = WorldRectangle(*dc->getCollider()->getBody()->getRectangle());
    r.setPosition(newPos);
    auto conp = new std::unordered_set<Collider *>();

    for (Collider *c : colliders) {
        if (r.isOverlapping(c->getBody()->getRectangle()))
            conp->insert(c);
    }
    conp->erase(dc->getCollider());
    return conp;
}

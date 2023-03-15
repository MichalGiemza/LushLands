#include "DynamicCollider.h"

Position *DynamicCollider::pos() {
    return collider->getBody()->getPosition();
}

Size *DynamicCollider::size() {
    return collider->getBody()->getSize();
}

DynamicCollider::DynamicCollider(Collider *collider, Mobility *mobility) :
    collider(collider), mobility(mobility)
{ }

Mobility *DynamicCollider::getMobility() {
    return mobility;
}

Collider *DynamicCollider::getCollider() {
    return collider;
}

void DynamicCollider::setPosition(Position &position) {
    mobility->getBody()->setPosition(position);
}

void DynamicCollider::updateNewPositionWithColliders(Position &newPosition, std::unordered_set<Collider *> &colliders) {
    int xVec = newPosition.getPX() - pos()->getPX();
    int zVec = newPosition.getPZ() - pos()->getPZ();
    for (auto c = colliders.begin(); c != colliders.end(); ++c) {
        Position *cP = (*c)->getBody()->getPosition();
        Size *cS = (*c)->getBody()->getSize();
        if (xVec > 0) {
            xVec = std::min(xVec + size()->getAccurateWidth(), cP->getPX());
        } else {
            xVec = std::max(xVec, cP->getPX() + cS->getAccurateWidth());
        }
        if (zVec > 0) {
            zVec = std::min(zVec + size()->getAccurateLength(), cP->getPZ());
        } else {
            zVec = std::max(zVec, cP->getPZ() + cS->getAccurateLength());
        }
    }
    newPosition.setPX(xVec);
    newPosition.setPZ(zVec);
}

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
    int xVec = newPosition.getAccurateX() - pos()->getAccurateX();
    int zVec = newPosition.getAccurateZ() - pos()->getAccurateZ();
    for (auto c = colliders.begin(); c != colliders.end(); ++c) {
        Position *cP = (*c)->getBody()->getPosition();
        Size *cS = (*c)->getBody()->getSize();
        if (xVec > 0) {
            xVec = std::min(xVec, cP->getAccurateX() - size()->getAccurateWidth());
        } else {
            xVec = std::max(xVec, cP->getAccurateX() + cS->getAccurateWidth());
        }
        if (zVec > 0) {
            zVec = std::min(zVec, cP->getAccurateZ() - size()->getAccurateLength());
        } else {
            zVec = std::max(zVec, cP->getAccurateZ() + cS->getAccurateLength());
        }
    }
    newPosition.setAccurateX(xVec);
    newPosition.setAccurateZ(zVec);
}

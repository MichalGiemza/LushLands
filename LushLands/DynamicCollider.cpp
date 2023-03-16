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
    ll xVec = newPosition.getPX() - pos()->getPX();
    ll zVec = newPosition.getPZ() - pos()->getPZ();
    for (auto c = colliders.begin(); c != colliders.end(); ++c) {
        Position *cP = (*c)->getBody()->getPosition();
        Size *cS = (*c)->getBody()->getSize();
        if (xVec > 0) {
            xVec = std::min(xVec, cP->getPX() - size()->getPW());
        } else {
            xVec = std::max(xVec, cP->getPX() + cS->getPW());
        }
        if (zVec > 0) {
            zVec = std::min(zVec, cP->getPZ() - size()->getPW());
        } else {
            zVec = std::max(zVec, cP->getPZ() + cS->getPL());
        }
    }
    newPosition.setPX(xVec);
    newPosition.setPZ(zVec);
}

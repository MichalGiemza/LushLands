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

void DynamicCollider::updateNewPositionWithColliders(Position &nP, std::unordered_set<Collider *> &colliders) { // FIXME: Not working properly
    Size *s = size();
    Position *p = pos();
    ll nX = nP.getPX();
    ll nZ = nP.getPZ();
    for (auto c = colliders.begin(); c != colliders.end(); ++c) {
        Position *cP = (*c)->getBody()->getPosition();
        Size *cS = (*c)->getBody()->getSize();
        // Direction handling
        bool goingRight = p->getPX() < nP.getPX();
        bool goingDown_ = p->getPZ() < nP.getPZ();
        // Distance to collider
        ll dx = (nX > p->getPX()) ? cP->getPX() - s->getPW() : cP->getPX() + cS->getPW();
        ll dz = (nZ > p->getPZ()) ? cP->getPZ() - s->getPL() : cP->getPZ() + cS->getPL();
        // Update position
        nX = goingRight ? std::min(nX, dx) : std::max(nX, dx);
        nZ = goingDown_ ? std::min(nZ, dz) : std::max(nZ, dz);
    }
    // Direction handling
    bool goingRight = p->getPX() < nP.getPX();
    bool goingDown_ = p->getPZ() < nP.getPZ();
    // Update position
    nX = goingRight ? std::max(nX, p->getPX()) : std::min(nX, p->getPX());
    nZ = goingDown_ ? std::max(nZ, p->getPZ()) : std::min(nZ, p->getPZ());

    nP.setPX(nX);
    nP.setPZ(nZ);
}


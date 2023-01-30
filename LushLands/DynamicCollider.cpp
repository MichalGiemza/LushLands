#include "DynamicCollider.h"

DynamicCollider::DynamicCollider(Position &position, Size &size, int movementSpeed_) :
    Collider(position, size),
    Mobility(movementSpeed_, position, size), 
    Body(position, size) 
{ }

void DynamicCollider::updateNewPositionWithColliders(Position &newPosition, std::unordered_set<Collider *> &colliders) {
    int xVec = newPosition.getAccurateX() - getPosition()->getAccurateX();
    int zVec = newPosition.getAccurateZ() - getPosition()->getAccurateZ();
    for (auto c = colliders.begin(); c != colliders.end(); ++c) {
        if (xVec > 0) {
            xVec = std::min(xVec, (**c).getPosition()->getAccurateX() - getRectangle()->getSize()->getAccurateWidth());
        } else {
            xVec = std::max(xVec, (**c).getPosition()->getAccurateX() + (**c).getSize().getAccurateWidth());
        }
        if (zVec > 0) {
            zVec = std::min(zVec, (**c).getPosition()->getAccurateZ() - getRectangle()->getSize()->getAccurateLength());
        } else {
            zVec = std::max(zVec, (**c).getPosition()->getAccurateZ() + (**c).getSize().getAccurateLength());
        }
    }
    newPosition.setAccurateX(xVec);
    newPosition.setAccurateZ(zVec);
}

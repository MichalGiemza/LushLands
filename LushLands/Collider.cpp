#include "Collider.h"

Collider::Collider(Position &position, Size &size) : Body(position, size) {}

bool Collider::isCloseBy(Collider *other) {
    return isCloseBy(other->rectangle);
}

bool Collider::isCloseBy(Rectangle_ *other) {
    return rectangle->accurateDistanceFromCenter2D(*other->getPosition()) < size.getAccurateWidth() + size.getAccurateLength()
        || rectangle->accurateDistanceFromCenter2D(*other->getPosition()) < other->getSize()->getAccurateWidth() + other->getSize()->getAccurateLength();
}

bool Collider::overlapes(Collider *other) {
    if (not isCloseBy(other)) // TODO: Czy to w ogóle pomaga?
        return false;

    return other->rectangle->isOverlapping(rectangle);
}

bool Collider::operator==(const Collider &other) const {
    return (Body)(*this) == (Body)other;
}

#include "Collider.h"

Collider::Collider(Position &position, Size &size) : Body(position, size) {}

bool Collider::isCloseBy(Collider *other) {
    return accurateDistanceFromCenter2D(other->position) < size.getAccurateWidth() + size.getAccurateLength()
        || accurateDistanceFromCenter2D(other->position) < other->size.getAccurateWidth() + other->size.getAccurateLength();
}

bool Collider::overlapes(Collider *other) {
    if (not isCloseBy(other)) // TODO: Czy to w ogóle pomaga?
        return false;

    return other->rectangle->isOverlapping(rectangle);
}

bool Collider::operator==(const Collider &other) const {
    return (Body)(*this) == (Body)other;
}

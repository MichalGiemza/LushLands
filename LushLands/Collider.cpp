#include "Collider.h"

int Collider::dist2D(Position &p) {
    return body->getRectangle()->accurateDistanceFromCenter2D(p);
}

Collider::Collider(Body *body) : body(body) {}

Body *Collider::getBody() {
    return body;
}

bool Collider::isCloseBy(Collider *other) {
    return isCloseBy(body->getRectangle());
}

bool Collider::isCloseBy(Rectangle_ *other) {
    return dist2D(*other->getPosition()) < body->getSize()->getAccurateWidth() + body->getSize()->getAccurateLength()
        || dist2D(*other->getPosition()) < other->getSize()->getAccurateWidth() + other->getSize()->getAccurateLength();
}

bool Collider::overlapes(Collider *other) {
    if (not isCloseBy(other)) // TODO: Czy to w ogóle pomaga w optymalizacji?
        return false;

    return other->body->getRectangle()->isOverlapping(body->getRectangle());
}

bool Collider::operator==(const Collider &other) const {
    return *body == *other.body;
}

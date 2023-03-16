#include "Collider.h"

int Collider::dist2D(Position &p) {
    return body->getRectangle()->accurateDistanceFromCenter2D(p);
}

Collider::Collider(Body *body) : body(body) {}

Body *Collider::getBody() {
    return body;
}

bool Collider::overlapes(Collider *other) {
    return other->body->getRectangle()->isOverlapping(body->getRectangle());
}

bool Collider::operator==(const Collider &other) const {
    return *body == *other.body;
}

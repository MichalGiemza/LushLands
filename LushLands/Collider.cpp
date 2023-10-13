#include "stdafx.h"
#include "Collider.h"

int Collider::dist2D(Position &p) {
    return body->getRectangle()->accurateDistanceFromCenter2D(p);
}

Collider::Collider(Body *body) : body(body) {}

Body *Collider::getBody() {
    return body;
}

void Collider::updateCollisionStatus(bool t, bool b, bool l, bool r) {
    fromTop = t;
    fromBottom = b;
    fromLeft = l;
    fromRight = r;
}

bool Collider::overlapes(const Collider *other) const {
    return body->getRectangle()->isOverlapping(other->body->getRectangle());
}

bool Collider::isCollidingTop(const Collider *other) const {
    return body->getRectangle()->isCollidingTop(other->body->getRectangle());
}

bool Collider::isCollidingBottom(const Collider *other) const {
    return body->getRectangle()->isCollidingBottom(other->body->getRectangle());
}

bool Collider::isCollidingLeft(const Collider *other) const {
    return body->getRectangle()->isCollidingLeft(other->body->getRectangle());
}

bool Collider::isCollidingRight(const Collider *other) const {
    return body->getRectangle()->isCollidingRight(other->body->getRectangle());
}

bool Collider::isInCollision() const {
    return fromTop or fromBottom or fromLeft or fromRight;
}

bool Collider::isInCollisionTop() const {
    return fromTop;
}

bool Collider::isInCollisionBottom() const {
    return fromBottom;
}

bool Collider::isInCollisionLeft() const {
    return fromLeft;
}

bool Collider::isInCollisionRight() const {
    return fromRight;
}

bool Collider::operator==(const Collider &other) const {
    return *body == *other.body;
}

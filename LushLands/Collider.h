#pragma once
#include <math.h>
#include "Body.h"

class Collider {
    /**
    * Entity module representing ability to collide with other colliders.
    */
    Body *body;
    bool fromTop = false, fromBottom = false, fromLeft = false, fromRight = false;
private:
    int dist2D(Position &p);
public:
    Collider(Body *body);
    Body *getBody();
    void updateCollisionStatus(bool fromTop, bool fromBottom, bool fromLeft, bool fromRight);
    bool overlapes(const Collider *other) const;
    bool isCollidingTop(const Collider *other) const;
    bool isCollidingBottom(const Collider *other) const;
    bool isCollidingLeft(const Collider *other) const;
    bool isCollidingRight(const Collider *other) const;
    bool isInCollision() const;
    bool isInCollisionTop() const;
    bool isInCollisionBottom() const;
    bool isInCollisionLeft() const;
    bool isInCollisionRight() const;
    bool operator==(const Collider &other) const;
};


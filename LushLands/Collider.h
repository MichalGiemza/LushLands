#pragma once
#include <math.h>
#include "Body.h"

class Collider {
    /**
    * Entity module representing ability to collide with other colliders.
    */
    Body *body;
private:
    int dist2D(Position &p);
public:
    Collider(Body *body);
    Body *getBody();
    bool overlapes(Collider *other);
    bool operator==(const Collider &other) const;
};


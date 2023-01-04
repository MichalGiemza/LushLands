#pragma once
#include <math.h>
#include "Body.h"

class Collider : public virtual Body {
    /**
    * Entity module representing ability to collide with other colliders.
    */
public:
    Collider(Position &position, Size &size);
    bool isCloseBy(Collider *other);
    bool overlapes(Collider *other);
    bool operator==(const Collider &other) const;
};


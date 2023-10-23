#pragma once
#include "Color.h"
#include "DataTypes.h"

class Appearance {
    /**
    * Represents appearance of an entity (as model, not view).
    */
    const Color *color;
public:
    Appearance(const Color &color);
    const Color *getColor() const;
};


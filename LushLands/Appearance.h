#pragma once
#include "Agui/Color.hpp"
#include "DataTypes.h"

class Appearance {
    /**
    * Represents appearance of an entity (as model, not view).
    */
    const agui::Color *color;
public:
    Appearance(const agui::Color &color);
    const agui::Color *getColor() const;
};


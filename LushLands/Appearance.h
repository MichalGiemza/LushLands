#pragma once
#include "Color.h"
#include "DataTypes.h"

class Appearance {
    /**
    * Represents appearance of an entity (as model, not view).
    */
    const Color *color;
    const TextureLocalization *textureLocalization;
public:
    Appearance(const Color &color, const TextureLocalization *textureLocalization);
    const Color *getColor() const;
    const TextureLocalization *getTextureLocalization() const;
};


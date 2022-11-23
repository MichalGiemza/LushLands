#pragma once
#include "Color.h"
#include "DataTypes.h"


class Representation {
    /**
    * Provides means of representing entity in UI.
    */
    texturename textureName;
    Color color;
public:
    Representation(texturename textureName, Color color);
    Color getColor();
    texturename getTextureName();
};


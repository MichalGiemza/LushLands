#pragma once
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include "Color.h"
#include "DataTypes.h"
#include "TextureManager.h"


class Representation {
    /**
    * Provides means of representing entity in UI.
    */
    texturename textureName;
    ALLEGRO_BITMAP *texture;
    Color color;
public:
    Representation(texturename textureName, Color color);
    Color getColor();
    texturename getTextureName();
};


#pragma once
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include "Color.h"
#include "DataTypes.h"
#include "TextureManager.h"
#include "Body.h"


class Representation {
    /**
    * Provides means of representing entity in UI.
    */
    texturename textureName;
    ALLEGRO_BITMAP *texture;
    Color color;
    Body *body;
public:
    Representation(texturename textureName, Color color, Body *body);
    Color getColor();
    texturename getTextureName();
    ALLEGRO_BITMAP *getTexture();
    Body *getBody();
};


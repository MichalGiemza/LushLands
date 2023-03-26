#pragma once
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "DataTypes.h"
#include "Constants.h"
#include "ConstantSets.h"
#include "EntityConstants.h"

class TextureManager {
    /**
    * Odpowiada za wczytywanie i zapewnianie tekstur.
    */
    std::unordered_map<texturename, ALLEGRO_BITMAP *> textures;
    std::unordered_map<TextureLocalization, ALLEGRO_BITMAP *> rawBitmaps;
    ALLEGRO_BITMAP *loadTexture(const TextureLocalization &tl);
    ALLEGRO_BITMAP *getRawBitmap(const TextureLocalization &tl);
    void loadAllTextures();
public:
    TextureManager();
    ALLEGRO_BITMAP *getEntityTexture(entitytype entityType);
    ALLEGRO_BITMAP *getTexture(const TextureLocalization &tl);
};


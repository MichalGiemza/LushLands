#pragma once
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "DataTypes.h"
#include "Constants.h"
#include "ConstantSets.h"

class TextureManager {
    /**
    * Odpowiada za wczytywanie i zapewnianie tekstur.
    */
    static std::unordered_map<texturename, ALLEGRO_BITMAP *> textures;
    static std::unordered_map<TextureLocalization, ALLEGRO_BITMAP *> rawBitmaps;

    static ALLEGRO_BITMAP *loadTexture(const TextureLocalization &tl);
    static ALLEGRO_BITMAP *getRawBitmap(const TextureLocalization &tl);
public:
    static void init();
    static void loadAllTextures();
    static ALLEGRO_BITMAP *getTexture(texturename textureName);
};


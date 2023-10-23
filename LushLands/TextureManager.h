#pragma once
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "DataTypes.h"
#include "Constants.h"
#include "ConstantSets.h"
#include "ConstantRepository.h"
#include "JsonHandler.h"


typedef std::unordered_map<std::string, std::vector<TextureLocalization>> NameToTexLocs;

class TextureManager {
    /**
    * Odpowiada za wczytywanie i zapewnianie tekstur.
    */
    static const std::string pngExt;
    static const std::string jsonExt;
    static entitytype defaultTex;
    static bool initialized;
    static std::unordered_map<entitytype, std::vector<ALLEGRO_BITMAP *>> textures;
    static std::unordered_map<std::string, ALLEGRO_BITMAP *> rawBitmaps;
    static std::vector<ALLEGRO_BITMAP *> *loadTextures(std::vector<TextureLocalization> tls);
    static ALLEGRO_BITMAP *getRawBitmap(const TextureLocalization *tl);
    static void loadAllTextures();
    static NameToTexLocs *prepareTextureLocalizations();
public:
    static void init();
    static ALLEGRO_BITMAP *getTexture(const char *texName, int variation = 0);
};

typedef TextureManager TM;

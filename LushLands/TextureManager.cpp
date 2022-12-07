#include "TextureManager.h"

std::unordered_map<texturename, ALLEGRO_BITMAP *> TextureManager::textures = std::unordered_map<texturename, ALLEGRO_BITMAP *>();
std::unordered_map<TextureLocalization, ALLEGRO_BITMAP *> TextureManager::rawBitmaps = std::unordered_map<TextureLocalization, ALLEGRO_BITMAP *>();

ALLEGRO_BITMAP *TextureManager::loadTexture(const TextureLocalization &tl) {
    auto rawBitmap = getRawBitmap(tl);
    return al_create_sub_bitmap(rawBitmap, tl.x, tl.y, tileSizePx, tileSizePx);
}

ALLEGRO_BITMAP *TextureManager::getRawBitmap(const TextureLocalization &tl) {
    if (!rawBitmaps[tl]) {
        rawBitmaps[tl] = al_load_bitmap(tl.path);
    }
    return rawBitmaps[tl];
}

void TextureManager::init() {
    al_init_image_addon();
    loadAllTextures();
}

void TextureManager::loadAllTextures() {
    textures[SOIL_TEXTURE] = loadTexture(SOIL_TEXTURE_LOCALIZATION);
    textures[GRASS_TEXTURE] = loadTexture(GRASS_TEXTURE_LOCALIZATION);
    textures[WATER_TEXTURE] = loadTexture(WATER_TEXTURE_LOCALIZATION);
    textures[SAND_TEXTURE] = loadTexture(SAND_TEXTURE_LOCALIZATION);
    textures[ROCK_TEXTURE] = loadTexture(ROCK_TEXTURE_LOCALIZATION);
    textures[COBBLE_TEXTURE] = loadTexture(COBBLE_TEXTURE_LOCALIZATION);
    textures[FARMLAND_TEXTURE] = loadTexture(FARMLAND_TEXTURE_LOCALIZATION);
    textures[GRAVEL_TEXTURE] = loadTexture(GRAVEL_TEXTURE_LOCALIZATION);
    textures[SNOW_TEXTURE] = loadTexture(SNOW_TEXTURE_LOCALIZATION);
}

ALLEGRO_BITMAP *TextureManager::getTexture(texturename textureName) {
    return textures[textureName];
}

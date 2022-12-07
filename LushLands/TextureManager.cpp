#include "TextureManager.h"

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

TextureManager::TextureManager() {
    textures = std::unordered_map<texturename, ALLEGRO_BITMAP *>();
    rawBitmaps = std::unordered_map<TextureLocalization, ALLEGRO_BITMAP *>();
    al_init_image_addon();
    loadAllTextures();
}

void TextureManager::loadAllTextures() {
    textures[SOIL] = loadTexture(SOIL_TEXTURE_LOCALIZATION);
    textures[GRASS] = loadTexture(GRASS_TEXTURE_LOCALIZATION);
    textures[WATER] = loadTexture(WATER_TEXTURE_LOCALIZATION);
    textures[SAND] = loadTexture(SAND_TEXTURE_LOCALIZATION);
    textures[ROCK] = loadTexture(ROCK_TEXTURE_LOCALIZATION);
    textures[COBBLE] = loadTexture(COBBLE_TEXTURE_LOCALIZATION);
    textures[FARMLAND] = loadTexture(FARMLAND_TEXTURE_LOCALIZATION);
    textures[GRAVEL] = loadTexture(GRAVEL_TEXTURE_LOCALIZATION);
    textures[SNOW] = loadTexture(SNOW_TEXTURE_LOCALIZATION);
}

ALLEGRO_BITMAP *TextureManager::getEntityTexture(entitytype entityType) {
    return textures[entityType];
}

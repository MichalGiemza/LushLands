#include "TextureManager.h"

ALLEGRO_BITMAP *TextureManager::loadTexture(const TextureLocalization &tl) {
    auto rawBitmap = getRawBitmap(tl);
    return al_create_sub_bitmap(rawBitmap, tl.x, tl.y, tl.w, tl.h);
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
    // Entities
    /*    Ground    */
    textures[SOIL] = loadTexture(SOIL_TEXTURE_LOCALIZATION);
    textures[GRASS] = loadTexture(GRASS_TEXTURE_LOCALIZATION);
    textures[WATER] = loadTexture(WATER_TEXTURE_LOCALIZATION);
    textures[SAND] = loadTexture(SAND_TEXTURE_LOCALIZATION);
    textures[ROCK] = loadTexture(ROCK_TEXTURE_LOCALIZATION);
    textures[COBBLE] = loadTexture(COBBLE_TEXTURE_LOCALIZATION);
    textures[FARMLAND] = loadTexture(FARMLAND_TEXTURE_LOCALIZATION);
    textures[GRAVEL] = loadTexture(GRAVEL_TEXTURE_LOCALIZATION);
    textures[SNOW] = loadTexture(SNOW_TEXTURE_LOCALIZATION);
    /*    Structure    */
    textures[TREE] = loadTexture(TREE_TEXTURE_LOCALIZATION);
    textures[BUSH] = loadTexture(BUSH_TEXTURE_LOCALIZATION);
    textures[TALL_GRASS] = loadTexture(TALL_GRASS_TEXTURE_LOCALIZATION);
    textures[FLOWER_YELLOW] = loadTexture(FLOWER_YELLOW_TEXTURE_LOCALIZATION);
    textures[STONE] = loadTexture(STONE_TEXTURE_LOCALIZATION);
    textures[LOG] = loadTexture(LOG_TEXTURE_LOCALIZATION);
    /*    Animal    */
    textures[CHICKEN] = loadTexture(CHICKEN_TEXTURE_LOCALIZATION);
    /*    Humanoids    */
    textures[HUMAN] = loadTexture(HUMAN_TEXTURE_LOCALIZATION);
    // Items 
    /*    Resources    */
    textures[WOOD] = loadTexture(WOOD_TEXTURE_LOCALIZATION);
    textures[PLANK] = loadTexture(PLANK_TEXTURE_LOCALIZATION);
    textures[BRANCH] = loadTexture(BRANCH_TEXTURE_LOCALIZATION);
    /*    Animal Loot    */
    textures[MEAT] = loadTexture(MEAT_TEXTURE_LOCALIZATION);
    textures[FEATHER] = loadTexture(FEATHER_TEXTURE_LOCALIZATION);
}

ALLEGRO_BITMAP *TextureManager::getNamedTexture(const char *name) {
    return textures[name];
}

ALLEGRO_BITMAP *TextureManager::getTexture(const TextureLocalization &tl) {
    return getRawBitmap(tl);
}

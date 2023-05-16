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
    textures[e::SOIL] = loadTexture(e::SOIL_TEXTURE_LOCALIZATION);
    textures[e::GRASS] = loadTexture(e::GRASS_TEXTURE_LOCALIZATION);
    textures[e::WATER] = loadTexture(e::WATER_TEXTURE_LOCALIZATION);
    textures[e::SAND] = loadTexture(e::SAND_TEXTURE_LOCALIZATION);
    textures[e::ROCK] = loadTexture(e::ROCK_TEXTURE_LOCALIZATION);
    textures[e::COBBLE] = loadTexture(e::COBBLE_TEXTURE_LOCALIZATION);
    textures[e::FARMLAND] = loadTexture(e::FARMLAND_TEXTURE_LOCALIZATION);
    textures[e::GRAVEL] = loadTexture(e::GRAVEL_TEXTURE_LOCALIZATION);
    textures[e::SNOW] = loadTexture(e::SNOW_TEXTURE_LOCALIZATION);
    /*    Structure    */
    textures[e::TREE] = loadTexture(e::TREE_TEXTURE_LOCALIZATION);
    textures[e::BUSH] = loadTexture(e::BUSH_TEXTURE_LOCALIZATION);
    textures[e::TALL_GRASS] = loadTexture(e::TALL_GRASS_TEXTURE_LOCALIZATION);
    textures[e::FLOWER_YELLOW] = loadTexture(e::FLOWER_YELLOW_TEXTURE_LOCALIZATION);
    textures[e::STONE] = loadTexture(e::STONE_TEXTURE_LOCALIZATION);
    textures[e::LOG] = loadTexture(e::LOG_TEXTURE_LOCALIZATION);
    /*    Animal    */
    textures[e::CHICKEN] = loadTexture(e::CHICKEN_TEXTURE_LOCALIZATION);
    /*    Humanoids    */
    textures[e::HUMAN] = loadTexture(e::HUMAN_TEXTURE_LOCALIZATION);
    // Items 
    /*    Resources    */
    textures[i::WOOD] = loadTexture(i::WOOD_TEXTURE_LOCALIZATION);
    textures[i::PLANK] = loadTexture(i::PLANK_TEXTURE_LOCALIZATION);
    textures[i::BRANCH] = loadTexture(i::BRANCH_TEXTURE_LOCALIZATION);
    /*    Animal Loot    */
    textures[i::MEAT] = loadTexture(i::MEAT_TEXTURE_LOCALIZATION);
    textures[i::FEATHER] = loadTexture(i::FEATHER_TEXTURE_LOCALIZATION);
    /*    Tools    */
    textures[i::SWORD] = loadTexture(i::SWORD_TEXTURE_LOCALIZATION);
    textures[i::SHOVEL] = loadTexture(i::SHOVEL_TEXTURE_LOCALIZATION);
    textures[i::PICKAXE] = loadTexture(i::PICKAXE_TEXTURE_LOCALIZATION);
    textures[i::AXE] = loadTexture(i::AXE_TEXTURE_LOCALIZATION);
    textures[i::SCYTHE] = loadTexture(i::SCYTHE_TEXTURE_LOCALIZATION);
}

ALLEGRO_BITMAP *TextureManager::getNamedTexture(const char *name) {
    return textures[name];
}

ALLEGRO_BITMAP *TextureManager::getTexture(const TextureLocalization &tl) {
    return getRawBitmap(tl);
}

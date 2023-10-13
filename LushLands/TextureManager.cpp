#include "stdafx.h"
#include "TextureManager.h"

ALLEGRO_BITMAP *TextureManager::loadTexture(const TextureLocalization *tl) {
    auto rawBitmap = getRawBitmap(tl);
    return al_create_sub_bitmap(rawBitmap, tl->x, tl->y, tl->w, tl->h);
}

ALLEGRO_BITMAP *TextureManager::getRawBitmap(const TextureLocalization *tl) {
    if (not rawBitmaps[tl->path]) {
        rawBitmaps[tl->path] = al_load_bitmap(tl->path);
    }
    return rawBitmaps[tl->path];
}

TextureManager::TextureManager() {
    al_init_image_addon();
    loadAllTextures();
}

void TextureManager::loadAllTextures() {
    // Entities
    for (entitytype entityType : CR::getAllEntityTypes())
        textures[entityType] = loadTexture(CR::selectTextureLocalization(entityType));
}

ALLEGRO_BITMAP *TextureManager::getNamedTexture(const char *name) {
    return textures[name];
}

ALLEGRO_BITMAP *TextureManager::getTexture(const TextureLocalization &tl) {
    return getRawBitmap(&tl);
}

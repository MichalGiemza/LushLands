#include "ChunkRepresentation.h"

size_t ChunkRepresentation::hashChunkGroundLevel(int level) {
    TilePosition referencePosition = position.getTilePosition();
    referencePosition.y = level;
    TilePosition tp = TilePosition(referencePosition);
    size_t hash_ = 0;

    for (int i = 0; i < chunkSizeByTiles; i++) {
        tp.x = referencePosition.x + i;
        for (int j = 0; j < chunkSizeByTiles; j++) {
            tp.z = referencePosition.z + j;
            hash_ = 33 * hash_ + std::hash<char *>()(groundTiles[tp]->getType());
        }
    }
    return hash_;
}

void ChunkRepresentation::drawLevelTilesToBitmap(int level) {
    TilePosition referencePosition = position.getTilePosition();
    referencePosition.y = level;
    TilePosition tp = TilePosition(referencePosition);
    for (int i = 0; i < chunkSizeByTiles; i++) {
        tp.x = referencePosition.x + i;
        for (int j = 0; j < chunkSizeByTiles; j++) {
            tp.z = referencePosition.z + j;
            if (groundTiles.find(tp) != groundTiles.end()) {
                Ground *g = (Ground *)groundTiles[tp];
                al_draw_bitmap(textureManager->getEntityTexture(g->getType()), i * tileSizePx, j * tileSizePx, 0);
            }
        }
    }
}

ChunkRepresentation::ChunkRepresentation(Display *display, ChunkPosition chunkPosition, 
    std::unordered_map<TilePosition, Entity *> &groundTiles, 
    std::unordered_map<TilePosition, Entity *> &structures, 
    std::unordered_map<TilePosition, Entity *> &animals,
    TextureManager *textureManager) {
    this->textureManager = textureManager;
    this->display = display;
    this->groundTiles = groundTiles;
    this->structures = structures;
    this->animals = animals;
    this->chunkPosition = chunkPosition;
    this->position = Position(chunkPosition);
    this->area = new Rectangle_(0, 0, chunkSizeByTiles, chunkSizeByTiles);
    this->area->setPosition(&this->position);
}

ALLEGRO_BITMAP *ChunkRepresentation::getBitmap(int level) {
    auto backbuffer = al_get_backbuffer(display->getDisplay());
    size_t newHash = hashChunkGroundLevel(level);
    if (newHash != cachedLevelHash) {
        auto chunkBmp = al_create_bitmap(tileSizePx * chunkSizeByTiles, tileSizePx * chunkSizeByTiles);
        al_set_target_bitmap(chunkBmp);
        drawLevelTilesToBitmap(level);
        cachedLevelBitmap = chunkBmp;
        cachedLevelHash = newHash;
    }
    al_set_target_bitmap(backbuffer);
    return cachedLevelBitmap;
}

std::unordered_map<TilePosition, Entity *> *ChunkRepresentation::getStructures() {
    return &structures;
}

std::unordered_map<TilePosition, Entity *> *ChunkRepresentation::getAnimals() {
    return &animals;
}

ChunkPosition *ChunkRepresentation::getChunkPosition() {
    return &chunkPosition;
}

Position *ChunkRepresentation::getPosition() {
    return &position;
}

Rectangle_ *ChunkRepresentation::getArea() {
    return area;
}

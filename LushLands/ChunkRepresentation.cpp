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
            if (ce->groundTiles.find(tp) != ce->groundTiles.end()) {
                hash_ = 33 * hash_ + std::hash<char *>()(ce->groundTiles[tp]->getType());
            } else {
                hash_ = 33 * hash_;
            }
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
            if (ce->groundTiles.find(tp) != ce->groundTiles.end()) {
                Ground *g = (Ground *)ce->groundTiles[tp];
                al_draw_bitmap(textureManager->getNamedTexture(g->getType()), i * tileSizePx, j * tileSizePx, 0);
            }
        }
    }
}

ChunkRepresentation::ChunkRepresentation(Display *display, ChunkPosition chunkPosition, ChunkElements *ce, TextureManager *textureManager) :
    ce(ce), textureManager(textureManager), chunkPosition(chunkPosition), display(display) {
    this->position = Position(chunkPosition);
    this->area = new WorldRectangle(0, 0, chunkSizeByTiles, chunkSizeByTiles);
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

ChunkPosition *ChunkRepresentation::getChunkPosition() {
    return &chunkPosition;
}

ChunkElements *ChunkRepresentation::getChunkElements() {
    return ce;
}

Position *ChunkRepresentation::getPosition() {
    return &position;
}

WorldRectangle *ChunkRepresentation::getArea() {
    return area;
}


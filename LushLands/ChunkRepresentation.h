#pragma once
#include "Entity.h"
#include "Display.h"
#include "Ground.h"
#include "Position.h"

class ChunkRepresentation {
    /**
    * Registeres and provides means for drawing a chunk.
    */
    ChunkPosition *chunkPosition;
    Position *position;
    std::unordered_map<TilePosition, Entity *> groundTiles;
    std::unordered_map<TilePosition, Entity *> structures;
    size_t cachedLevelHash = 0;
    ALLEGRO_BITMAP *cachedLevelBitmap = 0;
    Display *display;

    size_t hashChunkGroundLevel(int level);
    void drawLevelTilesToBitmap(int level);
public:
    ChunkRepresentation(Display *display, ChunkPosition &chunkPosition, std::unordered_map<TilePosition, Entity *> &groundTiles, std::unordered_map<TilePosition, Entity *> &structures);
    ALLEGRO_BITMAP *getBitmap(int level);
    ChunkPosition *getChunkPosition() const;
    Position *getPosition() const;
};


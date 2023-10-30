#pragma once
#include "ConstantSets.h"
#include "Entity.h"
#include "Display.h"
#include "Ground.h"
#include "Item.h"
#include "ChunkElements.h"
#include "Agui/TextureManager.h"


class ChunkRepresentation {
    /**
    * Registeres and provides means for drawing a chunk.
    */
    ChunkElements *ce;
    ChunkPosition chunkPosition;
    Position position;
    WorldRectangle *area;
    size_t cachedLevelHash = 0;
    ALLEGRO_BITMAP *cachedLevelBitmap = 0;
    Display *display;

    size_t hashChunkGroundLevel(int level);
    void drawLevelTilesToBitmap(int level);
public:
    ChunkRepresentation(Display *display, ChunkPosition chunkPosition, ChunkElements *ce);
    ALLEGRO_BITMAP *getBitmap(int level);
    ChunkPosition *getChunkPosition();
    ChunkElements *getChunkElements();
    Position *getPosition();
    WorldRectangle *getArea();
};


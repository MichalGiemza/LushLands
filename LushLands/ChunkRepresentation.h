#pragma once
#include "Rectangle_.h"
#include "Entity.h"
#include "Display.h"
#include "Ground.h"
#include "TextureManager.h"


class ChunkRepresentation {
    /**
    * Registeres and provides means for drawing a chunk.
    */
    ChunkPosition chunkPosition;
    Position position;
    Rectangle_ *area;
    std::unordered_map<TilePosition, Entity *> groundTiles;
    std::unordered_map<TilePosition, Entity *> structures;
    std::unordered_set<Entity *> animals;
    std::unordered_set<Entity *> humanoids;
    size_t cachedLevelHash = 0;
    ALLEGRO_BITMAP *cachedLevelBitmap = 0;
    Display *display;
    TextureManager *textureManager;

    size_t hashChunkGroundLevel(int level);
    void drawLevelTilesToBitmap(int level);
public:
    ChunkRepresentation(Display *display, ChunkPosition chunkPosition, std::unordered_map<TilePosition, Entity *> &groundTiles, std::unordered_map<TilePosition, Entity *> &structures, std::unordered_set<Entity *> &animals, std::unordered_set<Entity *> &humanoids, TextureManager *textureManager);
    ALLEGRO_BITMAP *getBitmap(int level);
    std::unordered_map<TilePosition, Entity *> *getStructures();
    std::unordered_set<Entity *> *getAnimals();
    std::unordered_set<Entity *> *getHumanoids();
    ChunkPosition *getChunkPosition();
    Position *getPosition();
    Rectangle_ *getArea();
};


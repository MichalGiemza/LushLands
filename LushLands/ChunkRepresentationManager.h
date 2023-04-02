#pragma once
#include "Camera.h"
#include <unordered_set>
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include "ChunkRepresentation.h"
#include "ConstantSets.h"
#include "World.h"
#include "Colors.h"

class ChunkRepresentationManager {
    /**
    * Obs³uguje rysowanie chunków.
    */
    std::unordered_map<ChunkPosition, ChunkRepresentation *> chunkRepresentations;
    World *world;
    Display *display;
    Camera *camera;
    TextureManager *textureManager;
private:
    void updateVisibleChunkRepresentations();
    void drawGround(ChunkRepresentation *cRep, int level);
    void drawStructures(ChunkRepresentation *cRep, int level);
    void drawItems(ChunkRepresentation *cRep, int level, miliseconds t);
    void drawAnimals(ChunkRepresentation *cRep, int level);
    void drawHumanoids(ChunkRepresentation *cRep, int level);
    void drawChunkDebug(ChunkRepresentation *cRep);
    void drawStructureDebug(ChunkRepresentation *cRep, int level);
    void drawItemsDebug(ChunkRepresentation *cRep, int level);
    void drawAnimalDebug(ChunkRepresentation *cRep, int level);
    void drawHumanoidDebug(ChunkRepresentation *cRep, int level);
    pxint shiftTexturePositionX(pxint screenPositionX, pxint bitmapWidth, pxint bbWidth);
    pxint shiftTexturePositionZ(pxint screenPositionZ, pxint bitmapHeight, pxint bbHeight);
public:
    ChunkRepresentationManager(World *world, Display *display, Camera *camera, TextureManager *textureManager);
    void draw(miliseconds time);
};

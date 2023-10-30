#pragma once
#include "Camera.h"
#include <cmath>
#include "ChunkRepresentation.h"
#include "ConstantSets.h"
#include "World.h"
#include "Agui/Base/Colors.h"
#include "Agui/TextureManager.h"

class ChunkRepresentationManager {
    /**
    * Obs³uguje rysowanie chunków.
    */
    std::unordered_map<ChunkPosition, ChunkRepresentation *> chunkRepresentations;
    World *world;
    Display *display;
    Camera *camera;
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
    ChunkRepresentationManager(World *world, Display *display, Camera *camera);
    void draw(miliseconds time, bool showDebug);
};

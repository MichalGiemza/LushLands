#pragma once
#include "Camera.h"
#include <unordered_set>
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include "ChunkRepresentation.h"
#include "ConstantSets.h"
#include "World.h"
#include "Colors.h"

class ChunkRepresentationManager {
    /**
    * Obs�uguje rysowanie chunk�w.
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
    void drawAnimals(ChunkRepresentation *cRep, int level);
    void drawChunkBorders(ChunkRepresentation *cRep);
    void drawStructureOutlines(ChunkRepresentation *cRep, int level);
    pxint shiftTexturePositionX(pxint screenPositionX, pxint bitmapWidth);
    pxint shiftTexturePositionZ(pxint screenPositionZ, pxint bitmapHeight);
public:
    ChunkRepresentationManager(World *world, Display *display, Camera *camera, TextureManager *textureManager);
    void draw();
};

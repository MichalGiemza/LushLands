#pragma once
#include "Camera.h"
#include <unordered_set>
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include "ChunkRepresentation.h"
#include "World.h"

class ChunkRepresentationManager {
    /**
    * Obs�uguje rysowanie chunk�w.
    */
    std::unordered_map<ChunkPosition, ChunkRepresentation *> chunkRepresentations;
    World *world;
    Display *display;
private:
    void updateVisibleChunkRepresentations(Camera &camera);
public:
    ChunkRepresentationManager(World *world, Display *display);
    void draw(Camera &camera);
};


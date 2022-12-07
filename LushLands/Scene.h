#pragma once
#include <unordered_set>
#include "DataTypes.h"
#include "Representation.h"
#include "Camera.h"
#include "ChunkRepresentationManager.h"
#include "ChunkRepresentation.h"


class Scene {
    /**
    * Pozwala na dodawanie element�w �wiata i UI na scen� w celu rysowania i przedstawiania ich u�ytkownikowi.
    */
    scenename name;
    Camera camera;
    ChunkRepresentationManager chunkRepresentationManager;
    World *world;
    Display *display;

    void drawChunkGround(ChunkRepresentation &chunkRepresentation, int level);
public:
    Scene(scenename sceneName, World *world, Display *display, Position *followedPosition);
    void draw();
};


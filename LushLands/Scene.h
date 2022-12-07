#pragma once
#include <unordered_set>
#include "DataTypes.h"
#include "Camera.h"
#include "ChunkRepresentationManager.h"
#include "ChunkRepresentation.h"


class Scene {
    /**
    * Pozwala na dodawanie elementów œwiata i UI na scenê w celu rysowania i przedstawiania ich u¿ytkownikowi.
    */
    scenename name;
    Camera camera;
    ChunkRepresentationManager chunkRepresentationManager;
    World *world;
    Display *display;
    InputEvents *inputEvents;
    TextureManager *textureManager;

    void drawChunkGround(ChunkRepresentation &chunkRepresentation, int level);
    friend void draw(void *scene);
public:
    Scene(scenename sceneName, World *world, Display *display, Position *followedPosition, InputEvents *inputEvents, TextureManager *textureManager);
};

void draw(void *scene);

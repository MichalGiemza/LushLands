#pragma once
#include <unordered_set>
#include "DataTypes.h"
#include "Camera.h"
#include "ChunkRepresentationManager.h"
#include "ChunkRepresentation.h"
#include "Console.h"


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
    Console *console;

    void drawChunkGround(ChunkRepresentation &chunkRepresentation, int level);
    friend void draw(ALLEGRO_EVENT *ae, void *scene);
public:
    Scene(scenename sceneName, World *world, Display *display, Position *followedPosition, InputEvents *inputEvents, TextureManager *textureManager, Focus *focus, Console *console);
};

void draw(ALLEGRO_EVENT *ae, void *scene);

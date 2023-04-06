#pragma once
#include <unordered_set>
#include "DataTypes.h"
#include "Camera.h"
#include "ChunkRepresentationManager.h"
#include "ChunkRepresentation.h"
#include "Console.h"
#include "FieldCursor.h"
#include "InventoryDisplay.h"
#include "WindowManager.h"
#include "Hotbar.h"
#include "PlayerActionHandler.h"


class Scene {
    /**
    * Pozwala na dodawanie elementów œwiata i UI na scenê w celu rysowania i przedstawiania ich u¿ytkownikowi.
    */
    scenename name;
    Camera camera;
    ChunkRepresentationManager chunkRepresentationManager;
    World *world;
    Player *player;
    Display *display;
    InputEvents *inputEvents;
    TextureManager *textureManager;
    Console *console;
    FieldCursor *fieldCursor;
    InventoryDisplay *invDispl;
    Hotbar *hotbar;
    WindowManager *windowManager;
    PlayerActionHandler *pah;
    
    bool invOpen = false;
    bool mapOpen = false;
    bool chtOpen = false;
    bool stsOpen = false;
    bool qstOpen = false;
    bool bldOpen = false;
    bool dbgOpen = true;

    void drawChunkGround(ChunkRepresentation &chunkRepresentation, int level);
public:
    Scene(scenename sceneName, World *world, Display *display, Position *followedPosition, InputEvents *inputEvents, TextureManager *textureManager, Focus *focus, Console *console, Player *player);

    friend void draw(ALLEGRO_EVENT *ae, void *scene);
    friend void handleAction(ALLEGRO_EVENT *ae, void *scene);
};

void draw(ALLEGRO_EVENT *ae, void *scene);
void handleAction(ALLEGRO_EVENT *ae, void *scene);

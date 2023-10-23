#pragma once
#include "stdafx.h"
#include "Camera.h"
#include "ChunkRepresentationManager.h"
#include "ChunkRepresentation.h"
#include "Console.h"
#include "FieldCursor.h"
#include "InventoryDisplay.h"
#include "WindowManager.h"
#include "Hotbar.h"
#include "CraftingDisplay.h"
#include "Simulation.h"


class Scene {
    /**
    * Pozwala na dodawanie elementów œwiata i UI na scenê w celu rysowania i przedstawiania ich u¿ytkownikowi.
    */
    scenename name;
    Core *core;
    Camera camera;
    ChunkRepresentationManager chunkRepresentationManager;
    World *world;
    Player *player;
    Display *display;
    InputEvents *inputEvents;
    Console *console;
    FieldCursor *fieldCursor;
    InventoryDisplay *invDispl;
    CraftingDisplay *craftingDisplay;
    Hotbar *hotbar;
    WindowManager *windowManager;
    
    bool invOpen = false;
    bool mapOpen = false;
    bool chtOpen = false;
    bool stsOpen = false;
    bool qstOpen = false;
    bool bldOpen = false;
    bool dbgOpen = true;

    void drawChunkGround(ChunkRepresentation &chunkRepresentation, int level);
public:
    Scene(scenename sceneName, Core *core, Controller *controller, Simulation *simulation, Display *display, Console *console);

    FieldCursor *getFieldCursor();
    Hotbar *getHotbar();
    InventoryDisplay *getInventoryDisplay();
    CraftingDisplay *getCraftingDisplay();

    friend void draw(ALLEGRO_EVENT *ae, void *scene);
    friend void handleAction(ALLEGRO_EVENT *ae, void *scene);
};

void draw(ALLEGRO_EVENT *ae, void *scene);
void handleAction(ALLEGRO_EVENT *ae, void *scene);

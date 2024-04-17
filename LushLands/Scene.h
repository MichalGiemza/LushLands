#pragma once
#include "Camera.h"
#include "FieldCursor.h"
#include "Hotbar.h"
#include "CraftingDisplay.h"
#include "Simulation.h"
#include "Agui/InventoryDisplay.h"
#include "Agui/Base/WindowManager.h"
#include "ChunkRepresentationManager.h"
#include "ChunkRepresentation.h"
#include "Agui/InventoryDisplay.h"
#include "Agui/Base/Colors.h"
#include "Console.h"
#include <PauseMenu.h>


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
    agui::InventoryDisplay *invDispl;
    CraftingDisplay *craftingDisplay;
    agui::Hotbar *hotbar;
    agui::WindowManager *windowManager;
    PauseMenu *pauseMenu;
    
    bool invOpen = false;
    bool mapOpen = false;
    bool chtOpen = false;
    bool stsOpen = false;
    bool qstOpen = false;
    bool bldOpen = false;
    bool dbgOpen = true;
    bool pmnOpen = false;

    void drawChunkGround(ChunkRepresentation &chunkRepresentation, int level);
public:
    Scene(scenename sceneName, Core *core, Controller *controller, Simulation *simulation, Display *display, Console *console);

    FieldCursor *getFieldCursor();
    agui::Hotbar *getHotbar();
    agui::InventoryDisplay *getInventoryDisplay();
    CraftingDisplay *getCraftingDisplay();

    friend void draw(ALLEGRO_EVENT *ae, void *scene);
    friend void handleAction(ALLEGRO_EVENT *ae, void *scene);
};

void draw(ALLEGRO_EVENT *ae, void *scene);
void handleAction(ALLEGRO_EVENT *ae, void *scene);

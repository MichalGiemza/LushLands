#pragma once
#include <vector>
#include "Controller.h"
#include "Simulation.h"
#include "GraphicsManager.h"


class EventHandler {
    /**
    * Class responsible for handling player's actions that has been translated from user input.
    * Most actions can be handled inside of entity or scene components - this class handles cases where are needed:
    *  - Interactions between disconnected components.
    *  - Interactions involving multiple events at once.
    */
    Controller *c;
    Simulation *s;
    GraphicsManager *g;
    InputEvents *inputEvents;
    ALLEGRO_EVENT_SOURCE *aes;
    Focus *focus;
    ActionMap *actionMap;
    World *world;
    Player *player;
    FieldCursor *fieldCursor;
    InventoryDisplay *invDispl;
    Hotbar *hotbar;
    ItemFactory *itemFactory;

    bool pN = false, pS = false, pE = false, pW = false;
private:
    std::vector<Chunk *> getChunks();
    Chunk *getChunk(ChunkPosition &chunkPosition);
    Chunk *getChunk(Position &position);
public:
    EventHandler(Controller *controller, Simulation *simulation, GraphicsManager *graphicsManager);
    // Input to Action translation
    friend void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj);
    friend void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj);
    friend void handleMouseClick(ALLEGRO_EVENT *ae, void *obj);
    friend void handlePlayerMovementInput(ALLEGRO_EVENT *ae, void *obj);
    // Action handling
    friend void handleMobMovementAttempt(ALLEGRO_EVENT *ae, void *obj);
    friend void handleItemCollection(ALLEGRO_EVENT *ae, void *obj);
    friend void handleItemDrop(ALLEGRO_EVENT *ae, void *obj);
    friend void handleItemGenerate(ALLEGRO_EVENT *ae, void *obj);
    friend void handleEntityDestroy(ALLEGRO_EVENT *ae, void *obj);
    // Player actions
    friend void handlePlayerMovementAttempt(ALLEGRO_EVENT *ae, void *obj);
    friend void handlePlayerThrowItem(ALLEGRO_EVENT *ae, void *obj);
    friend void handlePlayerContextUse(ALLEGRO_EVENT *ae, void *obj);
};

void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj);
void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj);
void handleMouseClick(ALLEGRO_EVENT *ae, void *obj);
void handlePlayerMovementInput(ALLEGRO_EVENT *ae, void *obj);

void handleMobMovementAttempt(ALLEGRO_EVENT *ae, void *obj);
void handleItemCollection(ALLEGRO_EVENT *ae, void *obj);
void handleItemDrop(ALLEGRO_EVENT *ae, void *obj);
void handleItemGenerate(ALLEGRO_EVENT *ae, void *obj);
void handleEntityDestroy(ALLEGRO_EVENT *ae, void *obj);

void handlePlayerMovementAttempt(ALLEGRO_EVENT *ae, void *obj);
void handlePlayerThrowItem(ALLEGRO_EVENT *ae, void *obj);
void handlePlayerContextUse(ALLEGRO_EVENT *ae, void *obj);

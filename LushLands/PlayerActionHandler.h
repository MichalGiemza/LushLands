#pragma once
#include "InputEvents.h"
#include "World.h"
#include "Player.h"
#include "FieldCursor.h"
#include "InventoryDisplay.h"
#include "Hotbar.h"


class PlayerActionHandler {
    /** 
    * Class responsible for handling player's actions that has been translated from user input.
    * Most actions can be handled inside of entity or scene components - this class handles cases where are needed:
    *  - Interactions between disconnected components.
    *  - Interactions involving multiple events at once.
    */
    InputEvents *inputEvents;
    World *world;
    Player *player;
    FieldCursor *fieldCursor;
    InventoryDisplay *invDispl;
    Hotbar *hotbar;

    bool pN = false, pS = false, pE = false, pW = false;
private:
public:
    PlayerActionHandler(InputEvents *inputEvents, World *world, Player *player, FieldCursor *fieldCursor, InventoryDisplay *invDispl, Hotbar *hotbar);
    friend void handlePlayerMovementAttempt(ALLEGRO_EVENT *ae, void *obj);
    friend void handlePlayerMovement(ALLEGRO_EVENT *ae, void *obj);
    friend void handlePlayerThrowItem(ALLEGRO_EVENT *ae, void *obj);
    friend void handlePlayerContextUse(ALLEGRO_EVENT *ae, void *obj);
};

void handlePlayerMovementAttempt(ALLEGRO_EVENT *ae, void *obj);
void handlePlayerMovement(ALLEGRO_EVENT *ae, void *obj);
void handlePlayerThrowItem(ALLEGRO_EVENT *ae, void *obj);
void handlePlayerContextUse(ALLEGRO_EVENT *ae, void *obj);

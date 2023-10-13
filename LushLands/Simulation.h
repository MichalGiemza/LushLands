#pragma once
#include "stdafx.h"
#include "World.h"
#include "EntityFactory.h"
#include "ItemFactory.h"
#include "InputEvents.h"
#include "Controller.h"
#include "Player.h"
#include "CraftingManager.h"


class Simulation {
    World *world;
    Position *loadPosition; // TODO: Move to camera (?) Maybe leave as free-camera?
    ItemFactory *itemFactory;
    EntityFactory *entityFactory;
    CraftingManager *craftingManager;
    miliseconds lastUpdated = 0;
    Player *player;
    Focus *focus;
public:
    Simulation(Controller *controller);
    World *getWorld();
    void keepPositionLoaded(Position position);
    Position *getWorldLoadingPosition();
    void addPlayer(InputEvents *inputEvents);
    Player *getPlayer();
    ItemFactory *getItemFactory();
    CraftingManager *getCraftingManager();
};


#pragma once
#include "World.h"
#include "ConstantSets.h"
#include "EntityFactory.h"
#include "ItemFactory.h"
#include "InputEvents.h"
#include "Controller.h"
#include "Player.h"
#include <cmath>


class Simulation {
    World *world;
    Position *loadPosition; // TODO: Move to camera (?) Maybe leave as free-camera?
    EntityFactory *entityFactory;
    ItemFactory *itemFactory;
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
};


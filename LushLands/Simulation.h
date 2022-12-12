#pragma once
#include "World.h"
#include "ConstantSets.h"
#include "EntityFactory.h"
#include "InputEvents.h"
#include "Controller_.h"

class Simulation {
    World *world;
    Position *loadPosition; // TODO: Move to camera (?) Maybe leave as free-camera?
    EntityFactory *entityFactory;
public:
    Simulation(Controller_ *controller);
    World *getWorld();
    void keepPositionLoaded(Position position);
    Position *getWorldLoadingPosition();
};


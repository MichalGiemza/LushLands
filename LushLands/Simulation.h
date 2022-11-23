#pragma once
#include "World.h"
#include "ConstantSets.h"

class Simulation {
    static World *world;
    static Position *loadPosition; // TODO: Move to camera
public:
    static void init();
    static void keepPositionLoaded(Position position);
};


#include "World.h"

World::World(worldtype worldType, seed seed_) {
    this->seed_ = seed_;
    this->worldType = worldType;
}

int World::getSeed() {
    return seed_;
}

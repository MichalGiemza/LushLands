#include "World.h"

World::World(worldtype worldType, seed seed_) {
    this->seed_ = seed_;
    this->worldType = worldType;

    if (worldType == FLATLAND) { // TODO
        this->worldPlanner = new FlatlandWorldPlanner(seed_);
    } else {
        throw not_implemented_error();
    }
    
    this->chunkSystem = new ChunkSystem(worldPlanner);

    Logger::log("Created World [%s]", worldType);
}

int World::getSeed() {
    return seed_;
}

int World::getSeaLevel() {
    return worldPlanner->getSeaLevel();
}

ChunkLoadManager *World::getChunkLoadManager() {
    return chunkSystem->getChunkLoadManager();
}

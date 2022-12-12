#include "World.h"

World::World(worldtype worldType, seed seed_, EntityFactory *entityFactory, EventHandler *eventHandler) {
    this->seed_ = seed_;
    this->worldType = worldType;
    this->entityFactory = entityFactory;

    if (worldType == FLATLAND) { // TODO: Coœ lepszego ni¿ ify? Mo¿e jakaœ mapa w czymœ zewnêtrznym
        this->worldPlanner = new FlatlandWorldPlanner(seed_);
    } else {
        throw not_implemented_error();
    }
    
    this->chunkSystem = new ChunkSystem(worldPlanner, entityFactory);
    this->worldEvents = new WorldEvents(eventHandler);

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

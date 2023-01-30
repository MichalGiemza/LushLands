#include "World.h"

World::World(worldtype worldType, seed seed_, EntityFactory *entityFactory, EventHandler *eventHandler) {
    this->seed_ = seed_;
    this->worldType = worldType;
    this->entityFactory = entityFactory;

    if (worldType == FLATLAND) { // TODO: Coœ lepszego ni¿ ify? Mo¿e jakaœ mapa w czymœ zewnêtrznym
        this->worldPlanner = new FlatlandWorldPlanner(seed_);
    } else {
        throw new std::logic_error(not_implemented);
    }
    
    this->time = new Time();
    this->chunkSystem = new ChunkSystem(worldPlanner, entityFactory);
    this->worldEvents = new WorldEvents(eventHandler);
    eventHandler->registerWorldTime(time);

    Logger::log(ll::DEBUG_WORLD, "Created World [%s]", worldType);
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

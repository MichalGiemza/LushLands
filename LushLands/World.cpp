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
    this->lastTimeUpdated = 0;

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

void World::update() {
    // Game time elapsed
    ChunkPositionsSet *activeChunks = getChunkLoadManager()->getLoadedChunkList();
    miliseconds timeNow = time->getAsMiliseconds();
    miliseconds dt = std::min((int)(timeNow - lastTimeUpdated), maxMilisecondsPerTick);
    lastTimeUpdated = timeNow;
    // Chunks
    for (int i = 0; i < activeChunks->n; i++) {
        ChunkPosition cPos = activeChunks->chunkPositions[i];
        ChunkEvents *ce = chunkSystem->getChunk(cPos)->getChunkEvents();
        ce->update(dt);
    }
    // World
    worldEvents->update(dt);
}

Time *World::getWorldTime() {
    return time;
}

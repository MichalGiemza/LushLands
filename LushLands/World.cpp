#include "World.h"

World::World(worldtype worldType, int seed_, EntityFactory *entityFactory, ItemFactory *itemFactory, EventHandler *eventHandler) {
    this->seed_ = seed_;
    srand(seed_);
    this->worldType = worldType;
    this->entityFactory = entityFactory;
    this->itemFactory = itemFactory;

    this->worldPlanner = 0;
    if (worldType == FLATLAND) // TODO: Coœ lepszego ni¿ ify? Mo¿e jakaœ mapa w czymœ zewnêtrznym
        this->worldPlanner = new FlatlandWorldPlanner(seed_);
    if (worldType == CHICKEN_BOX) // TODO: Coœ lepszego ni¿ ify? Mo¿e jakaœ mapa w czymœ zewnêtrznym
        this->worldPlanner = new ChickenBoxWorldPlanner(seed_);
    if (this->worldPlanner == 0)
        throw new std::logic_error(not_implemented);
    
    this->time = new Time();
    this->chunkSystem = new ChunkSystem(worldPlanner, entityFactory, itemFactory);
    this->worldEvents = new WorldEvents(eventHandler);
    this->lastTimeUpdated = 0;

    Logger::log(lg::DEBUG_WORLD, "Created World [%s]", worldType);
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

void World::placePlayer(Player *player) {
    Humanoid *h = (Humanoid *)player->getEntity();
    Position *p = h->getPosition();
    Chunk *c = chunkSystem->getChunk(p->getChunkPosition());
    c->placeHumanoid(h);
    worldEvents->registerPlayer(player);
}

void World::update(miliseconds dt) {
    // Game time elapsed
    ChunkPositionsSet *activeChunks = getChunkLoadManager()->getLoadedChunkList();
    *time += dt;
    miliseconds timeNow = time->getAsMiliseconds();
    lastTimeUpdated = timeNow;
    // Chunks
    for (int i = 0; i < activeChunks->n; i++) {
        ChunkPosition cPos = activeChunks->chunkPositions[i];
        Chunk *c = chunkSystem->getChunk(cPos);
        if (not c)
            continue;
        ChunkEvents *ce = c->getChunkEvents();
        ce->update(timeNow, dt);
    }
    // World
    worldEvents->update(timeNow, dt);
}

Time *World::getWorldTime() {
    return time;
}

#include "stdafx.h"
#include "World.h"

World::World(worldtype worldType, int seed_, EntityFactory *entityFactory, ItemFactory *itemFactory, InputEvents *inputEvents) :
    seed_(seed_), worldType(worldType), entityFactory(entityFactory), itemFactory(itemFactory), worldPlanner(0), inputEvents(inputEvents) {
    srand(seed_);
    
    if (worldType == FLATLAND) // TODO: Coœ lepszego ni¿ ify? Mo¿e jakaœ mapa w czymœ zewnêtrznym
        this->worldPlanner = new FlatlandWorldPlanner(seed_);
    if (worldType == CHICKEN_BOX) // TODO: Coœ lepszego ni¿ ify? Mo¿e jakaœ mapa w czymœ zewnêtrznym
        this->worldPlanner = new ChickenBoxWorldPlanner(seed_);
    if (this->worldPlanner == 0)
        throw new std::logic_error(not_implemented);
    
    this->time = new Time();
    this->sessionActiveSince = time->getAsMiliseconds();
    this->lastTimeUpdated = time->getAsMiliseconds();
    this->chunkSystem = new ChunkSystem(worldPlanner, entityFactory, itemFactory, inputEvents);

    inputEvents->subscribeTimerFPS(0, updateTime, this);

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

std::vector<Entity *> World::getByPosition(Position *position) {
    auto cP = position->getChunkPosition();
    auto chunk = getChunkLoadManager()->getChunk(cP);
    if (chunk)
        return chunk->getByPosition(position);
    return std::vector<Entity *>();
}

void World::placePlayer(Player *player) {
    Humanoid *h = (Humanoid *)player->getEntity();
    Position *p = (Position *)h->getPosition();
    ChunkPosition cp = p->getChunkPosition();
    Chunk *c = chunkSystem->getChunk(cp);
    c->placeHumanoid(h);
}

void World::placeItem(Item *item) {
    ChunkPosition cp = item->getPosition()->getChunkPosition();
    Chunk *c = chunkSystem->getChunk(cp);
    c->placeItem(item);
}

Time *World::getWorldTime() {
    return time;
}

void updateTime(ALLEGRO_EVENT *ae, void *obj) {
    World *w = (World *)obj;
    w->lastTimeUpdated = w->time->getAsMiliseconds();
    w->time->setAsMiliseconds(w->sessionActiveSince + ae->timer.count);
}

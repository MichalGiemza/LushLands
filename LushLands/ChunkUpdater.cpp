#include "stdafx.h"
#include "ChunkUpdater.h"


ChunkUpdater::ChunkUpdater(InputEvents *inputEvents) {
    inputEvents->subscribeTimerFPS(1, updateChunk, this);
    lastUpdated = al_get_time() * 1000;
}

void ChunkUpdater::registerEntity(Entity *en) {
    EntityUpdater *eu = (EntityUpdater *)en->getEntityUpdater();
    if (en->getUpdateType() == random_tick)
        randomTickEntities.push_back(en);
    if (en->getUpdateType() == constant_update)
        toUpdateEntities.push_back(en);
}

void ChunkUpdater::unregisterEntity(Entity *en) {
    EntityUpdater *eu = (EntityUpdater *)en->getEntityUpdater();
    if (en->getUpdateType() == random_tick) {
        auto &v = randomTickEntities;
        v.erase(std::remove(v.begin(), v.end(), en), v.end());
    }
    if (en->getUpdateType() == constant_update) {
        auto &v = toUpdateEntities;
        v.erase(std::remove(v.begin(), v.end(), en), v.end());
    }
}

void updateChunk(ALLEGRO_EVENT *ae, void *obj) {
    auto *ce = (ChunkUpdater *)obj;
    miliseconds timeNow = al_get_time() * 1000;
    miliseconds dt = timeNow - ce->lastUpdated;
    dt = std::min(dt, (miliseconds)100);
    // Consistent Update Entities
    for (auto &en : ce->toUpdateEntities) {
        EntityUpdater *eu = (EntityUpdater *)en->getEntityUpdater();
        eu->updateEntity(timeNow, dt);
    }
    // Random Update Entities
    // TODO: Random Update, oprzeæ losowanie o szansê? - czy zostanie wykonany update
    ce->lastUpdated = timeNow;
}

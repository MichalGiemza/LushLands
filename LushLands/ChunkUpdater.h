#pragma once
#include "stdafx.h"
#include "EntityUpdater.h"
#include "Entity.h"


class ChunkUpdater {
    /** 
    * Management tool for registering and updating world's Entities.
    */
    std::vector<Entity *> randomTickEntities;
    std::vector<Entity *> toUpdateEntities;
    miliseconds lastUpdated;
public:
    ChunkUpdater(InputEvents *inputEvents);
    void registerEntity(Entity *entity);
    void unregisterEntity(Entity *entity);
    friend void updateChunk(ALLEGRO_EVENT *ae, void *obj);
};

void updateChunk(ALLEGRO_EVENT *ae, void *obj);

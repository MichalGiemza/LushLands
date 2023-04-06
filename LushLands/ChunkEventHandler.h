#pragma once
#include "DynamicCollider.h"
#include "CollisionManager.h"
#include "EventFactory.h"
#include "Item.h"
#include "Entity.h"
#include "Humanoid.h"
#include "ChunkElements.h"
#include <vector>


class ChunkEventHandler {
    /**
    * Class responsible for handling Chunk Events.
    */
    CollisionManager *collisionManager;
    ChunkElements *ce;
public:
    ChunkEventHandler(CollisionManager *collisionManager, ChunkElements *ce);
    void handleMobMovementAttempt(ALLEGRO_EVENT *currentEvent);
    void handleItemCollection();
    void handleItemDrop(ALLEGRO_EVENT *currentEvent);
};


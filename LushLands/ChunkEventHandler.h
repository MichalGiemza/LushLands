#pragma once
#include "DynamicCollider.h"
#include "CollisionManager.h"

class ChunkEventHandler {
    /**
    * Class responsible for handling Chunk Events.
    */
    CollisionManager *collisionManager;
public:
    ChunkEventHandler(CollisionManager *collisionManager);
    void handleMobMovementAttempt(ALLEGRO_EVENT *currentEvent);
};


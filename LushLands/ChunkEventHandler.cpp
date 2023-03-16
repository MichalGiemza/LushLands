#include "ChunkEventHandler.h"


ChunkEventHandler::ChunkEventHandler(CollisionManager *collisionManager_) {
    collisionManager = collisionManager_;
}

void ChunkEventHandler::handleMobMovementAttempt(ALLEGRO_EVENT *currentEvent) {
    auto dynCollider = (DynamicCollider *)currentEvent->user.data1;
    auto newPos = (Position *)currentEvent->user.data2;
    auto collidersONP = collisionManager->getCollidersObstructuringNewPosition(dynCollider, newPos);
    if (not collidersONP->empty())
        return;
        //dynCollider->updateNewPositionWithColliders(*newPos, *collidersONP);
    dynCollider->setPosition(*newPos);
}


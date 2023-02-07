#include "ChunkEventHandler.h"

void handleMobMovementAttempt(ALLEGRO_EVENT *currentEvent, CollisionManager *collisionManager) {
    auto dynCollider = (DynamicCollider *)currentEvent->user.data1;
    auto newPos = (Position *)currentEvent->user.data1;
    auto collidersONP = collisionManager->getCollidersObstructuringNewPosition(dynCollider, newPos);
    if (not collidersONP->empty())
        dynCollider->updateNewPositionWithColliders(*newPos, *collidersONP);
    dynCollider->setPosition(*newPos);
}

ChunkEventHandler::ChunkEventHandler(CollisionManager *collisionManager_) {
    collisionManager = collisionManager_;
}

void ChunkEventHandler::handleMobMovementAttempt(ALLEGRO_EVENT *currentEvent) {
    auto dynCollider = (DynamicCollider *)currentEvent->user.data1;
    auto newPos = (Position *)currentEvent->user.data1;
    auto collidersONP = collisionManager->getCollidersObstructuringNewPosition(dynCollider, newPos);
    if (not collidersONP->empty())
        dynCollider->updateNewPositionWithColliders(*newPos, *collidersONP);
    dynCollider->setPosition(*newPos);
}

